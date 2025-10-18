/* Question : OJ Number */

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
const int         MAXN = 1e5 + 50;
const int          Mod = 1e9 + 7;
const int          INF = 0x7FFFFFFF;
const ll         LLINF = 0x7FFFFFFFFFFFFFFF;
const int       MEMINF = 0x3F;
const int   MEMINF_VAL = 0x3F3F3F3F;
const ll  MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

double fax[5][4] = {
                  {0.10, 0.06, 0.02},
                  {0.25, 0.15, 0.05},
                  {0.53, 0.33, 0.13},
                  {0.87, 0.47, 0.17},
                  {1.44, 0.80, 0.30}  };
double val[3 + 5];
int section[3 + 5] = { 0, 8 * 60, 18 * 60, 22 * 60, 24 * 60 };
int a, b, c, d, s, t, used[MAXN];
char ch;
string str;

inline void solve(){
    while( cin >> ch && ch != '#' ){
        cin >> str >> a >> b >> c >> d;

        MEM(val, 0);
        MEM(used, 0);
        s = a * 60 + b;
        t = c * 60 + d;

        if( t <= s ) t += 24 * 60;

        for( int i = s ; i < t ; ++i ) ++used[i % (24 * 60)];

        for( int i = 0 ; i < 4 ; ++i ){
            val[i] = 0;
            for( int j = section[i] ; j < section[i+1] ; ++j ) val[i] += used[j];
        }

        val[3] += val[0];
        double sum = val[1] * fax[ch-'A'][0] + val[2] * fax[ch-'A'][1] + val[3] * fax[ch-'A'][2];

        cout << setw(10) << setfill(' ') << right << str;
        cout << setw(6) << setfill(' ') << right << fixed << setprecision(0) << val[1];
        cout << setw(6) << setfill(' ') << right << fixed << setprecision(0) << val[2];
        cout << setw(6) << setfill(' ') << right << fixed << setprecision(0) << val[3];
        cout << setw(3) << setfill(' ') << right << ch;
        cout << setw(8) << setfill(' ') << right << fixed << setprecision(2) << sum << "\n";
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