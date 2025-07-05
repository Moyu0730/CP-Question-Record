/* Question : CSES 1694. Download Speed */

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
const int         MAXN = 5e2 + 50;
const int          Mod = 1e9 + 7;
const int          INF = 0x7FFFFFFF;
const ll         LLINF = 0x7FFFFFFFFFFFFFFF;
const int       MEMINF = 0x3F;
const int   MEMINF_VAL = 0x3F3F3F3F;
const ll  MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

struct DINIC {
    struct EDGE {
        int v, flow, rev; // rev is the pos in reverse edge
    };

    int n, s, t, level[MAXN];
    vector<EDGE> edge[MAXN];

    DINIC( int _n, int _s, int _t ){
        n = _n, s = _s, t = _t;
        for( int i = 0 ; i < n ; i++ ) edge[i].clear();
    }

    void add_edge( int u, int v, int w ){
        edge[u].pb({v, w, (int)edge[v].sz});
        edge[v].pb({u, 0, (int)edge[u].sz - 1});
    }

    bool bfs(){
        MEM(level, -1);
        queue<int> q;
        q.push(s);
        level[s] = 0;
        while( !q.empty() ){
            int cnt = q.front();
            q.pop();
            for( auto i : edge[cnt] ){
                if( i.flow > 0 && level[i.v] == -1 ){
                    level[i.v] = level[cnt] + 1;
                    q.push(i.v);
                }
            }
        }

        return level[t] != -1;
    }

    int dfs( int cnt, int remFlow ){
        if( cnt == t ) return remFlow;
        int res = 0;
        
        for( auto &i : edge[cnt] ){
            if( i.flow > 0 && level[i.v] == level[cnt] + 1 ){
                int blockFlow = dfs(i.v, min(remFlow, i.flow));
                res += blockFlow, remFlow -= blockFlow, i.flow -= blockFlow;
                edge[i.v][i.rev].flow += blockFlow;
                if( remFlow == 0 ) return res;
            }
        }

        if( !res ) level[cnt] = -1;
        return res;
    }

    int flow( int res = 0 ){
        while( bfs() ) res += dfs( s, INF );

        return res;
    }
};

int n, u, v, w, m;

inline void solve(){
    cin >> n >> m;
    
    DINIC dinic(n, 0, n-1);

    for( int i = 0 ; i < m ; ++i ){
        cin >> u >> v >> w;

        dinic.add_edge(u-1, v-1, w);
    }

    cout << dinic.flow() << "\n";
}

signed main(){
    // IO;

    int T = 1;
    // cin >> T;
    while( T-- ){
        solve();
    }
}