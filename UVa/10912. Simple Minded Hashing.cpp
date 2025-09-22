/* Question : UVa 10912. Simple Minded Hashing */

#include<bits/stdc++.h>
using namespace std;

/* Pragma */
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

/* Self Define */
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MEM(_array, _value) memset(_array, _value, sizeof(_array));
#define ALL(_array) _array.begin(), _array.end()
#define LB(_array, v) lower_bound(ALL(_array), v)
#define UB(_array, v) upper_bound(ALL(_array), v)
#define REV(_vector) _vector.reverse()
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
const int         MAXN = 1e4 + 50;
const int          Mod = 1e9 + 7;
const int          INF = 0x7FFFFFFF;
const ll         LLINF = 0x7FFFFFFFFFFFFFFF;
const int       MEMINF = 0x3F;
const int   MEMINF_VAL = 0x3F3F3F3F;
const ll  MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int l, s, dp[26 + 50][MAXN]['z' + 50];

inline void solve(){
    for( int j = 'a' ; j <= 'z' ; ++j ) dp[1][j - 'a' + 1][j] = 1;

    for( int len = 2 ; len <= 26 ; ++len ){
        for( int sum = len * 1 ; sum <= 26 * 'z' ; ++sum ){
            for( int last = 'a' ; last <= 'z' ; ++last ){
                for( int i = 'a' ; i < last ; ++i ) dp[len][sum][last] += dp[len - 1][sum - (last - 'a' + 1)][i];
            }
        }
    }

    int counter = 1;
    while( cin >> l >> s && ( l || s ) ){
        cout << "Case " << counter++ << ": ";

        if( l > 26 || s > 26 * 26 ){
            cout << "0\n";
            continue;
        }

        int res = 0;
        for( int i = 'a' ; i <= 'z' ; ++i ) res += dp[l][s][i];

        cout << res << "\n";
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