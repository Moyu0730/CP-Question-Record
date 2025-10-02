/* Question : UVa 497. Strategic Defense Initiative */

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
const int         MAXN = 1e7 + 50;
const int          Mod = 1e9 + 7;
const int          INF = 0x7FFFFFFF;
const ll         LLINF = 0x7FFFFFFFFFFFFFFF;
const int       MEMINF = 0x3F;
const int   MEMINF_VAL = 0x3F3F3F3F;
const ll  MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int counter, len;
string str;
vector<int> arr, dp, last;

int tran(){
    int num = 0;
    for( int i = 0 ; i < str.sz ; ++i ){
        num *= 10;
        num += str[i] - '0';
    }

    return num;
}

inline void solve(){
    arr.clear();
    len = -1;

    while( getline(cin, str) && str != "" ) arr.pb(tran());

    dp.resize(arr.sz, 1);
    last.resize(arr.sz, -1);

    for( int i = 0 ; i < arr.sz ; ++i ){
        for( int j = 0 ; j < i ; ++j ){
            if( arr[j] < arr[i] ){
                if( dp[i] < dp[j] + 1 ){
                    dp[i] = dp[j] + 1;
                    last[i] = j;
                } 
            }
        }
    }

    if( counter++ > 0 ) cout << "\n";

    int len = 0, idx;
    for( int i = 0 ; i < dp.sz ; ++i ){
        if( dp[i] > len ){
            len = dp[i];
            idx = i;
        }
    }

    cout << "Max hits: " << len << "\n";
    
    int cnt = last[idx];
    vector<int> ans;
    ans.pb(arr[idx]);
    while( cnt != -1 ){
        ans.pb(arr[cnt]);
        cnt = last[cnt];
    }

    reverse(ALL(ans));
    for( auto i : ans ) cout << i << "\n";
}

signed main(){
    IO;

    int T = 1;
    
    getline(cin, str);
    T = tran();
    getline(cin, str);

    while( T-- ){
        solve();
    }
}