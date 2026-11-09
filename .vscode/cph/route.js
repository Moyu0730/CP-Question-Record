// CPH + Competitive Companion 歸檔規則
// patch.js 注入到 CPH 的 hook 每次收到題目都會重新載入這個檔案，改完存檔即生效（不用重開 VS Code）
// 回傳相對於 workspace 根目錄的路徑；回傳 null 則使用 CPH 預設行為（放在根目錄）
// 資料夾不存在會自動建立

// hostname -> OJ 資料夾
const OJ = {
    "atcoder.jp": "AtCoder",
    "codeforces.com": "Code Force",
    "mirror.codeforces.com": "Code Force",
    "cses.fi": "CSES",
    "open.kattis.com": "Kattis",
    "www.luogu.com.cn": "Luogu",
    "onlinejudge.org": "UVa",
    "vjudge.net": "VJudge",
    "zerojudge.tw": "Zero Judge",
    "tioj.ck.tp.edu.tw": "TIOJ",
    "leetcode.com": "Leetcode",
};

// AtCoder 比賽代號 -> 資料夾名稱
const ATCODER_CONTEST = {
    abc: "Beginner Contest",
    arc: "Regular Contest",
    agc: "Grand Contest",
    ahc: "Heuristic Contest",
};

// Windows 不允許的字元換成全形
const clean = (s) =>
    s.replace(/[\\/:*?"<>|]/g, (c) => String.fromCharCode(c.charCodeAt(0) + 0xfee0))
     .replace(/\s+/g, " ")
     .trim()
     .replace(/[. ]+$/, "");

// "F - Title" / "F. Title" -> { index: "F", title: "Title" }
const splitIndex = (name) => {
    const m = name.match(/^(\w+)\s*(?:-|\.)\s+(.*)$/);
    return m ? { index: m[1], title: m[2] } : { index: "", title: name };
};

module.exports = (problem, ext) => {
    const url = new URL(problem.url);
    const host = url.hostname;
    const name = problem.name;
    const group = problem.group || "";

    // 沒設定的 OJ：用 group 的站名（"Site - Contest"）開新資料夾
    const oj = OJ[host] || clean(group.split(" - ")[0] || host);

    let dir = [oj];
    let file = name;

    if (host === "atcoder.jp") {
        // /contests/abc481/tasks/abc481_f -> Beginner Contest 481/F. Title
        const contest = url.pathname.match(/contests\/([^/]+)/)?.[1] || "";
        const m = contest.match(/^([a-z]+)(\d+)$/);
        if (m && ATCODER_CONTEST[m[1]]) dir.push(`${ATCODER_CONTEST[m[1]]} ${Number(m[2])}`);
        else dir.push(group.replace(/^AtCoder - /, "") || contest);
        const { index, title } = splitIndex(name);
        file = index ? `${index.toUpperCase()}. ${title}` : title;
    } else if (oj === "Code Force") {
        // /contest/1333/problem/C, /problemset/problem/1333/C, /gym/100001/problem/A -> 1333C. Title
        const m = url.pathname.match(/(?:contest|gym)\/(\d+)\/problem\/(\w+)/) ||
                  url.pathname.match(/problemset\/problem\/(\d+)\/(\w+)/);
        const { title } = splitIndex(name);
        if (m) file = `${m[1]}${m[2]}. ${title}`;
    } else if (host === "cses.fi") {
        // /problemset/task/1068 -> 1068. Title
        const id = url.pathname.match(/task\/(\d+)/)?.[1];
        if (id) file = `${id}. ${name}`;
    } else if (oj === "Luogu") {
        // "P3374 【模板】树状数组 1" -> P3374.【模板】树状数组 1
        const m = name.match(/^([A-Z]+\d+\w*)\s+(.*)$/);
        if (m) file = `${m[1]}.${m[2]}`;
    } else if (oj === "UVa") {
        // "10165 - Stone Game" -> 10165. Stone Game
        const m = name.match(/^(\d+)\s*-\s*(.*)$/);
        if (m) file = `${m[1]}. ${m[2]}`;
    } else if (oj === "VJudge") {
        if (group) dir.push(group.replace(/^Virtual Judge - /, ""));
    } else if (!OJ[host] && group.includes(" - ")) {
        dir.push(group.split(" - ").slice(1).join(" - "));
    }

    return [...dir.map(clean), `${clean(file)}.${ext}`].join("/");
};

// 新檔自動帶入的 snippet（VS Code 使用者 snippet 檔，取第一個 snippet）
const SNIPPET_DIR = require("path").join(process.env.APPDATA, "Code", "User", "snippets");
const snippetFile = (relPath) =>
    /^AtCoder\/(Beginner|Regular|Grand) Contest /.test(relPath) ? "abc-atcoder-templete-c++.code-snippets" : "cp-templete-c++.code-snippets";

// 檔頭 "/* Question : OJ Number */" 的 OJ 名稱
const HEADER_OJ = {
    "Code Force": "CF",
};

// 回傳要插入的 snippet 字串；回傳 null 則不插入
module.exports.snippet = (problem, relPath) => {
    const fs = require("fs");
    const path = require("path");
    const SNIPPET_FILE = path.join(SNIPPET_DIR, snippetFile(relPath));
    if (!relPath.endsWith(".cpp") || !fs.existsSync(SNIPPET_FILE)) return null;

    const snippets = JSON.parse(fs.readFileSync(SNIPPET_FILE, "utf8"));
    const first = Object.values(snippets)[0];
    let body = Array.isArray(first.body) ? first.body.join("\n") : first.body;

    // AtCoder/Beginner Contest 481/F. Title.cpp -> AtCoder Beginner Contest 481 - F. Title
    // CSES/1068. Title.cpp -> CSES 1068. Title
    const parts = relPath.split("/");
    const file = path.basename(parts.pop(), path.extname(relPath));
    const oj = HEADER_OJ[parts[0]] || parts[0];
    const header = parts.length > 1 ? `${oj} ${parts.slice(1).join(" ")} - ${file}` : `${oj} ${file}`;

    // snippet 語法中 $ } \ 是特殊字元
    body = body.replace(/^\/\* Question : .* \*\//, `/* Question : ${header.replace(/[$}\\]/g, "\\$&")} */`);
    // 游標停在 solve() 裡
    body = body.replace("inline void solve(){\n\n}", "inline void solve(){\n    $0\n}");
    return body;
};
