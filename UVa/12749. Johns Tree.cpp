/* Question : CSES 12749. John's Tree */

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
const int         MAXN = 1e7 + 50;
// const int          Mod = 1e9 + 7;
const int          INF = 0x7FFFFFFF;
const ll         LLINF = 0x7FFFFFFFFFFFFFFF;
const int       MEMINF = 0x3F;
const int   MEMINF_VAL = 0x3F3F3F3F;
const ll  MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

tuple<ll, ll, ll> exgcd( ll a, ll b ){
    ll s = 1, t = 0, u = 0, v = 1;
    while( b ){
        ll q = a / b;
        swap(a -= q * b, b);
        swap(s -= q * t, t);
        swap(u -= q * v, v);
    }
    return {s, u, a};
}

template<tpn T> struct M {
    static T MOD;
    T v;
    M( T x = 0 ){
        v = (-MOD <= x && x < MOD) ? x : x % MOD;
        if( v < 0 ) v += MOD;
    }
    explicit operator T() const { return v; }
    bool operator==( const M &b ) const { return v == b.v; }
    bool operator!=( const M &b ) const { return v != b.v; }
    M operator-(){ return M(-v); }
    M operator+( M b ){ return M(v + b.v); }
    M operator-( M b ){ return M(v - b.v); }
    M operator*( M b ){ return M((__int128)v * b.v % MOD); }
    M operator/( M b ){ return *this * b.inv(); }
    M& operator=( const M& b ){ v = b.v; return *this; }
    // change above implement to this if MOD isn’t prime
    // Modular Multiplicative Inverse
    M inv(){
        ll p, unused, g;
        tie(p, unused, g) = exgcd(v, MOD);
        assert(g == 1); // Make sure inverse exists
        return M(p);
    }
    friend M operator^( M a, ll b ){
        M ans(1);
        for( ; b ; b >>= 1, a *= a ){
            if( b & 1 ) ans *= a;
        }
        return ans;
    }
    friend M& operator+=( M &a, M b ){ return a = a + b; }
    friend M& operator-=( M &a, M b ){ return a = a - b; }
    friend M& operator*=( M &a, M b ){ return a = a * b; }
    friend M& operator/=( M &a, M b ){ return a = a / b; }
};
using Mod = M<int>;
template <> int Mod::MOD = 1e9 + 7;
int &MOD = Mod::MOD;

int d, tmp, counter;

inline void solve(){
    cin >> d >> tmp;

    Mod v(tmp);

    if( d != 0 && d != 1 && v == 1 ){
        cout << "Case " << ++counter << ": -1\n";
        return;
    }

    if( d == 0 ){
        cout << "Case " << ++counter << ": 1\n";
        return;
    }

    if( d == 1 ){
        cout << "Case " << ++counter << ": "<< ( v + Mod((ll)1) ).v << "\n";
        return;
    }

    if( v == 2 ){
        cout << "Case " << ++counter << ": " << ( ( Mod((ll)2) * Mod(d) ) + 1 ).v << "\n";
        return;
    }

    Mod numerator = (Mod(v-1)^d) - 1;
    Mod denominator = v - 2;
    Mod ans = Mod(1) + Mod(v) * (numerator / denominator);
    cout << "Case " << ++counter << ": " << ans.v << "\n";
}

signed main(){
    IO;

    int T = 1;
    cin >> T;
    while( T-- ){
        solve();
    }
}