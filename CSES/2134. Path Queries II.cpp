/* Question : 2134. Path Queries II */
 
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
// #define int long long
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
const int         MAXN = 2e5 + 50;
const int          Mod = 1e9 + 7;
const int          INF = 0x7FFFFFFF;
const ll         LLINF = 0x7FFFFFFFFFFFFFFF;
const int       MEMINF = 0x3F;
const int   MEMINF_VAL = 0x3F3F3F3F;
const ll  MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;
 
#define nL v * 2
#define nR v * 2 + 1
 
struct HLD {
    struct NODE {
        int size, fa, depth, hson, id, chain;
    } node[MAXN];
 
    int timer = 0, id2pos[MAXN];
    vector<vector<int>> edge;
 
    void init(){
        build(1, 0);
        decomposition(1, 1);
    }
 
    int build( int root, int dep ){
        node[root].hson = 0;
        node[node[root].hson].size = 0;
        node[root].depth = dep;
        node[root].size = 1;
        for( auto i : edge[root] ){
            if( i == node[root].fa ) continue;
            node[i].fa = root;
            node[root].size += build(i, dep + 1);
            if( node[i].size > node[node[root].hson].size ){
                node[root].hson = i;
            }
        }
        return node[root].size;
    }
 
    void decomposition( int root, int chain ){
        node[root].chain = chain;
        node[root].id = ++timer;
        id2pos[node[root].id] = root;
        if( node[root].hson != 0 ){
            decomposition(node[root].hson, chain);
            for( auto i : edge[root] ){
                if( i == node[root].fa || i == node[root].hson ) continue;
                decomposition(i, i);
            }
        }
    }
};
 
int n, q, u, v, op, a, b, arr[MAXN], seg[MAXN * 4];
HLD hld;
 
void build( int L, int R, int v ){
    if( L == R ){
        seg[v] = arr[hld.id2pos[L]];
        return;
    }
 
    int M = ( L + R ) / 2;
    build(L, M, nL);
    build(M+1, R, nR);
    seg[v] = max(seg[nL], seg[nR]);
}
 
int query( int L, int R, int qL, int qR, int v ){
    if( R < L || qR < L || R < qL ) return -1;
    if( qL <= L && R <= qR ) return seg[v];
 
    int M = ( L + R ) / 2;
    return max( query(L, M, qL, qR, nL), query(M+1, R, qL, qR, nR) );
}
 
void modify( int L, int R, int mL, int mR, int mV, int v ){
    if( R < L || mR < L || R < mL ) return;
    if( L == R && mL == L && mR == R ){
        seg[v] = mV;
        return;
    }
 
    int M = ( L + R ) / 2;
    modify(L, M, mL, mR, mV, nL);
    modify(M+1, R, mL, mR, mV, nR);
    seg[v] = max(seg[nL], seg[nR]);
    return;
}
 
inline void solve(){
    cin >> n >> q;
 
    for( int i = 1 ; i <= n ; ++i ) cin >> arr[i];
 
    hld.edge.resize(n+ 5);
    for( int i = 0 ; i < n - 1 ; ++i ){
        cin >> u >> v;
 
        hld.edge[u].pb(v);
        hld.edge[v].pb(u);
    }
 
    hld.init();
    build(1, n, 1);
 
    while( q-- ){
        cin >> op >> a >> b;
 
        if( op == 1 ) modify(1, n, hld.node[a].id, hld.node[a].id, b, 1);
        else{
            int res = -1;
            while( hld.node[a].chain != hld.node[b].chain ){
                // cout << "Enter\n";
                if( hld.node[hld.node[a].chain].depth < hld.node[hld.node[b].chain].depth ) swap(a, b);
 
                res = max( res, query(1, n, hld.node[hld.node[a].chain].id, hld.node[a].id, 1) );
                a = hld.node[hld.node[a].chain].fa;
            }
            
            res = max(res, query(1, n, min(hld.node[a].id, hld.node[b].id), max(hld.node[a].id, hld.node[b].id), 1));
 
            cout << res << " ";
        }
    }
 
    cout << "\n";
}
 
signed main(){
    IO;
 
    int T = 1;
    // cin >> T;
    while( T-- ){
        solve();
    }
}