/* Question : CSES 1678. Round Trip II */
 
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
#define sz size()
#define LB(_array, v) lower_bound(ALL(_array), v)
#define UB(_array, v) upper_bound(ALL(_array), v)
#define RVS(_vector) reverse(ALL(_vector))
#define vc(_data) vector<_data>
#define pii pair<int, int>
#define pdd pair<double, double>
#define mkp make_pair
#define pb emplace_back
#define F first
#define S second
#define int long long
#define ll long long
 
/* Self Define Template Function */
template <typename T> void pV(vector<T> _vector ) { 
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
const int         MAXN = 1e5 + 50;
const int          Mod = 1e9 + 7;
const int          INF = 0x7FFFFFFF;
const ll         LLINF = 0x7FFFFFFFFFFFFFFF;
const int       MEMINF = 0x3F;
const int   MEMINF_VAL = 0x3F3F3F3F;
const ll  MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;
 
int n, m, a, b, start, timer, t[MAXN], to[MAXN];
bool valid[MAXN];
vc(vc(int)) edge;
vc(int) res;
 
bool dfs( int root ){
    for( auto i : edge[root] ){
        if( t[i] == t[root] ){
            to[root] = i;

            if( t[to[i]] != t[root] || valid[i] == false ){
                valid[root] = false;
                continue;
            }
            
            start = root;
            return true;
        }
        if( t[i] != -1 ) continue;

        t[i] = t[root];
        to[root] = i;
        if( dfs(i) ) return true;
    }

    valid[root] = false;
    return false;
}
 
inline void solve(){
    cin >> n >> m;
 
    edge.resize(n + 5);
    for( int i = 0 ; i < m ; ++i ){
        cin >> a >> b;
 
        edge[a].pb(b);
    }
 
    MEM(t, -1);
    MEM(valid, true);
    for( int i = 1 ; i <= n ; ++i ){
        if( t[i] == -1 ){
            t[i] = ++timer;
            dfs(i);
        }
    }
 
    if( start == 0 ) cout << "IMPOSSIBLE\n";
    else{
        res.pb(start);
        for( int i = to[start] ; i != start ; i = to[i] ) res.pb(i);
        res.pb(start);

        cout << res.sz << "\n";
        pV(res);
    }
 
    return;
}
 
signed main(){
    IO;
 
    int T = 1;
    // cin >> T;
    while( T-- ){
        solve();
    }
}