/* Question : UVa 11770. Lighting Away */

#include<bits/stdc++.h>
using namespace std;

/* Pragma */
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
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
const int     MAXN = 1e5 + 50;
const int      Mod = 1e9 + 7;
const int      INF = 0x7FFFFFFF;
const int    LLINF = 0x7FFFFFFFFFFFFFFF;
const int MEMLLINF = 0x3F3F3F3F3F3F3F3F;

int n, m, u, v, res, dfsTime, amt, counter, low[MAXN], t[MAXN], scc[MAXN], indeg[MAXN];
vector<vector<int>> edge;
vector<set<int>> sccs;
stack<int> stk;

inline void dfs( int root ){
    t[root] = ++dfsTime;
    low[root] = t[root];

    stk.push(root);
    for( auto v : edge[root] ){
        if( !t[v] ){
            dfs(v);

            low[root] = min(low[root], low[v]);
        }else low[root] = min(low[root], t[v]);
    }

    if( t[root] == low[root] ){
        ++amt;

        int nxt;
        do{
            nxt = stk.top();
            stk.pop();
            scc[nxt] = amt;
            t[nxt] = LLONG_MAX;
        }while( nxt != root && !stk.empty() );
    }
}

inline void solve(){
    cin >> n >> m;

    edge.cr; edge.rz(n + 5);
    sccs.cr; sccs.rz(n + 5);
    MEM(low, 0);
    MEM(t, 0);
    MEM(scc, 0);
    MEM(indeg, 0);
    dfsTime = 0;
    amt = 0;
    for( int i = 0 ; i < m ; ++i ){
        cin >> u >> v;

        edge[u].pb(v);
    }

    for( int i = 1 ; i <= n ; ++i ){
        if( !t[i] ) dfs(i);
    }

    for( int i = 1 ; i <= n ; ++i ){
        for( auto j : edge[i] ){
            if( scc[i] == scc[j] ) continue;
            if( sccs[scc[i]].find(scc[j]) == sccs[scc[i]].end() ){
                sccs[scc[i]].insert(scc[j]);
                ++indeg[scc[j]];
            }
        }
    }

    res = 0;
    for( int i = 1 ; i <= amt ; ++i ){
        if( !indeg[i] ) ++res;
    }

    cout << "Case " << ++counter << ": " << res << "\n";
}

signed main(){
    IO;

    int T = 1;
    cin >> T;
    while( T-- ){
        solve();
    }
}