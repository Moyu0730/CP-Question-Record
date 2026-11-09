/* Question : UVa Online Judge 10533 - Digit Primes */

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

bool prime[MAXN];
int a, b, pfs[MAXN];

inline int d( int val ){
    int tmp = 0;
    while( val > 0 ){
        tmp += val % 10;
        val /= 10;
    }

    return tmp;
}

inline void solve(){
    cin >> a >> b;
    cout << pfs[b] - pfs[a-1] << "\n";
}

signed main(){
    IO;

    MEM(prime, true);
    prime[0] = false;
    prime[1] = false;
    prime[2] = true;
    for( int i = 2 ; i < 1000000 + 50 ; ++i ){
        if( !prime[i] ){
            pfs[i] = pfs[i-1];
            continue;
        }

        if( prime[d(i)] ) pfs[i] = pfs[i-1] + 1;
        else pfs[i] = pfs[i-1];

        int ctr = 2;
        while( i * ctr < 1000000 + 50 ){
            prime[i * ctr] = false;
            ++ctr;
        }
    }

    int T = 1;
    cin >> T;
    while( T-- ){
        solve();
    }
}