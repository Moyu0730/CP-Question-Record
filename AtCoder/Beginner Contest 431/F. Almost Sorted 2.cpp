/* Question : AtCoder Beginner Contest 431 - F. Almost Sorted 2 */

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
#define REV(_vector) reverse(ALL(_vector))
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
template <typename T> void pV(vector<T> _vector ){
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
const int          Mod = 998244353;
const int          INF = 0x7FFFFFFF;
const ll         LLINF = 0x7FFFFFFFFFFFFFFF;
const int       MEMINF = 0x3F;
const int   MEMINF_VAL = 0x3F3F3F3F;
const ll  MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int n, d, res, arr[MAXN], fac[MAXN], facd[MAXN];
map<int, int> mp;

inline int ksm( int base, int power ){
    int tmp = 1;
    while( power ){
        if( power & 1 ) tmp = ( tmp * base ) % Mod;

        power >>= 1;
        base = ( base * base ) % Mod;
    }

    return tmp;
}

inline int binom( int x, int y ){
    return ( ( fac[x] * facd[y] ) % Mod * facd[x-y] ) % Mod;
}

inline void solve(){
    cin >> n >> d;
    for( int i = 0 ; i < n ; ++i ){
        cin >> arr[i];
        ++mp[arr[i]];
    }

    fac[1] = 1;
    for( int i = 2 ; i <= n ; ++i ) fac[i] = fac[i-1] * i % Mod;

    facd[n] = ksm(fac[n], Mod - 2);
    for( int i = n - 1 ; i >= 0 ; --i ) facd[i] = facd[i + 1] * ( i + 1 ) % Mod;

    res = 1;
    int amt = 0;
    auto lft = mp.begin();
    for( auto i : mp ){
        while( lft->F + d < i.F ){
            amt -= lft->S;
            ++lft;
        }

        amt += i.S;

        res *= binom(amt, i.S);
        res %= Mod;
    }

    cout << res << "\n";
}

signed main(){
    // IO;

    int T = 1;
    // cin >> T;
    while( T-- ){
        solve();
    }
}