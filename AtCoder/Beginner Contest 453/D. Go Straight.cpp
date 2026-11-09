/* Question : AtCoder Beginner Contest 453 - D. Go Straight */

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
#define as assign
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

int h, w;
pii st;
bool used[MAXN][MAXN][4 + 5];
char grid[MAXN][MAXN], d[MAXN][MAXN];
map<char, int> mp;
map<int, char> rmp;
queue<pair<pii, char>> q;
string str;

inline bool dfs( pii cnt, char face, int counter ){
    if( counter > 5000000 ) return false;
    if( grid[cnt.F][cnt.S] == 'G' ) return true;

    for( int t = 0 ; t < 4 ; ++t ){
        pii nxt = { cnt.F + dir[t].F, cnt.S + dir[t].S };

        if( nxt.F < 0 || nxt.F >= h || nxt.S < 0 || nxt.S >= w ) continue;
        if( used[nxt.F][nxt.S][t] ) continue;
        if( grid[nxt.F][nxt.S] == '#' ) continue;
        if( grid[cnt.F][cnt.S] == 'o' && t != mp[face] ) continue;
        if( grid[cnt.F][cnt.S] == 'x' && t == mp[face] ) continue;

        used[nxt.F][nxt.S][t] = true;

        if( dfs(nxt, rmp[t], ++counter) ){
            str.pb(rmp[t]);
            return true;
        }
    }

    return false;
}

inline void solve(){
    cin >> h >> w;

    for( int i = 0 ; i < h ; ++i ){
        for( int j = 0 ; j < w ; ++j ){
            cin >> grid[i][j];

            if( grid[i][j] == 'S' ) st = {i, j};
        }
    }

    MEM(d, 'X');
    mp['D'] = 0; rmp[0] = 'D';
    mp['R'] = 1; rmp[1] = 'R';
    mp['U'] = 2; rmp[2] = 'U';
    mp['L'] = 3; rmp[3] = 'L';
    mp['X'] = 9; rmp[9] = 'X';

    if( !dfs(st, 'X', 0) ) cout << "No\n";
    else{
        reverse(ALL(str));
        cout << "Yes\n";
        cout << str << "\n";
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