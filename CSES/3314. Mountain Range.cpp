/* Question : CSES 3314. Mountain Range */

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

int n, res, l[MAXN], r[MAXN], arr[MAXN], dp[MAXN];
stack<int> mono;

void dfs( int root ){
    if( l[root] == r[root] ){
        dp[root] = 1;
        return;
    }

    if( l[root] != root && dp[l[root]] == -1 ) dfs(l[root]);
    if( r[root] != root && dp[r[root]] == -1 ) dfs(r[root]);
    
    dp[root] = max(dp[l[root]] + 1, dp[r[root]] + 1);
    res = max(res, dp[root]);
    return;
}

inline void solve(){
    cin >> n;

    for( int i = 0 ; i < n ; ++i ) cin >> arr[i];

    for( int i = 0 ; i < n ; ++i ){
        while( !mono.empty() && arr[mono.top()] <= arr[i] ) mono.pop();
        
        if( mono.empty() ){
            mono.push(i);
            l[i] = i;
        }else{
            l[i] = mono.top();
            mono.push(i);
        }
    }

    while( !mono.empty() ) mono.pop();

    for( int i = n-1 ; i >= 0 ; --i ){
        while( !mono.empty() && arr[mono.top()] <= arr[i] ) mono.pop();
        
        if( mono.empty() ){
            mono.push(i);
            r[i] = i;
        }else{
            r[i] = mono.top();
            mono.push(i);
        }
    }
    
    MEM(dp, -1);
    res = 1;
    for( int i = 0 ; i < n ; ++i ){
        if( dp[i] == -1 ) dfs(i);
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