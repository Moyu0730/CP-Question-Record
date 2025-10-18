/* Question : UVa 11987. Almost Union-Find */

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
const int         MAXN = 1e5 + 50;
const int          Mod = 1e9 + 7;
const int          INF = 0x7FFFFFFF;
const ll         LLINF = 0x7FFFFFFFFFFFFFFF;
const int       MEMINF = 0x3F;
const int   MEMINF_VAL = 0x3F3F3F3F;
const ll  MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int n, m, tp, a, b;

struct Node {
    int fa, size, sum;
};

vector<Node> ARRAY;

template<tpn T> struct DSU {
    DSU(){
        for( T i = 1 ; i <= n ; ++i ){
            ARRAY[i].fa = i;
            ARRAY[i].size = 1;
            ARRAY[i].sum = i;
        }
    }
    T size( T a ){ return ARRAY[query(a)].size; }
    T sum( T a ){ return ARRAY[query(a)].sum; }
    T query( T a ){ return ARRAY[a].fa = ARRAY[a].fa == a ? a : query(ARRAY[a].fa); }
    void comb( T a, T b ){
        T faa = query(a);
        T fab = query(b);

        if( faa != fab ){
            Node tmp;
            tmp.fa = ARRAY.sz;
            tmp.size = ARRAY[faa].size + ARRAY[fab].size;
            tmp.sum = ARRAY[faa].sum + ARRAY[fab].sum;

            ARRAY[faa].fa = tmp.fa;
            ARRAY[fab].fa = tmp.fa;

            ARRAY.pb(tmp);
        }

        return;
    }
};

inline void solve(){
    while( cin >> n >> m ){
        ARRAY.clear();
        ARRAY.resize(n+1);
        DSU<int> dsu;

        while( m-- ){
            cin >> tp;

            if( tp == 1 ){
                cin >> a >> b;

                dsu.comb(a, b);
            }else if( tp == 2 ){
                cin >> a >> b;

                int faa = dsu.query(a);
                int fab = dsu.query(b);

                if( dsu.query(a) != dsu.query(b) ){
                    Node tmp;
                    tmp.fa = ARRAY.sz;
                    tmp.size = ARRAY[faa].size - 1;
                    tmp.sum = ARRAY[faa].sum - a;
                    ARRAY.pb(tmp);

                    ARRAY[faa].fa = tmp.fa;
                    ARRAY[a].fa = a;
                    ARRAY[a].size = 1;
                    ARRAY[a].sum = a;

                    dsu.comb(a, b);
                }
            }else{
                cin >> a;
                cout << dsu.size(a) << " " << dsu.sum(a) << "\n";
            }
        }
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