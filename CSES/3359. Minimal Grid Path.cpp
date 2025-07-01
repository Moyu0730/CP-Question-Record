/* Question : CSES 3359. Minimal Grid Path */

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

/* Self Define Template Function */
template <typename T> void print(vector<T> _vector ) {
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
// const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1},  {-1, 0}, {0, -1}, 
//                                             {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
const int         MAXN = 3e3 + 50;
const int          Mod = 1e9 + 7;
const int          INF = 0x7FFFFFFF;
const ll         LLINF = 0x7FFFFFFFFFFFFFFF;
const int       MEMINF = 0x3F;
const int   MEMINF_VAL = 0x3F3F3F3F;
const ll  MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

bool used[MAXN][MAXN];
int n, cnt, pre;
string res, grid[MAXN];
queue<pii> q;

/*
 * DP DEFINITION 1 - Got RE
 * Define      | dp[i][j] = the result of (i, j)
 * Base        | dp[0][0] = grid[0][0]
 * Transition  | dp[i][j] = min(dp[i-1][j], dp[i][j-1]).pb(grid[i][j])
 * Code        | for( int i = 0 ; i < n ; ++i ){
 *             |    for( int j = 0 ; j < n ; ++j ){
 *             |    if( i != 0 && j != 0 ) dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
 *             |    else if( i != 0 ) dp[i][j] = dp[i-1][j];
 *             |    else if( j != 0 ) dp[i][j] = dp[i][j-1];
 *             |    
 *             |    dp[i][j].pb(grid[i][j]);
 *             |    }
 *             | }
 *             |    
 *             | cout << dp[n-1][n-1] << "\n";
 */

/*
 * DP DEFINITION 2 - Memory Optomized - Got TLE
 * Define      | dp[i][j] = i for the row index, j for pre or cnt
 * Base        | 
 * Transition  | 
 * Code        | for( int i = 0 ; i < n ; ++i ){
 *             |    cnt = i % 2;
 *             |    pre = !cnt;
 *             |
 *             |    for( int j = 0 ; j < n ; ++j ){    
 *             |        if( i != 0 && j != 0 ) dp[j][cnt] = min(dp[j-1][cnt], dp[j][pre]);
 *             |        else if( i != 0 ) dp[j][cnt] = dp[j][pre];
 *             |        else if( j != 0 ) dp[j][cnt] = dp[j-1][cnt];
 *             |        
 *             |        dp[j][cnt].pb(grid[i][j]);
 *             |    }
 *             | }
 * 
 *             |  cout << dp[n-1][cnt] << "\n";
 */

inline void solve(){
    cin >> n;

    for( int i = 0 ; i < n ; ++i ) cin >> grid[i];

    q.push({0, 0});
    res.pb(grid[0][0]);

    for( int step = 1 ; step < 2 * n - 1 ; ++step ){
        char Min = 'Z';
        queue<pii> nq;

        while( !q.empty() ){
            auto [i, j] = q.front();
            q.pop();

            if( j < n - 1 && !used[i][j + 1] ){
                char ch = grid[i][j + 1];

                if( ch < Min ){
                    Min = ch;
                    
                    while( !nq.empty() ) nq.pop();
                    
                    nq.push({i, j + 1});
                    used[i][j + 1] = true;
                }else if( ch == Min ){
                    nq.push({i, j + 1});
                    used[i][j + 1] = true;
                }
            }

            if( i < n - 1 && !used[i + 1][j] ){
                char ch = grid[i + 1][j];
                if( ch < Min ){
                    Min = ch;
                    
                    while( !nq.empty() ) nq.pop();

                    nq.push({i + 1, j});
                    used[i + 1][j] = true;
                }else if( ch == Min ){
                    nq.push({i + 1, j});
                    used[i + 1][j] = true;
                }
            }
        }

        res.pb(Min);
        q = nq;
    }

    cout << res << endl;
}

signed main(){
    IO;

    int T = 1;
    // cin >> T;
    while( T-- ){
        solve();
    }
} 