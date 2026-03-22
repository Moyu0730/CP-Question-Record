/* Question : UVa 820. Internet Bandwidth */

#include<bits/stdc++.h>
using namespace std;

/* Pragma */
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

/* Self Define */
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MEM(_A, _V) memset(_A, _V, sizeof(_A))
#define ALL(_A) _A.begin(), _A.end()
#define LB(_A, _V) lower_bound(ALL(_A), _V)
#define UB(_A, _V) upper_bound(ALL(_A), _V)
#define pii pair<int, int>
#define as assign
#define sz size()
#define cr clear()
#define rz resize
#define pb push_back
#define F first
#define S second
#define int long long
#define tpn typename

/* Self Define Template Function */
template<tpn T> void pV( vector<T> _A ){
    for( auto _I : _A ) cout << _I << " ";
    cout << "\n";
}

template<tpn A, tpn B> ostream& operator<<( ostream& _OS, pair<A, B> _P ){
    return _OS << "(" << _P.F << ", " << _P.S << ")";
}

/* Self Define Const */
const auto dir = vector<pii> { {1, 0}, {0, 1},  {-1, 0}, {0, -1},
                               {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
const int     MAXN = 1e7 + 50;
const int      Mod = 1e9 + 7;
const int      INF = 0x7FFFFFFF;
const int    LLINF = 0x7FFFFFFFFFFFFFFF;
const int MEMLLINF = 0x3F3F3F3F3F3F3F3F;

struct EDGE {
    int v, cap, rid;
};

int n, s, t, m, u, v, w, res;
vector<vector<EDGE>> edge;
vector<int> level;

inline void add_edge(){
    edge[u].pb({v, w, (int)edge[v].sz});
    edge[v].pb({u, w, (int)edge[u].sz-1});
}

inline bool bfs(){
    queue<int> q;
    q.push(s);

    level.as(n + 5, INF);
    level[s] = 0;
    while( !q.empty() ){
        int cnt = q.front();
        q.pop();

        for( auto nxt : edge[cnt] ){
            if( level[nxt.v] == INF && nxt.cap > 0 ){
                level[nxt.v] = level[cnt] + 1;
                q.push(nxt.v);
            }
        }
    }

    return level[t] != INF;
}

inline int dfs( int root, int th ){
    if( root == t ) return th;

    int cost = 0;
    for( auto &nxt : edge[root] ){
        if( level[nxt.v] != level[root] + 1 ) continue;
        if( nxt.cap == 0 ) continue;
        
        int flow = dfs(nxt.v, min(th, nxt.cap));

        cost += flow;
        nxt.cap -= flow;
        th -= flow;
        edge[nxt.v][nxt.rid].cap += flow;
    }
 
    if( !cost ) level[root] = INF;

    return cost;
}

inline int dinic(){
    while( bfs() ){
        res += dfs(s, INF);
    }

    return res;
}

inline void solve(){
    int counter = 0;
    while( cin >> n && n ){
        cin >> s >> t >> m;

        res = 0;
        edge.cr; edge.rz(n + 5);
        for( int i = 0 ; i < m ; ++i ){
            cin >> u >> v >> w;
            add_edge();
        }

        cout << "Network " << ++counter << "\n";
        cout << "The bandwidth is " << dinic() << ".\n\n";
    }
}

signed main(){
    // IO;

    int T = 1;
    // cin >> T;
    while( T-- ){
        solve();
    }
}