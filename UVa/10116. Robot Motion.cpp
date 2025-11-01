/* Question : UVa 10116. Robot Motion */

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
                                        //  S       E        N        W
const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1},  {-1, 0}, {0, -1}, 
                                            {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
const int         MAXN = 1e0 + 50;
const int          Mod = 1e9 + 7;
const int          INF = 0x7FFFFFFF;
const ll         LLINF = 0x7FFFFFFFFFFFFFFF;
const int       MEMINF = 0x3F;
const int   MEMINF_VAL = 0x3F3F3F3F;
const ll  MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int n, m, now, dis[MAXN][MAXN];
map<char, int> mp;
string grid[MAXN];

void dfs( pii cnt ){
    pii nxt = { cnt.F + dir[mp[grid[cnt.F][cnt.S]]].F,  cnt.S + dir[mp[grid[cnt.F][cnt.S]]].S };

    if( nxt.F < 0 || nxt.F >= n || nxt.S < 0 || nxt.S >= m ){
        cout << dis[cnt.F][cnt.S] << " step(s) to exit\n";
        return;
    }else if( dis[nxt.F][nxt.S] != 0 ){
        cout << dis[nxt.F][nxt.S] - 1 << " step(s) before a loop of " << dis[cnt.F][cnt.S] - dis[nxt.F][nxt.S] + 1 << " step(s)\n";
        return;
    }else{
        dis[nxt.F][nxt.S] = dis[cnt.F][cnt.S] + 1;
        dfs(nxt);
    }
}

inline void solve(){
    mp['S'] = 0;
    mp['E'] = 1;
    mp['N'] = 2;
    mp['W'] = 3;

    while( cin >> n >> m >> now && ( n || m || now ) ){
        for( int i = 0 ; i < n ; ++i ) cin >> grid[i];
    
        MEM(dis, 0);
        dis[0][now-1] = 1;
        dfs({0, now-1});
    }
}

signed main(){
    // IO;

    int T = 1;
    // cin >> T;
    while( T-- ){
        solve();
    }
}