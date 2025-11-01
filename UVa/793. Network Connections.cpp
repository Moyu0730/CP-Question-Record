/* Question : UVa 793. Network Connections */

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
const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1},  {-1, 0}, {0, -1}, 
                                            {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
const int         MAXN = 3e4 + 50;
const int          Mod = 1e9 + 7;
const int          INF = 0x7FFFFFFF;
const ll         LLINF = 0x7FFFFFFFFFFFFFFF;
const int       MEMINF = 0x3F;
const int   MEMINF_VAL = 0x3F3F3F3F;
const ll  MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int counter, n, u, v, succ, fail;
char op;
string str;
stringstream ss;

struct Node {
    int fa, size;
} ARRAY[MAXN];

template<tpn T> struct DSU {
    DSU(){
        for( T i = 0 ; i <= n ; ++i ){
            ARRAY[i].fa = i;
            ARRAY[i].size = 1;
        }
    }
    T SZ( T a ){ return ARRAY[a].size; }
    T query( T a ){ return ARRAY[a].fa == a ? a : query(ARRAY[a].fa); }
    void comb( T a, T b ){
        T faa = query(a);
        T fab = query(b);

        if( faa != fab ){
            if( faa > fab ) swap(faa, fab);
            
            ARRAY[fab].fa = faa;
            ARRAY[faa].size += ARRAY[fab].size;
        }

        return;
    }
};

inline void solve(){
    getline(cin, str);
    ss.clear();
    ss.str(str);
    ss >> n;

    DSU<int> dsu;
    succ = 0, fail = 0;
    while( getline(cin, str) && str != "" ){
        ss.clear();
        ss.str(str);
        ss >> op >> u >> v;

        if( op == 'c' ) dsu.comb(u, v);
        else{
            if( dsu.query(u) == dsu.query(v) ) ++succ;
            else ++fail;
        }
    }
    
    if( counter++ > 0 ) cout << "\n";

    cout << succ << "," << fail << "\n";
}

signed main(){
    IO;

    int T = 1;
    getline(cin, str);
    ss.clear();
    ss.str(str);
    ss >> T;

    getline(cin, str);
    while( T-- ){
        solve();
    }
}