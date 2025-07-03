/* Question : CSES 1135. Distance Queries */

#include<bits/stdc++.h>
using namespace std;

/* Pragma */
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

/* Self Define */
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MEM(_array, _value) memset(_array, _value, sizeof(_array));
#define ALL(_array) _array.begin(), _array.end()
#define LB(_array, v) lower_bound(ALL(_array), v)
#define UB(_array, v) upper_bound(ALL(_array), v)
#define REV(_vector) _vector.reverse()
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
const int         MAXN = 2e5 + 50;
const int          Mod = 1e9 + 7;
const int          INF = 0x7FFFFFFF;
const ll         LLINF = 0x7FFFFFFFFFFFFFFF;
const int       MEMINF = 0x3F;
const int   MEMINF_VAL = 0x3F3F3F3F;
const ll  MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int n, q, u, v, res, dep[MAXN], fa[MAXN][25];
vc(vc(int)) edge;

void dfs( int root, int parent ){
    dep[root] = dep[parent] + 1;
    
    for( int i = 1 ; (1<<i) <= dep[root] ; i++ ){
        fa[root][i] = fa[ fa[root][i-1] ][i-1];
    }
    
    for( auto i : edge[root] ){
        if( i == parent ) continue;

        fa[i][0] = root;
        dfs(i, root);
    }
}

void lca( int a, int b ){
    res = 0;

    if( dep[a] > dep[b] ) swap(a, b);

    for( int i = 20 ; i >= 0 ; --i ){
        if( dep[fa[b][i]] >= dep[a] ){
            res += 1<<i;
            b = fa[b][i];
        }

        if( a == b ) return;
    }

    for( int i = 20 ; i >= 0 ; --i ){
        if( fa[a][i] != fa[b][i] ){
            a = fa[a][i];
            b = fa[b][i];
            res += 2 * (1<<i);
        }
    }
    
    res += 2;
}

inline void solve(){
    cin >> n >> q;

    edge.resize(n + 5);

    for( int i = 0 ; i < n-1 ; ++i ){
        cin >> u >> v;

        edge[u].pb(v);
        edge[v].pb(u);
    }

    dfs(1, 0);

    while( q-- ){
        cin >> u >> v;
        lca(u, v);
        cout << res << "\n";
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