/* Question : UVa 389. Basically Speaking */

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
const int     MAXN = 1e7 + 50;
const int      Mod = 1e9 + 7;
const int      INF = 0x7FFFFFFF;
const int    LLINF = 0x7FFFFFFFFFFFFFFF;
const int MEMLLINF = 0x3F3F3F3F3F3F3F3F;

string str, res;
int from, to, cnt, acc, val, ksm[7 + 5];
char tran[16 + 5] = {'0', '1', '2', '3', '4', '5', '6', '7',
                     '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

inline void solve(){
    while( cin >> str ){
        cin >> from >> to;

        reverse(ALL(str));
        cnt = 1;
        val = 0;
        for( auto i : str ){
            if( isdigit(i) ) val += cnt * ( i - '0' );
            else val += cnt * ( i - 'A' + 10 );

            cnt *= from;
        }

        res.cr;
        int heading = false;
        for( int i = 6 ; i >= 0 ; --i ){
            cnt = 1;
            for( int j = 0 ; j < i ; ++j ) cnt *= to;

            if( val / cnt >= to ) break;
            else{
                if( heading || ( val / cnt ) != 0 ){
                    heading = true;
                    res.pb(tran[val / cnt]);
                }
            }

            val -= (val / cnt) * cnt;
        }

        if( val == 0 && res.sz == 0 ) cout << setw(7) << right << setfill(' ') << 0 << "\n";
        else if( val == 0 ) cout << setw(7) << right << setfill(' ') << res << "\n";
        else if( res.sz == 0 || val > 0 ) cout << "  ERROR\n";
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