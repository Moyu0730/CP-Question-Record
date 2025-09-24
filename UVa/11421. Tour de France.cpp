/* Question : UVa 11421. Tour de France */

#include<bits/stdc++.h>
using namespace std;

/* Pragma */
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

/* Self Define */
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MEM(_array, _value) memset(_array, _value, sizeof(_array));
#define ALL(_array) _array.begin(), _array.end()
#define LB(_array, v) lower_bound(ALL(_array), v)
#define UB(_array, v) upper_bound(ALL(_array), v)
#define REV(_vector) _vector.reverse();
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
    return _os << '(' << _pair.F << ", " << _pair.S << ')';
}

/* Self Define Const */
const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1},  {-1, 0}, {0, -1},
                                            {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
const int         MAXN = 10 + 50;
const int          Mod = 1e9 + 7;
const int          INF = 0x7FFFFFFF;
const ll         LLINF = 0x7FFFFFFFFFFFFFFF;
const int       MEMINF = 0x3F;
const int   MEMINF_VAL = 0x3F3F3F3F;
const ll  MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

double n, m, cnt, arr[MAXN];
vector<double> v;

inline void solve(){
    while( cin >> n && n ){
        cin >> m;

        v.clear();
        for( int i = 0 ; i < n ; ++i ) cin >> arr[i];
        for( int i = 0 ; i < m ; ++i ){
            cin >> cnt;
            for( int j = 0 ; j < n ; ++j ){
                v.pb(cnt / arr[j]);
            }
        }

        sort(ALL(v));

        double res = -1;
        for( int i = 0 ; i < v.sz - 1 ; ++i ) res = max(res, v[i+1] / v[i] );

        cout << fixed << setprecision(2) << res << "\n";
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