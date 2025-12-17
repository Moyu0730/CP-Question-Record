/* Question : AtCoder Beginner Contest 430 - E. Shift String */

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
const int     MAXN = 2e6 + 50;
const int      MOD = 1e9 + 7;
const int      INF = 0x7FFFFFFF;
const int    LLINF = 0x7FFFFFFFFFFFFFFF;
const int MEMLLINF = 0x3F3F3F3F3F3F3F3F;
const int        P = 75577;

int ksm[MAXN], hshv[MAXN];
string a, b;

void getHV(){
    hshv[0] = a[0];
    for( int i = 1 ; i < a.sz ; ++i ) hshv[i] = ( ( hshv[i-1] * P ) % MOD + a[i] ) % MOD;
    
    return;
}

int queryHV( int l, int r ){
    if( l == 0 ) return hshv[r];
    else return ( ( hshv[r] - ( hshv[l-1] * ksm[r-l+1] ) % MOD ) % MOD + MOD ) % MOD;
}

inline void solve(){
    cin >> a >> b;

    a += a;
    getHV();

    int hb = b[0];
    for( int i = 1 ; i < b.sz ; ++i ) hb = ( ( hb * P ) % MOD + b[i] ) % MOD;

    for( int i = 0 ; i + b.sz <= a.sz ; ++i ){
        if( queryHV(i, i + b.sz - 1) == hb ){
            cout << i << "\n";
            return;
        }
    }

    cout << "-1\n";
}

signed main(){
    IO;

    ksm[0] = 1;
    for( int i = 1 ; i < MAXN ; ++i ) ksm[i] = ( ksm[i-1] * P ) % MOD;

    int T = 1;
    cin >> T;
    while( T-- ){
        solve();
    }
}