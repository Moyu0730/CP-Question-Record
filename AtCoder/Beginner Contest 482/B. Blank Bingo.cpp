/* Question : AtCoder Beginner Contest 482 - B. Blank Bingo */

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
const int     MAXN = 5 + 50;
const int      Mod = 1e9 + 7;
const int      INF = 0x7FFFFFFF;
const int    LLINF = 0x7FFFFFFFFFFFFFFF;
const int MEMLLINF = 0x3F3F3F3F3F3F3F3F;

int res;
string grid[MAXN];

inline void solve(){
    for( int i = 0 ; i < 5 ; ++i ) cin >> grid[i];

    res = 10;
    for( int i = 0 ; i < 5 ; ++i ){
        for( int j = 0 ; j < 5 ; ++j ){
            if( i != 0 && j != 0 ) continue;

            int tmpv = 0, tmph = 0;
            for( int t = 0 ; t < 5 ; ++t ){
                if( i == 0 && grid[t][j] == '.' ) ++tmph;
                if( j == 0 && grid[i][t] == '.' ) ++tmpv;
            }

            if( i == 0 ) res = min(res, tmph);
            if( j == 0 ) res = min(res, tmpv);
        }
    }

    int tmpa = 0, tmpb = 0;
    for( int i = 0 ; i < 5 ; ++i ){
        if( grid[i][i] == '.' ) ++tmpa;
        if( grid[i][4-i] == '.' ) ++tmpb;
    }

    res = min({res, tmpa, tmpb});

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