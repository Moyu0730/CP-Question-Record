/* Question : CSES 1713. Counting Divisors */

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
const int         MAXN = 1e6 + 50;
const int          Mod = 1e9 + 7;
const int          INF = 0x7FFFFFFF;
const ll         LLINF = 0x7FFFFFFFFFFFFFFF;
const int       MEMINF = 0x3F;
const int   MEMINF_VAL = 0x3F3F3F3F;
const ll  MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int n;

bitset<MAXN> is_prime;
vc(int) primes;
int mpf[MAXN], phi[MAXN], mu[MAXN];

void sieve(){
    is_prime.set();
    is_prime[1] = 0;
    mu[1] = phi[1] = 1;
    for( int i = 2 ; i < MAXN ; i++ ){
        if( is_prime[i] ){
            mpf[i] = i;
            primes.pb(i);
            phi[i] = i - 1;
            mu[i] = -1;
        }
        for( int p : primes ){
            if( p > mpf[i] || i * p >= MAXN ) break;
            is_prime[i * p] = 0;
            mpf[i * p] = p;
            mu[i * p] = -mu[i];
            if( i % p == 0 ){
                phi[i * p] = phi[i] * p;
                mu[i * p] = 0;
            }else phi[i * p] = phi[i] * (p - 1);
        }
    }
}

int getFactor( int x ){
    vc(int) fac = { 1 };

    while( x > 1 ){
        const int p = mpf[x];
        vc(int) cur = { 1 };

        while( x % p == 0 ){
            x /= p;
            cur.pb(cur.back() * p);
        }

        vc(int) tmp;
        for( auto i : fac ){
            for( auto j : cur ) tmp.pb(i * j);
        }
        tmp.swap(fac);
    }
    return fac.sz;
}

inline void solve(){
    cin >> n;
    cout << getFactor(n) << "\n";
}

signed main(){
    IO;

    sieve();

    int T = 1;
    cin >> T;
    while( T-- ){
        solve();
    }
}