/* Question : AtCoder Beginner Contest 320 - D - Relative Position  */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pirq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define f first
#define s second
#define int long long

const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
vector<vector<pair<int , pii>>> dir;
int n, m, a, b, c, d;
bool used[MAXN];
vector<pii> pos;
queue<int> todo;

signed main(){
    opt;
    cin >> n >> m;
    dir.resize(n+5);
    pos.resize(n+5);
    for( int i = 0 ; i < m ; i++ ){
        cin >> a >> b >> c >> d;
        dir[a].pb( { b, {c, d} } );
        dir[b].pb( { a, {-1 * c, -1 * d} } );
    }

    for( int i = 0 ; i < pos.size() ; i++ ) pos[i].f = 1e9, pos[i].s = 1e9;
    for( int i = 0 ; i < dir.size() ; i++ ) unique(dir[i].begin(), dir[i].end());
    mem(used, false);

    todo.push(1);
    pos[1] = {0, 0};
    while( !todo.empty() ){
        int cnt = todo.front();
        used[cnt] = true;
        todo.pop();

        for( auto i : dir[cnt] ){
            int nxt = i.f;
            int x = pos[cnt].f, y = pos[cnt].s;
            int dx = i.s.f, dy = i.s.s;

            pos[nxt] = {x + dx, y + dy};

            if( used[nxt] == false ){
                todo.push(nxt);
                used[nxt] = true;
            }
        }
    }

    for( int i = 1 ; i <= n ; i++ ){
        if( pos[i].f != 1e9 && pos[i].s != 1e9 ) cout << pos[i].f << " " << pos[i].s << "\n";
        else cout << "undecidable\n";
    }
}