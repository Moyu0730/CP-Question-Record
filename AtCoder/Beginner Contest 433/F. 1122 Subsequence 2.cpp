/* Question : AtCoder Beginner Contest 433 - F. 1122 Subsequence 2 */

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
#define rz resize
#define cr clear()
#define pb push_back
#define F first
#define S second
#define X first
#define Y second
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
const int         MAXN = 2e6 + 50;
const int          Mod = 998244353;
const int          INF = 0x7FFFFFFF;
const ll         LLINF = 0x7FFFFFFFFFFFFFFF;
const int       MEMINF = 0x3F;
const int   MEMINF_VAL = 0x3F3F3F3F;
const ll  MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int res;
string str;
vc(vc(int)) nxt;
int fac[MAXN], facd[MAXN];

int fermat( int base ){
    int power = Mod - 2;

    int tmp = 1;
    while( power ){
        if( power & 1 ) tmp = ( tmp * base ) % Mod;
        
        base = ( base * base ) % Mod;
        power >>= 1;
    }

    return tmp;
}

int binom( int n, int k ){
    if( n < 0 || k < 0 || n < k ) return 0;
    return ( ( fac[n] * facd[k] ) % Mod * facd[n-k] ) % Mod;
}

inline void solve(){
    cin >> str;

    fac[0] = 1;
    fac[1] = 1;
    for( int i = 2 ; i < MAXN ; ++i ) fac[i] = ( fac[i-1] * i ) % Mod;

    facd[MAXN-1] = fermat(fac[MAXN-1]);
    for( int i = MAXN - 2 ; i >= 0 ; --i ) facd[i] = ( facd[i+1] * ( i + 1 ) ) % Mod;

    nxt.rz(9 + 5);
    for( int i = 0 ; i < str.sz ; ++i ) nxt[str[i]-'0'].pb(i);

    for( int i = 0 ; i < str.sz ; ++i ){
        int p = str[i] - '0' + 1;
        int pos = LB(nxt[str[i] - '0'], i) - nxt[str[i] - '0'].begin();
        int rem = nxt[p].sz - ( LB(nxt[p], i) - nxt[p].begin() );

        // cout << pos << " " << rem << " " << binom(pos + rem, pos + 1) << "\n";

        res = ( res + binom(pos + rem, pos + 1) ) % Mod;
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