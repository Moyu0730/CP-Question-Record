/* Question : AtCoder Beginner Contest 431 - E. Reflection on Grid */

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
#define pb push_back
#define F first
#define S second
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
    return _pair.F <= 0 || _pair.F > _n || _pair.S <= 0 || _pair.S > _m;
}

template <typename A, typename B> istream& operator>>( istream& _is, pair<A, B> &_pair ){ 
    return _is >> _pair.F >> _pair.S;
}

template <typename A, typename B> ostream& operator<<( ostream& _os, pair<A, B> _pair ){ 
    return _os << '(' << _pair.F << " " << _pair.S << ')';
}

/* Self Define Const */
const auto dir = vector<pii> { {0, 1}, {-1, 0}, {0, -1}, {1, 0} };
const int         MAXN = 2e5 + 50;
const int          Mod = 1e9 + 7;
const int          INF = 0x7FFFFFFF;
const ll         LLINF = 0x7FFFFFFFFFFFFFFF;
const int       MEMINF = 0x3F;
const int   MEMINF_VAL = 0x3F3F3F3F;
const ll  MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int h, w;
map<char, int> mp;

struct Node {
    pii pt;
    int face, cost;
};

/*     3
 *  0 | | 2
 *     1
 */

inline void solve(){
    cin >> h >> w;

    vc(vc(char)) grid;
    vc(vc(vc(int))) dis;
    grid.resize(h + 5);
    dis.resize(h + 5);
    for( int i = 1 ; i <= h ; ++i ){
        grid[i].resize(w + 5);
        dis[i].resize(w + 5);
        dis[i][0].resize(4, LLINF);
        for( int j = 1 ; j <= w ; ++j ){
            dis[i][j].resize(4, LLINF);
            cin >> grid[i][j];
        }
    }

    deque<Node> dq;
    dq.pb(Node{{1, 0}, 0, 0});
    dis[1][0][0] = 0;
    while( !dq.empty() ){
        Node pre = dq.front();
        dq.pop_front();

        Node cnt;
        cnt.pt = { pre.pt.F + dir[pre.face].F, pre.pt.S + dir[pre.face].S };

        if( boundry(cnt.pt, h, w) ) continue;

        for( int t = 0 ; t <= 3 ; ++t ){
            cnt.face = t;
            if( (pre.face ^ t) == 2 ) continue;
            if( (pre.face ^ t) == mp[grid[cnt.pt.F][cnt.pt.S]] ){
                if( pre.cost >= dis[cnt.pt.F][cnt.pt.S][cnt.face] ) continue;

                dis[cnt.pt.F][cnt.pt.S][cnt.face] = pre.cost;
                cnt.cost = pre.cost;
                dq.push_front(cnt);
            }else{
                if( pre.cost + 1 >= dis[cnt.pt.F][cnt.pt.S][cnt.face] ) continue;

                dis[cnt.pt.F][cnt.pt.S][cnt.face] = pre.cost + 1;
                cnt.cost = pre.cost + 1;
                dq.pb(cnt);
            }
        }
    }

    cout << dis[h][w][0] << "\n";
}

signed main(){
    IO;

    int T = 1;
    cin >> T;

    mp['A'] = 0;
    mp['B'] = 3;
    mp['C'] = 1;
    while( T-- ){
        solve();
    }
}