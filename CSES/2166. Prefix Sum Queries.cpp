/* Question : CSES 2166. Prefix Sum Queries */

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
const int         MAXN = 2e5 + 50;
const int          Mod = 1e9 + 7;
const int          INF = 0x7FFFFFFF;
const ll         LLINF = 0x7FFFFFFFFFFFFFFF;
const int       MEMINF = 0x3F;
const int   MEMINF_VAL = 0x3F3F3F3F;
const ll  MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

#define nL v * 2
#define nR v * 2 + 1

int n, q, arr[MAXN], pre[MAXN];

struct Node {
    int val = 0, tag = 0, len;
    int getValue(){ return val + tag; }
} SEG[MAXN * 4];

void build( int L, int R, int v ){
    SEG[v].len = R - L + 1;
    if( R == L ){
        SEG[v].val = pre[L];
        return;
    }

    int M = (L + R) / 2;
    build(L, M, nL);
    build(M+1, R, nR);
    SEG[v].val = max( SEG[nL].val, SEG[nR].val );
}

void push( int v ){
    SEG[nL].tag += SEG[v].tag;
    SEG[nR].tag += SEG[v].tag;
    SEG[v].val = SEG[v].getValue();
    SEG[v].tag = 0;
}

int query( int L, int R, int qL, int qR, int v ){
    if( R < L || qL > R || qR < L ) return -1 * LLINF;
    if( qL <= L && R <= qR ) return SEG[v].getValue();

    push(v);
    int M = (L + R) / 2;

    return max( query(L, M, qL, qR, nL), query(M+1, R, qL, qR, nR) );
}

void modify( int L, int R, int mL, int mR, int val, int v ){
    if( R < L || mL > R || mR < L ) return;
    if( mL <= L && R <= mR ){
        SEG[v].tag += val;
        return;
    }

    push(v);
    int M = (L + R) / 2;

    modify(L, M, mL, mR, val, nL);
    modify(M+1, R, mL, mR, val, nR);
    SEG[v].val = max( SEG[nL].getValue(), SEG[nR].getValue() );
}

inline void solve(){
    cin >> n >> q;

    for( int i = 1 ; i <= n ; ++i ){
        cin >> arr[i];
        pre[i] = pre[i-1] + arr[i];
    }

    build(1, n, 1);

    int op, a, b;
    while( q-- ){
        cin >> op >> a >> b;

        if( op == 1 ){
            modify(1, n, a, n, b - arr[a], 1);
            arr[a] = b;
        }else{
            if( a == 1) cout << max( (ll)0, query(1, n, a, b, 1) ) << "\n";
            else cout << max( (ll)0, query(1, n, a, b, 1) - query(1, n, a-1, a-1, 1) ) << "\n";
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