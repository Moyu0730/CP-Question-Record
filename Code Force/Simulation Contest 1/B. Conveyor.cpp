/* Question : CF 【2023 MD Player Training】 Simulation Contest 1 - B. Conveyor */

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

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
                                            // D     R       U         L
const int MAXN = 5000 + 50;
const int Mod = 1e9 + 7;
int n, m, res;
char graph[MAXN][MAXN];
pii st, ed;
bool flag;
string str;
bool visited[MAXN][MAXN];
// queue< pair<pii, int> > q;
// queue< vector<vector<bool>> > used;
// vector<vector<bool>> def, v'

void dfs( int i, int j, int num ){
    if( i == ed.f && j == ed.s ){
        res = min(res, num);
        return;
    }

    if( visited[i][j] == true ) return;
    if( graph[i][j] == '#' ) return;

    for( int t = 0 ; t < 4 ; t++ ){
        int ni = i + dir[t].f;
        int nj = j + dir[t].s;

        flag = true;
        if( graph[i][j] == 'U' && t != 2 ) flag = false;
        else if( graph[i][j] == 'D' && t != 0 ) flag = false;
        else if( graph[i][j] == 'L' && t != 3 ) flag = false;
        else if( graph[i][j] == 'R' && t != 1 ) flag = false;

        if( nj > m || nj <= 0 || ni > n || ni <= 0 ) continue;

        visited[i][j] = true;
        if( flag == false ) dfs(ni, nj, num+1);
        else dfs(ni, nj, num);
        visited[i][j] = false;
    }
}

// void bfs(){
//     q.push({{st.f, st.s}, 0});
    
//     def.resize(n+5);
//     for( int i = 0 ; i <= n ; i++ ) def[i].resize(m+5);
   
//     used.push(def);
    
//     res = 1e9;
//     while( !q.empty() ){
//         int i = q.front().f.f;
//         int j = q.front().f.s;
//         int num = q.front().s;
//         vector<vector<bool>> vis = used.front();
//         q.pop(); used.pop();

//         if( vis[i][j] == true ) continue;
//         if( i == ed.f && j == ed.s ){
//             res = min(res, num);
//             continue;
//         }

//         for( int t = 0 ; t < 4 ; t++ ){
//             int ni = i + dir[t].f;
//             int nj = j + dir[t].s;

//             flag = true;
//             if( graph[i][j] == 'U' && t != 2 ) flag = false;
//             else if( graph[i][j] == 'D' && t != 0 ) flag = false;
//             else if( graph[i][j] == 'L' && t != 3 ) flag = false;
//             else if( graph[i][j] == 'R' && t != 1 ) flag = false;

//             if( nj > m || nj <= 0 || ni > n || ni <= 0 ) continue;
//             if( graph[ni][nj] == '#' ) continue;
//             if( vis[ni][nj] == true ) continue;

//             vis[i][j] = true;
//             if( flag == false ) q.push({{ni, nj}, num+1});
//             else q.push({{ni, nj}, num});
//             used.push(vis);
//         }
    
//     }
//     return;
// }

signed main(){
    // opt;
    cin >> n >> m;
    for( int i = 1 ; i <= n ; i++ ){
        cin >> str;
        for( int j = 0 ; j < str.size() ; j++ ){
            graph[i][j+1] = str[j];
        }
    }
    cin >> st.f >> st.s;
    cin >> ed.f >> ed.s;

    // bfs();
    res = 1e9;
    dfs(st.f, st.s, 0);

    if( res != 1e9) cout << res << "\n";
    else cout << "-1\n";
}