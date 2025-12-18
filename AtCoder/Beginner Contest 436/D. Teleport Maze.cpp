/* Question : AtCoder Beginner Contest 436 - D. Teleport Maze */

#include<bits/stdc++.h>
using namespace std;

/* Pragma */
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

/* Self Define */
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MEM(_A, _V) memset(_A, _V, sizeof(_A))
#define ALL(_A) _A.begin(), _A.end()
#define LB(_A, _V) lower_bound(ALL(_A), _V)
#define UB(_A, _V) upper_bound(ALL(_A), _V)
#define pii pair<int, int>
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

int n, m, dis[MAXN][MAXN];
char grid[MAXN][MAXN];
bool used[MAXN];
vector<vector<pii>> tep;

int d( pii x, pii y = {n-1, m-1} ){
    return abs(x.F - y.F) + abs(x.S - y.S);
}

bool cmp( pii x, pii y ){
    return d(x) < d(y);
}

inline void solve(){
    cin >> n >> m;

    tep.rz('z' + 5);
    for( int i = 0 ; i < n ; ++i ){
        for( int j = 0 ; j < m ; ++j ){
            cin >> grid[i][j];

            if( isalpha(grid[i][j]) ) tep[grid[i][j]].pb({i, j});
        }
    }

    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
    MEM(dis, 0x3F);
    MEM(used, false);
    dis[0][0] = 0;
    pq.push({0, {0, 0}});
    while( !pq.empty() ){
        auto [dist, cnt] = pq.top();
        char ch = grid[cnt.F][cnt.S];
        pq.pop();

        if( cnt == make_pair(n-1, m-1) ) break;

        if( isalpha(ch) && tep[ch].sz != 1 && !used[ch] ){
            for( auto nxt : tep[ch] ){
                if( dis[nxt.F][nxt.S] > dis[cnt.F][cnt.S] + 1 ){
                    // cout << cnt << " teleport to " << nxt << "\n";

                    dis[nxt.F][nxt.S] = dis[cnt.F][cnt.S] + 1;
                    pq.push({dis[nxt.F][nxt.S], nxt});
                }
            }

            used[ch] = true;
        }

        for( int t = 0 ; t < 4 ; ++t ){
            pii nxt = {cnt.F + dir[t].F, cnt.S + dir[t].S };

            if( nxt.F < 0 || nxt.F >= n || nxt.S < 0 || nxt.S >= m ) continue;
            if( grid[nxt.F][nxt.S] == '#' ) continue;
            if( dis[nxt.F][nxt.S] <= dis[cnt.F][cnt.S] + 1 ) continue;

            dis[nxt.F][nxt.S] = dis[cnt.F][cnt.S] + 1;
            pq.push({dis[nxt.F][nxt.S], nxt});
        }
    }

    if( dis[n-1][m-1] == dis[MAXN-1][MAXN-1] ) cout << "-1\n";
    else cout << dis[n-1][m-1] << "\n";
}

signed main(){
    // IO;

    int T = 1;
    // cin >> T;
    while( T-- ){
        solve();
    }
}