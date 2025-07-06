/* Question : CSES 1138. Path Queries */

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
#define ld long double
#define tpn typename

#define nL v * 2
#define nR v * 2 + 1

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

int n, q, u, v, timer, tp, s, x, arr[MAXN], id2pos[MAXN];
vc(vc(int)) edge;

struct HLDNODE {
    int size, fa, depth, hson, id, chain;
} node[MAXN];

int tree_build( int root, int dep ){
    node[root].hson = 0;
    node[node[root].hson].size = 0;
    node[root].depth = dep;
    node[root].size = 1;
    
    for( auto i : edge[root] ){
        if( i == node[root].fa ) continue;

        node[i].fa = root;
        node[root].size += tree_build(i, dep + 1);

        if( node[i].size > node[node[root].hson].size ) node[root].hson = i;
    }

    return node[root].size;
}

void tree_decom( int root, int chain ){
    node[root].chain = chain;
    node[root].id = ++timer;
    id2pos[node[root].id] = root;

    if( node[root].hson != 0 ){
        tree_decom(node[root].hson, chain);
        for( auto i : edge[root] ){
            if( i == node[root].fa || i == node[root].hson ) continue;

            tree_decom(i, i);
        }
    }
}

struct NODE {
    int val = 0, tag = 0, len;
    int getValue(){ return val + (tag * len); }
} SEG[MAXN * 4];

void build( int L, int R, int v ){
    SEG[v].len = R - L + 1;
    if( R == L ){
        SEG[v].val = arr[id2pos[L]];
        return;
    }

    int M = (L + R) / 2;
    build(L, M, nL);
    build(M+1, R, nR);
    SEG[v].val = SEG[nL].val + SEG[nR].val;
}

void push( int v ){
    SEG[nL].tag += SEG[v].tag;
    SEG[nR].tag += SEG[v].tag;
    SEG[v].val = SEG[v].getValue();
    SEG[v].tag = 0;
}

int query( int L, int R, int qL, int qR, int v ){
    if( R < L || qL > R || qR < L ) return 0;
    if( qL <= L && R <= qR ) return SEG[v].getValue();

    push(v);
    int M = (L + R) / 2;
    return query(L, M, qL, qR, nL) + query(M+1, R, qL, qR, nR);
}

void modify( int L, int R, int mL, int mR, int val, int v ){
    if( R < L || mL > R || mR < L ) return;
    if( mL <= L && R <= mR ){
        SEG[v].tag += val;
        return;
    }

    int M = (L + R) / 2;
    modify(L, M, mL, mR, val, nL);
    modify(M+1, R, mL, mR, val, nR);
    SEG[v].val = SEG[nL].getValue() + SEG[nR].getValue();
}

inline void solve(){
    cin >> n >> q;
    
    for( int i = 1 ; i <= n ; ++i ) cin >> arr[i];

    edge.resize(n + 5);
    for( int i = 0 ; i < n - 1 ; ++i ){
        cin >> u >> v;
        edge[u].pb(v);
        edge[v].pb(u);
    }

    tree_build(1, 0);
    tree_decom(1, 1);

    build(1, n, 1);

    while( q-- ){
        cin >> tp;

        if( tp == 1 ){
            cin >> s >> x;

            int tmp = query(1, n, node[s].id, node[s].id, 1);
            modify(1, n, node[s].id, node[s].id, x - tmp, 1);
        }else{
            cin >> u;
            v = 1;

            int res = 0;
            while( node[u].chain != node[v].chain ){
                if( node[node[u].chain].depth < node[node[v].chain].depth ){
                    swap(u, v); // guarantee u is deeper
                }

                res += query(1, n, node[node[u].chain].id, node[u].id, 1);
                u = node[node[u].chain].fa;
            }

            res += query(1, n, min(node[u].id, node[v].id), max(node[u].id, node[v].id), 1);

            cout << res << "\n";
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