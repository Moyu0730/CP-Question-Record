/* Question : CSES 2206. Pizzeria Queries */

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

#define nL x<<1
#define nR (x<<1) + 1

int n, q, arr[MAXN], upward[MAXN * 4], downward[MAXN * 4];

void build( int L, int R, int x, int tp ){
    if( L > R ) return;
    if( L == R ){
        if( tp == 0 ) upward[x] = arr[L] + L; // up
        else downward[x] = arr[L] + n - L - 1; // down
        return;
    }

    int M = ( L + R ) / 2;
    build(L, M, nL, tp);
    build(M+1, R, nR, tp);

    if( tp == 0 ) upward[x] = min(upward[nL], upward[nR]);
    else downward[x] = min(downward[nL], downward[nR]);

    return;
}

int query( int L, int R, int qL, int qR, int x, int tp ){
    if( L > R || qL > R || qR < L ) return INF;
    if( qL <= L && R <= qR ){
        if( tp == 0 ) return upward[x];
        else return downward[x];
    }

    int M = ( L + R ) / 2;
    return min( query(L, M, qL, qR, nL, tp), query(M+1, R, qL, qR, nR, tp) );
}

void modify( int L, int R, int mL, int mR, int x, int val ){
    if( L > R || mL > R || mR < L ) return;
    if( mL <= L && R <= mR ){
        upward[x] = val + L; // up
        downward[x] = val + n - L - 1; // down

        return;
    }

    int M = ( L + R ) / 2;
    modify(L, M, mL, mR, nL, val);
    modify(M+1, R, mL, mR, nR, val);

    upward[x] = min(upward[nL], upward[nR]);
    downward[x] = min(downward[nL], downward[nR]);

    return;
}

inline void solve(){
    cin >> n >> q;

    for( int i = 1 ; i <= n ; ++i ) cin >> arr[i];

    build(1, n, 1, 0);
    build(1, n, 1, 1);

    int t, a, b;
    while( q-- ){
        cin >> t;

        if( t == 1 ){
            cin >> a >> b;

            modify(1, n, a, a, 1, b);
        }else{
            cin >> a;

            cout << min( query(1, n, a, n, 1, 0) - a, query(1, n, 1, a, 1, 1) - n + a + 1 ) << "\n";
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