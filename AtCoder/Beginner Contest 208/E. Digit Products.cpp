/* Question : AtCoder Beginner Contest 208 - E. Digit Products */

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
const int     MAXN = 2 + 50;
const int      Mod = 1e9 + 7;
const int      INF = 0x7FFFFFFF;
const int    LLINF = 0x7FFFFFFFFFFFFFFF;
const int MEMLLINF = 0x3F3F3F3F3F3F3F3F;

int n, k, res;
string n_str;
map<int, int> dp[MAXN][MAXN], dp_new[MAXN][MAXN];

inline int cps( int val ){
    return val <= k ? val : k + 1;
}

inline void solve(){
    cin >> n >> k;

    dp[0][0][1] = 1;
    n_str = to_string(n);
    for( int pos = 0 ; pos < n_str.sz ; ++pos ){
        for( int small = 0 ; small <= 1 ; ++small ){
            for( int st = 0 ; st <= 1 ; ++st ){

                int limit = (small == 0) ? n_str[pos] - '0' : 9;
                for( int d = 0 ; d <= limit ; ++d ){
                    for( auto i : dp[small][st] ){
                        int small_new = small | ( d < limit );
                        int st_new = st | ( d != 0 );
                        int prod_new = i.F;

                        if( st == 0 ){
                            if( d == 0 ) prod_new = 1;
                            else prod_new = cps(d);
                        }else{
                            prod_new = cps(prod_new * d);
                        }

                        dp_new[small_new][st_new][prod_new] += dp[small][st][i.F];
                    }
                }
            }
        }

        for( int i = 0 ; i <= 1 ; ++i ){
            for( int j = 0 ; j <= 1 ; ++j ){
                dp[i][j] = dp_new[i][j];
                dp_new[i][j].cr;
            }
        }
    }

    for( auto i : dp[1][1] ){
        if( i.F <= k ) res += i.S;
    }

    int p_new = 1;
    for( auto i : n_str ) p_new *= i - '0';

    if( p_new <= k ) cout << res + 1 << "\n";
    else cout << res << "\n";
}

signed main(){
    IO;

    int T = 1;
    // cin >> T;
    while( T-- ){
        solve();
    }
}