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

const auto dir = vector< pair<int, int> > { {1, 0},     // D
                                            {0, 1},     // R
                                            {-1, 0},    // U
                                            {0, -1} };      // L
const int MAXN = 5000 + 50;
const int N = 30000000 + 7;
int n, m, res;
pii st, ed;
char graph[MAXN][MAXN];
int dis[MAXN][MAXN];
bool vis[MAXN][MAXN];
deque<pii> dq;
string str;
map<char, int> mp;

void bfs(){
    dq.push_front(st);
    mem(dis, -1);
    dis[st.f][st.s] = 0;
    
    while( !dq.empty() ){
        pii cnt = dq.front();
        dq.pop_front();

        if( cnt == ed ) return;
        if( vis[cnt.f][cnt.s] ) continue;
        
        vis[cnt.f][cnt.s] = true;
        int d = dis[cnt.f][cnt.s];
 
        for( int t = 0 ; t < 4 ; t++ ){
            pii nxt = {cnt.f + dir[t].f, cnt.s + dir[t].s};

            if( nxt.s > m || nxt.s <= 0 || nxt.f > n || nxt.f <= 0 ) continue;
            if( graph[nxt.f][nxt.s] == '#' ) continue;

            int nxtd = t != mp[graph[cnt.f][cnt.s]] ? d+1 : d;
            if( dis[nxt.f][nxt.s] == -1 || nxtd < dis[nxt.f][nxt.s] ){
                dis[nxt.f][nxt.s] = nxtd;
                if( t != mp[graph[cnt.f][cnt.s]]) dq.push_back(nxt);
                else dq.push_front(nxt);
            }
        }
    }
}

signed main(){
    opt;
    cin >> n >> m;
    for( int i = 1 ; i <= n ; i++ ){
        cin >> str;
        for( int j = 0 ; j < str.size() ; j++ ) graph[i][j+1] = str[j];
    }
    cin >> st.f >> st.s;
    cin >> ed.f >> ed.s;

    mp['U'] = 2;
    mp['D'] = 0;
    mp['L'] = 3;
    mp['R'] = 1;

    bfs();

    cout << dis[ed.f][ed.s] << "\n";
}

/***** DFS(Failed) *****/
// void dfs( int i, int j, int num ){
//     if( i == ed.f && j == ed.s ){
//         res = min(res, num);
//         return;
//     }

//     if( visited[i][j] == true ) return;
//     if( graph[i][j] == '#' ) return;

//     for( int t = 0 ; t < 4 ; t++ ){
//         int ni = i + dir[t].f;
//         int nj = j + dir[t].s;

//         flag = true;
//         if( graph[i][j] == 'U' && t != 2 ) flag = false;
//         else if( graph[i][j] == 'D' && t != 0 ) flag = false;
//         else if( graph[i][j] == 'L' && t != 3 ) flag = false;
//         else if( graph[i][j] == 'R' && t != 1 ) flag = false;

//         if( nj > m || nj <= 0 || ni > n || ni <= 0 ) continue;

//         visited[i][j] = true;
//         if( flag == false ) dfs(ni, nj, num+1);
//         else dfs(ni, nj, num);
//         visited[i][j] = false;
//     }
// }

/***** BFS(Failed) *****/
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