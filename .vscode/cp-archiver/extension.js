const vscode = require('vscode');
const fs = require('fs');
const path = require('path');
const crypto = require('crypto');

// Competitive Companion judge name -> folder in this repo
const JUDGE_FOLDERS = {
    'Codeforces': 'Code Force',
    'AtCoder': 'AtCoder',
    'CSES': 'CSES',
    'Luogu': 'Luogu',
    'Kattis': 'Kattis',
    'LeetCode': 'Leetcode',
    'UVa Online Judge': 'UVa',
    'Virtual Judge': 'VJudge',
    'ZeroJudge': 'Zero Judge',
};

const sleep = ms => new Promise(r => setTimeout(r, ms));
const samePath = (a, b) => path.resolve(a).toLowerCase() === path.resolve(b).toLowerCase();
const clean = s => s.replace(/[<>:"/\\|?*\x00-\x1f]/g, '').replace(/\s+/g, ' ').trim().replace(/[. ]+$/, '');

// Decide folder, file name and header comment from the problem URL / group
function locate(p) {
    const url = new URL(p.url);
    const sep = p.group.indexOf(' - ');
    const judge = sep < 0 ? p.group : p.group.slice(0, sep);
    const contest = sep < 0 ? '' : p.group.slice(sep + 3);
    const name = p.name.trim();

    if (url.hostname.endsWith('atcoder.jp')) {
        const id = (url.pathname.match(/\/contests\/([^/]+)/) || [])[1] || '';
        const letter = (url.pathname.match(/\/tasks\/\w+_(\w+)$/) || [])[1];
        const task = / - /.test(name) ? name.replace(/^(\w+) - /, '$1. ')
            : letter ? `${letter.toUpperCase()}. ${name}` : name;
        const m = id.match(/^(abc|arc|agc)(\d+)$/);
        if (m) {
            const folder = `${{ abc: 'Beginner', arc: 'Regular', agc: 'Grand' }[m[1]]} Contest ${m[2]}`;
            return { dir: ['AtCoder', folder], file: task, header: `AtCoder ${folder} - ${task}`, abc: m[1] === 'abc' };
        }
        const folder = id === 'dp' ? 'Educational DP Contest' : contest.replace(/^AtCoder /, '');
        return { dir: ['AtCoder', folder], file: task, header: `${contest} - ${task}` };
    }

    if (url.hostname.endsWith('codeforces.com')) {
        const ps = url.pathname.match(/\/problemset\/problem\/(\d+)\/(\w+)/);
        if (ps) {
            const file = `${ps[1]}${ps[2]}. ${name.replace(/^\w+\.\s*/, '')}`;
            return { dir: ['Code Force'], file, header: `Codeforces ${file}` };
        }
        return { dir: ['Code Force', contest], file: name, header: `${contest} - ${name}` };
    }

    if (url.hostname === 'cses.fi') {
        const id = (url.pathname.match(/\/task\/(\d+)/) || [])[1];
        const file = id ? `${id}. ${name}` : name;
        return { dir: ['CSES'], file, header: `CSES ${file}` };
    }

    return { dir: [JUDGE_FOLDERS[judge] || judge], file: name, header: `${judge} ${name}` };
}

function parseJsonc(text) {
    const trailing = /\s*[}\]]/y;
    let out = '';
    for (let i = 0; i < text.length; i++) {
        const c = text[i];
        if (c === '"') {
            let j = i + 1;
            while (j < text.length && text[j] !== '"') j += text[j] === '\\' ? 2 : 1;
            out += text.slice(i, j + 1);
            i = j;
        } else if (c === '/' && text[i + 1] === '/') {
            while (i + 1 < text.length && text[i + 1] !== '\n') i++;
        } else if (c === '/' && text[i + 1] === '*') {
            const j = text.indexOf('*/', i + 2);
            i = j < 0 ? text.length : j + 1;
        } else if (c === ',') {
            trailing.lastIndex = i + 1;
            if (!trailing.test(text)) out += c;
        } else {
            out += c;
        }
    }
    return JSON.parse(out);
}

