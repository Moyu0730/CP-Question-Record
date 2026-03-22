/* Question : AtCoder Beginner Contest 450 - C. Puddles */

#include<bits/stdc++.h>
using namespace std;

/* Pragma */
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

/* Self Define */
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MEM(_A, _V) memset(_A, _V, sizeof(_A))
#define ALL(_A) _A.begin(), _A.end()
#define LB(_A, _V) lower_bound(ALL(_A), _V)
#define UB(_A, _V) upper_bound(ALL(_A), _V)
#define pii pair<int, int>
#define az assign
#define sz size()
#define cr clear()
#define rz resize
#define pb push_back
#define F first
#define S second
#define int long long
#define tpn typename

/* Self Define Template Function */
template<tpn T> void pV( vector<T> _A ){
    for( auto _I : _A ) cout << _I << " ";
    cout << "\n";
}

template<tpn A, tpn B> ostream& operator<<( ostream& _OS, pair<A, B> _P ){
    return _OS << "(" << _P.F << ", " << _P.S << ")";
}

/* Self Define Const */
const auto dir = vector<pii> { {1, 0}, {0, 1},  {-1, 0}, {0, -1},
                               {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
const int     MAXN = 1e3 + 50;
const int      Mod = 1e9 + 7;
const int      INF = 0x7FFFFFFF;
const int    LLINF = 0x7FFFFFFFFFFFFFFF;
const int MEMLLINF = 0x3F3F3F3F3F3F3F3F;

int res, h, w;
char grid[MAXN][MAXN];
bool flag, visited[MAXN][MAXN];
queue<pii> q;

inline void solve(){
    cin >> h >> w;

    for( int i = 1 ; i <= h ; ++i ){
        for( int j = 1 ; j <= w ; ++j ) cin >> grid[i][j];
    }

    MEM(visited, false);

    for( int i = 1 ; i <= h ; ++i ){
        for( int j = 1 ; j <= w ; ++j ){
            if( visited[i][j] || grid[i][j] == '#' ) continue;
            
            q.push({i, j});
            visited[i][j] = true;
            if( i == 1 || i == h || j == 1 || j == w ) flag = true;
            else flag = false;
            ++res;

            while( !q.empty() ){
                pii cnt = q.front();
                q.pop();

                for( int t = 0 ; t < 4 ; ++t ){
                    pii nxt = { cnt.F + dir[t].F, cnt.S + dir[t].S };

                    if( visited[nxt.F][nxt.S] ) continue;
                    if( grid[nxt.F][nxt.S] == '#' ) continue;
                    if( nxt.F <= 0 || nxt.F > h || nxt.S <= 0 || nxt.S > w ) continue;

                    if( nxt.F == 1 || nxt.F == h || nxt.S == 1 || nxt.S == w ) flag = true;

                    visited[nxt.F][nxt.S] = true;
                    q.push(nxt);
                }
            }

            if( flag ) --res;
        }
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