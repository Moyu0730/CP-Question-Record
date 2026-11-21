/* Question : AtCoder Beginner Contest 338 - D. Island Tour */

#include<bits/stdc++.h>
using namespace std;

/* Pragma */
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

/* Self Define */
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MEM(_A, _V) memset(_A, _V, sizeof(_A))
#define ALL(_A) _A.begin(), _A.end()
#define LB(_A, _V) lower_bound(ALL(_A), _V)
#define UB(_A, _V) upper_bound(ALL(_A), _V)
#define pii pair<int, int>
#define sz size()
#define cr clear()
#define as assign
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
const int     MAXN = 2e5 + 50;
const int      Mod = 1e9 + 7;
const int      INF = 0x7FFFFFFF;
const int    LLINF = 0x7FFFFFFFFFFFFFFF;
const int MEMLLINF = 0x3F3F3F3F3F3F3F3F;

#define nL x<<1
#define nR (x<<1) + 1

int n, m, res, ans, seg[MAXN * 4], tag[MAXN * 4], len[MAXN * 4];
vector<int> arr;

inline void push( int x ){
    tag[nL] += tag[x];
    tag[nR] += tag[x];
    seg[x] += tag[x] * len[x];
    tag[x] = 0;
}

inline int query( int L, int R, int qL, int qR, int x ){
    if( qR < L || R < qL ) return 0;
    if( qL <= L && R <= qR ) return seg[x] + tag[x] * len[x];

    push(x);

    int M = ( L + R ) / 2;
    return query(L, M, qL, qR, nL) + query(M+1, R, qL, qR, nR);
}

inline void modify( int L, int R, int mL, int mR, int x, int val ){
    if( mR < L || R < mL ) return;
    if( mL <= L && R <= mR ){
        tag[x] += val;
        return;
    }

    push(x);

    int M = ( L + R ) / 2;
    modify(L,   M, mL, mR, nL, val);
    modify(M+1, R, mL, mR, nR, val);
    seg[x] = seg[nL] + tag[nL] * len[nL] + seg[nR] + tag[nR] * len[nR];
}

inline void build( int L, int R, int x ){
    len[x] = R - L + 1;

    if( L == R ) return;

    int M = ( L + R ) / 2;
    build(L,   M, nL);
    build(M+1, R, nR);
    seg[x] = seg[nL] + seg[nR];
}

inline void solve(){
    cin >> n >> m;

    arr.rz(m);
    for( int i = 0 ; i < m ; ++i ) cin >> arr[i];
    
    build(1, n, 1);

    for( int i = 1 ; i < m ; ++i ){
        int l = min(arr[i-1], arr[i]);
        int r = max(arr[i-1], arr[i]);

        if( l > 1 ) modify(1, n, 1, l-1, 1, r - l);
        modify(1, n, l, r-1, 1, n - (r - l));
        modify(1, n, r, n,   1, r - l);
    }

    int res = LLONG_MAX;
    for( int i = 1 ; i <= n ; ++i ) res = min(res, query(1, n, i, i, 1));

    cout << res << "\n";
}

signed main(){
    IO;

    int T = 1;
    // cin >> T;
    while( T-- ){
        solve();
    }
}