function template(loc) {
    const cfg = vscode.workspace.getConfiguration('cpArchiver');
    const dir = path.join(process.env.APPDATA || '', 'Code', 'User', 'snippets');
    const file = loc.abc
        ? cfg.get('abcSnippet') || path.join(dir, 'abc-atcoder-template.code-snippets')
        : cfg.get('defaultSnippet') || path.join(dir, 'cp-template-c++.code-snippets');

    const snippet = Object.values(parseJsonc(fs.readFileSync(file, 'utf8')))[0];
    const body = Array.isArray(snippet.body) ? snippet.body.join('\n') : snippet.body;
    const lines = body
        .replace(/\$\{\d+:([^}]*)\}/g, '$1')
        .replace(/\$\{?\d+\}?/g, '')
        .replace(/\\([$}\\])/g, '$1')
        .split(/\r?\n/);
    if (/^\/\*\s*Question\s*:.*\*\/\s*$/.test(lines[0])) lines[0] = `/* Question : ${loc.header} */`;
    return lines.join('\r\n');
}

// Same location rule as cph's getProbSaveLocation
function probPath(src) {
    const loc = vscode.workspace.getConfiguration('cph').get('general.saveLocation');
    const file = `.${path.basename(src)}_${crypto.createHash('md5').update(src).digest('hex')}.prob`;
    return loc ? path.join(loc, file) : path.join(path.dirname(src), '.cph', file);
}

const tabsOf = file => vscode.window.tabGroups.all
    .flatMap(g => g.tabs)
    .filter(t => t.input instanceof vscode.TabInputText && samePath(t.input.uri.fsPath, file));

// Move a problem cph just received (an empty <root>/<name>.cpp) into its contest folder
async function archive(file, root) {
    let prob;
    try { prob = JSON.parse(fs.readFileSync(file, 'utf8')); } catch { return; }
    const src = prob.srcPath;
    if (!/^https?:/.test(prob.url || '') || !src || !samePath(path.dirname(src), root)) return;
    try { if (fs.statSync(src).size !== 0) return; } catch { return; }

    const loc = locate(prob);
    const dir = path.join(root, ...loc.dir.map(clean).filter(Boolean));
    const target = vscode.Uri.file(path.join(dir, clean(loc.file) + '.cpp')).fsPath;

    fs.mkdirSync(dir, { recursive: true });
    const fresh = !fs.existsSync(target);
    if (fresh) fs.writeFileSync(target, template(loc));

    const probFile = probPath(target);
    fs.mkdirSync(path.dirname(probFile), { recursive: true });
    fs.writeFileSync(probFile, JSON.stringify({ ...prob, srcPath: target }));

    // cph opens the root file right after saving the .prob; wait for it, then drop it
    for (let t = 0; t < 15 && tabsOf(src).length === 0; t++) await sleep(200);
    await vscode.window.tabGroups.close(tabsOf(src));
    fs.rmSync(file, { force: true });
    fs.rmSync(src, { force: true });

    const editor = await vscode.window.showTextDocument(vscode.Uri.file(target), { preview: false });
    if (fresh) {
        const line = editor.document.getText().split(/\r?\n/).findIndex(l => l.startsWith('inline void solve()'));
        if (line >= 0) {
            const pos = new vscode.Position(line + 1, 4);
            editor.selection = new vscode.Selection(pos, pos);
            editor.revealRange(new vscode.Range(pos, pos), vscode.TextEditorRevealType.InCenter);
        }
    }
    vscode.window.setStatusBarMessage(`CP Archiver: ${path.relative(root, target)}`, 5000);
}

function activate(context) {
    const cfg = vscode.workspace.getConfiguration('cpArchiver');
    if (!cfg.get('enabled') || !vscode.workspace.workspaceFolders) return;

    const root = vscode.workspace.workspaceFolders[0].uri.fsPath;
    const dir = vscode.workspace.getConfiguration('cph').get('general.saveLocation') || path.join(root, '.cph');
    fs.mkdirSync(dir, { recursive: true });

    let queue = Promise.resolve();
    const enqueue = name => {
        if (!name || !name.endsWith('.prob')) return;
        queue = queue
            .then(() => archive(path.join(dir, name), root))
            .catch(e => vscode.window.showErrorMessage(`CP Archiver: ${e.message}`));
    };

    const watcher = fs.watch(dir, (_, name) => enqueue(name));
    context.subscriptions.push({ dispose: () => watcher.close() });
    fs.readdirSync(dir).forEach(enqueue);  // leftovers from before startup
}

module.exports = { activate, deactivate() { } };
