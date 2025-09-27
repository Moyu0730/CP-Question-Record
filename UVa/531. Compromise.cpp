/* Question : UVa 531. Compromise */

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
    bool flag = false;
    for( auto _it : _vector ){
        if( !flag ){
            flag = true;
            cout << _it;
        }else cout << " " << _it;
    }
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
const int         MAXN = 1e2 + 50;
const int          Mod = 1e9 + 7;
const int          INF = 0x7FFFFFFF;
const ll         LLINF = 0x7FFFFFFFFFFFFFFF;
const int       MEMINF = 0x3F;
const int   MEMINF_VAL = 0x3F3F3F3F;
const ll  MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int dp[MAXN][MAXN];
string str;
vc(string) a, b;

inline void solve(){
    while (true) {
        a.clear(); b.clear();

        if (!(cin >> str)) break;

        if (str != "#") a.pb(str);
        while (cin >> str && str != "#") a.pb(str);
        while( cin >> str && str != "#" ) b.pb(str);

        for( int i = 1 ; i <= a.sz ; ++i ){
            for( int j = 1 ; j <= b.sz ; ++j ){
                if( a[i-1] == b[j-1] ) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
            }
        }

        vc(string) res;
        pii cnt = {a.sz, b.sz};

        while( dp[cnt.F][cnt.S] != 0 ){
            if( a[cnt.F-1] == b[cnt.S-1] ){
                cnt = {cnt.F - 1, cnt.S - 1};
                res.pb(a[cnt.F]);
            }else{
                if( dp[cnt.F-1][cnt.S] > dp[cnt.F][cnt.S-1] ) cnt = {cnt.F - 1, cnt.S};
                else cnt = {cnt.F, cnt.S - 1};
            }
        }

        reverse(ALL(res));
        pV(res);
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