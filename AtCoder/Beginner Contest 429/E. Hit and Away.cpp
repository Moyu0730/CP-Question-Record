/* Question : AtCoder Beginner Contest 429 - E. Hit and Away */

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

int n, m, u, v, dis[MAXN][2 + 5], src[MAXN][2 + 5];
vector<vector<int>> edge;
queue<tuple<int,int,int>> q;
string str;

inline void solve(){
    cin >> n >> m;

    edge.resize(n + 1);
    for( int i = 0 ; i < m ; ++i ){
        cin >> u >> v;

        edge[u].pb(v);
        edge[v].pb(u);
    }

    cin >> str;
    MEM(dis, MEMINF);
    MEM(src, 0);
    for( int i = 0 ; i < str.sz ; ++i ){
        if( str[i] == 'S' ){
            q.push({i+1, i+1, 1});
            dis[i+1][1] = 0;
            src[i+1][1] = i+1;
        }
    }

    while( !q.empty() ){
        auto [s, u, k] = q.front();
        q.pop();

        for( auto v : edge[u] ){
            int nd = dis[u][k] + 1;

            if( nd < dis[v][1] ){
                if( src[v][1] != 0 && src[v][1] != s ){
                    dis[v][2] = dis[v][1];
                    src[v][2] = src[v][1];
                    q.push({src[v][2], v, 2});
                }
                dis[v][1] = nd;
                src[v][1] = s;
                q.push({s, v, 1});
            }else if( s != src[v][1] && nd < dis[v][2] ){
                dis[v][2] = nd;
                src[v][2] = s;
                q.push({s, v, 2});
            }
        }
    }

    for( int i = 0 ; i < str.sz ; ++i ){
        if( str[i] == 'D' ) cout << dis[i+1][1] + dis[i+1][2] << "\n";
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