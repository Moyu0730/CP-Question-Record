/* Question : AtCoder Beginner Contest 437 - D. Sum of Differences */

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
#define az assign
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
const int     MAXN = 3e5 + 50;
const int      MOD = 998244353;
const int      INF = 0x7FFFFFFF;
const int    LLINF = 0x7FFFFFFFFFFFFFFF;
const int MEMLLINF = 0x3F3F3F3F3F3F3F3F;

int n, m, res, A[MAXN], B[MAXN], pfs[MAXN];

inline void solve(){
    cin >> n >> m;

    for( int i = 1 ; i <= n ; ++i ){
        cin >> A[i];
        A[i] %= MOD;
    }

    for( int i = 1 ; i <= m ; ++i ){
        cin >> B[i];
        B[i] %= MOD;
    }
    
    sort(B + 1, B + 1 + m);

    for( int i = 1 ; i <= m ; ++i ) pfs[i] = ( pfs[i-1] + B[i] ) % MOD;

    for( int i = 1 ; i <= n ; ++i ){
        auto ind = lower_bound(B + 1, B + 1 + m, A[i]) - B;

        int more = m - ind + 1;
        int less = ind - 1;

        res = ( res + ( ( ( pfs[m] - pfs[ind-1] ) % MOD + MOD ) % MOD + MOD - ( more * A[i] ) % MOD + MOD ) % MOD ) % MOD;
        res = ( res + ( ( less * A[i] - pfs[ind-1] ) % MOD + MOD ) % MOD ) % MOD;
    }
    
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