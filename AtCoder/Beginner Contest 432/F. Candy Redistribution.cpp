/* Question : AtCoder Beginner Contest 432 - F. Candy Redistribution */

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
const int         MAXN = 1e7 + 50;
const int          Mod = 1e9 + 7;
const int          INF = 0x7FFFFFFF;
const ll         LLINF = 0x7FFFFFFFFFFFFFFF;
const int       MEMINF = 0x3F;
const int   MEMINF_VAL = 0x3F3F3F3F;
const ll  MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int n, sum, arr[MAXN], dp[MAXN], dprev[MAXN], subsum[MAXN];

inline void solve(){
    cin >> n;

    for( int i = 0 ; i < n ; ++i ){
        cin >> arr[i];
        sum += arr[i];
    }

    if( sum % n != 0 ){
		cout << "-1" << "\n";
		return;
	}

    for( int i = 0 ; i < n ; ++i ) arr[i] -= sum / n;
    
    dp[0] = 0;
    for( int i = 1 ; i < (1<<n) ; ++i ){
        dp[i] = n + 1;
        subsum[i] = 0;

        for( int j = 0 ; j < n ; ++j ){
            if( i & (1<<j) ) subsum[i] += arr[j];
        }

        int flag = subsum[i] == 0 ? 0 : 1;
        for( int j = 0 ; j < n ; ++j ){
            if( i & (1<<j) ){
                if( dp[i] > dp[i^(1<<j)] + flag ){
                    dp[i] = dp[i^(1<<j)] + flag;
                    dprev[i] = j;
                }
            }
        }
    }

    stringstream sst{};
    int counter{};
    int cnt = (1<<n) - 1;
    while( cnt ){
        vector<pii> sep;

        do{
            int nxt = dprev[cnt];
            sep.pb({arr[nxt], nxt});
            cnt ^= 1<<nxt;
        }while( subsum[cnt] );

        sort(ALL(sep));

        while( sep.sz > 1 ){
            pii fst = sep.back();
            sep.pop_back();
            pii sec = sep.back();
            sep.pop_back();
            counter++;
            sst << fst.S + 1 << " " << sec.S + 1 << " " << fst.F << "\n";
            sep.pb({fst.F + sec.F, sec.S});
        }
    }
    cout << counter << '\n';
    string str;
    while(getline(sst, str)) cout << str << '\n';
}

signed main(){
    IO;

    int T = 1;
    // cin >> T;
    while( T-- ){
        solve();
    }
}