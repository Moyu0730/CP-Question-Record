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
#define pdd pair<long double, long double>
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
const int     MAXN = 1e6 + 50;
const int      Mod = 1e9 + 7;
const int      INF = 0x7FFFFFFF;
const int    LLINF = 0x7FFFFFFFFFFFFFFF;
const int MEMLLINF = 0x3F3F3F3F3F3F3F3F;

int n, tmp, amt;
int arr[MAXN];
long double a;
pdd cnt;

inline long double dis( pdd x, pdd y ){
    return sqrt( abs(x.F - y.F) * abs(x.F - y.F) + abs(x.S - y.S) * abs(x.S - y.S) );
}

inline void solve(){
    while( cin >> n && n != 0 ){
        cin >> a;

        amt = 0;
        for( int i = 0 ; i < n ; ++i ){
            cin >> cnt.F >> cnt.S;

            tmp = 0;
            if( dis(cnt, {a, 0}) <= a ) ++tmp;
            if( dis(cnt, {0, a}) <= a ) ++tmp;
            if( dis(cnt, {0, 0}) <= a ) ++tmp;
            if( dis(cnt, {a, a}) <= a ) ++tmp;

            if( tmp == 4 ) ++amt;
        }

        long double ldn = n;
        cout << fixed << setprecision(5) << amt * a * a / ldn << "\n";
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