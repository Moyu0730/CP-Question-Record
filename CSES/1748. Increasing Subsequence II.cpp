/* Question : CSES 1748. Increasing Subsequence II */

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
const int         MAXN = 2e5 + 50;
const int          Mod = 1e9 + 7;
const int          INF = 0x7FFFFFFF;
const ll         LLINF = 0x7FFFFFFFFFFFFFFF;
const int       MEMINF = 0x3F;
const int   MEMINF_VAL = 0x3F3F3F3F;
const ll  MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int n, arr[MAXN], dp[MAXN], tmp[MAXN];
vc(int) lis, distinct;

void discretization(){
    for( int i = 0 ; i < n ; ++i ) tmp[i] = arr[i];

    sort(tmp, tmp + n);
    distinct.pb(tmp[0]);

    for( int i = 1 ; i < n ; i++ ){
        if( tmp[i] != tmp[i-1] ) distinct.pb(tmp[i]);
    }

    for( int i = 0 ; i < n ; i++ ) arr[i] = LB(distinct, arr[i]) - distinct.begin() + 1;
}

template<tpn T> struct M {
    static T MOD;
    T v;
    M( T x = 0 ){
        v = (-MOD <= x && x < MOD) ? x : x % MOD;
        if( v < 0 ) v += MOD;
    }
    explicit operator T() const { return v; }
    M operator-(){ return M(-v); }
    M operator+( M b ){ return M(v + b.v); }
    M operator-( M b ){ return M(v - b.v); }
    M operator*( M b ){ return M((__int128)v * b.v % MOD); }
    M& operator=( const M& b ){ v = b.v; return *this; }
    friend M& operator+=( M &a, M b ){ return a = a + b; }
    friend M& operator-=( M &a, M b ){ return a = a - b; }
    friend M& operator*=( M &a, M b ){ return a = a * b; }
    friend M& operator/=( M &a, M b ){ return a = a / b; }
};
template <> int M<int>::MOD = 1000000007;

template<tpn T> struct BIT {
    T ARRAY[MAXN];
    int lowbit( int x ){ return x & -x; }
    BIT (){ clear(); }
    T query( int pos ){
        T ans = 0;
        while( pos ){
            ans += ARRAY[pos];
            pos -= lowbit(pos);
        }
        return ans;
    }
    void update( int x, T val ){
        while( x < MAXN ){
            ARRAY[x] += val;
            x += lowbit(x);
        }
    }
    T sum( int l, int r ){
        if( l > r ) return 0;
        return query(r) - query(l - 1);
    }
    T lower_bound( T val ){ // lower_bound by sum
        T sum = 0, x = 0;
        for( int i = __lg(MAXN) ; i >= 0 ; --i ){
            int new_x = x | (1 << i);
            if( new_x <= MAXN && sum + ARRAY[new_x] < val ){
                sum += ARRAY[new_x];
                x = new_x;
            }
        }
        return x + 1;
    }
    void clear(){ MEM(ARRAY, 0); }
};

inline void solve(){
    cin >> n;

    for( int i = 0 ; i < n ; ++i ) cin >> arr[i];

    discretization();

    BIT<M<int>> bit;
    M<int> res;

    for( int i = 0 ; i < n ; ++i ){
        if( lis.empty() || arr[i] > lis.back() ){
            lis.pb(arr[i]);
        }else{
            int ind = UB(lis, arr[i]) - lis.begin();
            lis[ind] = arr[i];
        }

        res += bit.query(arr[i] - 1).v + 1;
        bit.update(arr[i], bit.query(arr[i] - 1) + 1);
    }

    cout << res.v << "\n";
}

signed main(){
    IO;

    int T = 1;
    // cin >> T;
    while( T-- ){
        solve();
    }
}