/* Question : UVa 10449. Traffic */

#include<bits/stdc++.h>
using namespace std;

/* Pragma */
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

/* Self Define */
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MEM(_array, _value) memset(_array, _value, sizeof(_array));
#define ALL(_array) _array.begin(), _array.end()
#define LB(_array, v) lower_bound(ALL(_array), v)
#define UB(_array, v) upper_bound(ALL(_array), v)
#define vc(_data) vector<_data>
#define pii pair<int, int>
#define pdd pair<double, double>
#define mkp make_pair
#define sz size()
#define pb push_back
#define F first
#define S second
#define int long long
#define ll long long
#define ld long double
#define tpn typename

/* Self Define Template Function */
template <typename T> void pV(vector<T> _vector ) {
    for( auto _it : _vector ) cout << _it << " ";
    cout << "\n";
}

template <typename A, typename B> bool boundry( pair<A, B> &_pair, int _n, int _m ){
    return 1 <= _pair.F && _pair.F <= _n && 1 <= _pair.S && _pair.S <= _m;
}

template <typename A, typename B> istream& operator>>( istream& _is, pair<A, B> &_pair ){ 
    return _is >> _pair.F >> _pair.S;
}

template <typename A, typename B> ostream& operator<<( ostream& _os, pair<A, B> _pair ){ 
    return _os << '(' << _pair.F << " " << _pair.S << ')';
}

/* Self Define Const */
const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1},  {-1, 0}, {0, -1}, 
                                            {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
const int         MAXN = 2e2 + 50;
const int          Mod = 1e9 + 7;
const int          INF = 0x7FFFFFFF;
const ll         LLINF = 0x7FFFFFFFFFFFFFFF;
const int       MEMINF = 0x3F;
const int   MEMINF_VAL = 0x3F3F3F3F;
const ll  MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int n, m, u, v, q, ask, counter, arr[MAXN], dis[MAXN], valid[MAXN];
vector< pair<int, pii> > edge;
vector<vector<int>> graph;

inline int trp( int val ){ return val * val * val; }

inline void dfs( int root ){
    valid[root] = false;

    for( auto nxt : graph[root] ){
        if( !valid[nxt] ) continue;

        dfs(nxt);
    }
}

inline void bell(){
    MEM(dis, MEMINF);
    MEM(valid, true);
    
    dis[1] = 0;

    for( int i = 0 ; i <= n ; ++i ){
        for( auto [w, e] : edge ){
            auto [x, y] = e;

            if( dis[x] >= MEMLLINF_VAL ) continue;
            if( dis[x] + w < dis[y] ){
                if( i == n ) dfs(y);

                dis[y] = dis[x] + w;
            }
        }
    }
}

inline void solve(){
    while( cin >> n ){
        for( int i = 1 ; i <= n ; ++i ) cin >> arr[i];

        edge.clear();
        edge.resize(n+1);
        graph.clear();
        graph.resize(n+1);
        cin >> m;
        for( int i = 0 ; i < m ; ++i ){
            cin >> u >> v;

            graph[u].pb(v);
            edge.pb({trp(arr[v] - arr[u]), {u, v}});
        }

        bell();

        cout << "Set #" << ++counter << "\n";
        cin >> q;
        while( q-- ){
            cin >> ask;
            
            if( !valid[ask] || dis[ask] < 3 || dis[ask] >= MEMLLINF_VAL ) cout << "?\n";
            else cout << dis[ask] << "\n";
        }
    }
}

signed main(){
    IO;

    int T = 1;
    // cin >> T;
    while( T-- ){
        solve();
    }
}