// 在 CPH 的 Competitive Companion 處理流程中注入 hook：
//   1. 用 .vscode/cph/route.js 決定存檔路徑（自動建資料夾）
//   2. 新檔自動帶入 route.js 指定的 snippet
// 用法：node .vscode/cph/patch.js   （CPH 更新或 patch.js 修改後重跑一次，然後 Reload Window）
const fs = require("fs");
const path = require("path");
const os = require("os");

const MARK = "/*cph-route-patch*/";
const extRoot = path.join(os.homedir(), ".vscode", "extensions");

const ROUTE = 'd.default.join(r,".vscode","cph","route.js")';

// 保存改名前的原始題名（CPH 會把 e.name 改掉，例如 Kattis 會換成題目 id）
const RAW_FROM = 'try{a=new URL(e.url)}catch(e){return globalThis.logger.error(e),null}';
const RAW_TO = MARK + 'var __cphRaw=e.name;' + RAW_FROM;

const PATH_FROM = "v=d.default.join(r,s);";
const PATH_TO = MARK + `v=(()=>{try{
const h=${ROUTE};
if(!f.existsSync(h))return d.default.join(r,s);
delete require.cache[require.resolve(h)];
const rel=require(h)(Object.assign({},e,{name:__cphRaw}),d.default.extname(s).slice(1));
if(!rel)return d.default.join(r,s);
const p=d.default.join(r,rel);
f.mkdirSync(d.default.dirname(p),{recursive:!0});
return p}catch(x){globalThis.logger.error("cph-route",x);return d.default.join(r,s)}})();
var __cphNew=!f.existsSync(v);`.replace(/\n/g, "");

const SNIP_FROM = 'if(-1!==w){const e=m.positionAt(w)';
const SNIP_TO = MARK + `if(__cphNew&&""===m.getText())try{
const h=${ROUTE},R=f.existsSync(h)?require(h):null;
const sn=R&&R.snippet&&R.snippet(Object.assign({},e,{name:__cphRaw}),d.default.relative(r,v).split(d.default.sep).join("/"));
sn&&(await b.insertSnippet(new l.SnippetString(sn)),await m.save())
}catch(x){globalThis.logger.error("cph-snippet",x)}` .replace(/\n/g, "") + SNIP_FROM;

const dirs = fs.readdirSync(extRoot).filter((d) => d.startsWith("divyanshuagrawal.competitive-programming-helper-"));
if (dirs.length === 0) {
    console.error("找不到 CPH extension");
    process.exit(1);
}

for (const d of dirs) {
    const file = path.join(extRoot, d, "dist", "extension.js");
    const orig = file + ".orig";
    // 一律從原始檔重新 patch，patch.js 更新後重跑即可套用新版
    let src = fs.readFileSync(fs.existsSync(orig) ? orig : file, "utf8");
    if (src.includes(MARK)) {
        console.error(`[fail] ${d}：原始檔已含 patch 且沒有 .orig 備份`);
        process.exitCode = 1;
        continue;
    }
    const missing = [RAW_FROM, PATH_FROM, SNIP_FROM].filter((a) => src.split(a).length !== 2);
    if (missing.length) {
        console.error(`[fail] ${d}：找不到注入點（CPH 版本變動，需要更新 patch.js）`);
        process.exitCode = 1;
        continue;
    }
    if (!fs.existsSync(orig)) fs.copyFileSync(file, orig);
    src = src.replace(RAW_FROM, RAW_TO).replace(PATH_FROM, PATH_TO).replace(SNIP_FROM, SNIP_TO);
    fs.writeFileSync(file, src);
    console.log(`[done] ${d} 已 patch，請執行 Developer: Reload Window`);
}
