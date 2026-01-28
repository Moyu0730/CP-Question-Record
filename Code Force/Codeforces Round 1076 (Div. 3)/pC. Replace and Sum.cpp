/* Question : OJ Number */

#include<bits/stdc++.h>
using namespace std;

/* Pragma */
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

/* Self Define */
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MEM(_A, _V) memset(_A, _V, sizeof(_A))
#define ALL(_A) _A.begin(), _A.end()
#define LB(_A, _V) lower_bound(ALL(_A), _V)
#define UB(_A, _V) upper_bound(ALL(_A), _V)
#define pii pair<int, int>
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
const int     MAXN = 1e7 + 50;
const int      Mod = 1e9 + 7;
const int      INF = 0x7FFFFFFF;
const int    LLINF = 0x7FFFFFFFFFFFFFFF;
const int MEMLLINF = 0x3F3F3F3F3F3F3F3F;

int n, q, x, y, a[MAXN], b[MAXN], pfs[MAXN];

inline void solve(){
    cin >> n >> q;

    for( int i = 1 ; i <= n ; ++i ) cin >> a[i];
    for( int i = 1 ; i <= n ; ++i ) cin >> b[i];
    a[n+1] = 0;
    b[n+1] = 0;

    for( int i = 1 ; i <= n ; ++i ) a[i] = max(a[i], b[i]);
    for( int i = n ; i >= 1 ; --i ) a[i] = max(a[i], a[i+1]);

    for( int i = 1 ; i <= n ; ++i ) pfs[i] = pfs[i-1] + a[i];

    while( q-- ){
        cin >> x >> y;
        cout << pfs[y] - pfs[x-1] << " ";
    }

    cout << "\n";
}

signed main(){
    IO;

    // cout << "---\n";

    int T = 1;
    cin >> T;
    while( T-- ){
        solve();
    }
}