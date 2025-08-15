/* Question : CSES 1735. Range Updates and Sums */

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

#define nL (x<<1)
#define nR (x<<1) + 1

int n, q, arr[MAXN];

struct Node {
    int len, sum, tag = 0, val = 0;
    int rv(){
        if( val == 0 ) return sum + ( len * tag );
        else return ( len * val ) + ( len * tag );
    }
} seg[MAXN * 4];

void build( int L, int R, int x ){
    seg[x].len = R - L + 1;
    
    if( L > R ) return;
    if( L == R ){
        seg[x].sum = arr[L];
        return;
    }

    int M = ( L + R ) / 2;
    build(L, M, nL);
    build(M+1, R, nR);

    seg[x].sum = seg[nL].sum + seg[nR].sum;
}

void push( int x ){
    if( seg[x].val != 0 ){
        seg[nL].val = seg[x].val;
        seg[nL].tag = seg[x].tag;
    }else seg[nL].tag += seg[x].tag;

    if( seg[x].val != 0 ){
        seg[nR].val = seg[x].val;
        seg[nR].tag = seg[x].tag;
    }else seg[nR].tag += seg[x].tag;

    seg[x].sum = seg[x].rv();
    seg[x].val = 0;
    seg[x].tag = 0;
}

int query( int L, int R, int qL, int qR, int x ){
    if( L > R || qR < L || R < qL ) return 0;
    else if( qL <= L && R <= qR )return seg[x].rv();

    push(x);

    int M = ( L + R ) / 2;
    return query(L, M, qL, qR, nL) + query(M+1, R, qL, qR, nR);
}

void modifyA( int L, int R, int mL, int mR, int val, int x ){
    if( L > R || mR < L || R < mL ) return;
    else if( mL <= L && R <= mR ){
        seg[x].tag += val;
        return;
    }

    push(x);

    int M = ( L + R ) / 2;
    modifyA(L, M, mL, mR, val, nL);
    modifyA(M+1, R, mL, mR, val, nR);

    seg[x].sum = seg[nL].rv() + seg[nR].rv();
}

void modifyB( int L, int R, int mL, int mR, int val, int x ){
    if( L > R || mR < L || R < mL ) return;
    else if( mL <= L && R <= mR ){
        seg[x].val = val;
        seg[x].tag = 0;
        return;
    }

    push(x);

    int M = ( L + R ) / 2;
    modifyB(L, M, mL, mR, val, nL);
    modifyB(M+1, R, mL, mR, val, nR);

    seg[x].sum = seg[nL].rv() + seg[nR].rv();
}

inline void solve(){
    cin >> n >> q;

    for( int i = 1 ; i <= n ; ++i ) cin >> arr[i];
    
    build(1, n, 1);

    int op, a, b, c;
    while( q-- ){
        cin >> op;

        if( op == 1 ){
            cin >> a >> b >> c;
            modifyA(1, n, a, b, c, 1);
        }else if( op == 2 ){
            cin >> a >> b >> c;
            modifyB(1, n, a, b, c, 1);
        }else{
            cin >> a >> b;
            cout << query(1, n, a, b, 1) << "\n";
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