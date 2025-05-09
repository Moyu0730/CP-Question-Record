/* Question : CESE 2220. Counting Numbers */

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
#define VC(_data) vector<_data>
#define pii pair<int, int>
#define pdd pair<double, double>
#define mkp make_pair
#define pb emplace_back
#define SZ size()
#define F first
#define S second
#define int long long
#define ll long long
#define PAUSE system("pause")

/* Self Define Template Function */
template <typename T> void AUTOV(vector<T> _vector ) { 
    for( auto _it : _vector ) cout << _it << " ";
    cout << "\n";
}

template <typename A, typename B> bool boundry( pair<A, B> &_pair, int _n, int _m ){ 
    return 1 <= _pair.F && _pair.F <= _n && 1 <= _pair.S && _pair.S <= _m;
}

template <typename A, typename B> istream& operator>>( istream& _is, pair<A, B> &_pair ){ 
    return _is >> _pair.X >> _pair.Y;
}

template <typename A, typename B> ostream& operator<<( ostream& _os, pair<A, B> _pair ){ 
    return _os << '(' << _pair.X << ", " << _pair.Y << ')';
}

/* Self Define Const */
const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1},  {-1, 0}, {0, -1}, 
                                            {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
const int         MAXN = 20 + 50;
const int          Mod = 1e9 + 7;
const int          INF = 0x7FFFFFFF;
const ll         LLINF = 0x7FFFFFFFFFFFFFFF;
const int       MEMINF = 0x3F;
const int   MEMINF_VAL = 0x3F3F3F3F;
const ll  MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int a, b, na, nb;
string sa, sb;
int arr[MAXN], dp[MAXN][10 + 5][2][2];

int get( int idx, int pre, int leading, int tight ){
    if( idx < 0 ) return 1;

    if( pre != -1 && dp[idx][pre][leading][tight] != -1 ) return dp[idx][pre][leading][tight];
    int limit = tight ? arr[idx] : 9;

    dp[idx][pre][leading][tight] = 0;
    for( int i = 0 ; i <= limit ; ++i ){
       if( !leading && i == pre ) continue;
       if( tight && i > limit ) break;

        if( leading && i == 0 ) dp[idx][pre][leading][tight] += get(idx-1, i, true, false);
        else if( tight && i == limit ) dp[idx][pre][leading][tight] += get(idx-1, i, false, true);
        else dp[idx][pre][leading][tight] += get(idx-1, i, false, false);
    }

    return dp[idx][pre][leading][tight];
}

inline void solve(){
    cin >> a >> b;

    sa = a == 0 ? "0" : to_string(a-1);
    for( int i = sa.SZ - 1 ; i >= 0 ; --i ) arr[i] = sa[sa.SZ - 1 - i] - '0';

    MEM(dp, -1);

    na = a == 0 ? 0 : get(sa.SZ - 1, -1, true, true);

    sb = to_string(b);
    for( int i = sb.SZ - 1 ; i >= 0 ; --i ) arr[i] = sb[sb.SZ - 1 - i] - '0';

    MEM(dp, -1);
    nb = get(sb.SZ - 1, -1, true, true);
    cout << nb - na << "\n";
}

signed main(){ 
    IO;

    int T = 1;
    // cin >> T;
    while( T-- ){
        solve();
    }
}