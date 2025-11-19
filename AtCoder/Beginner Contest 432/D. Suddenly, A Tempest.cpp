/* Question : AtCoder Beginner Contest 432 - D. Suddenly, A Tempest */

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
#define X first
#define Y second
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
    return _os << '(' << _pair.F << ", " << _pair.S << ')';
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

int n, x, y, a, b;
char tp;
set<pair<pii, pii>> st, tmp_st;
vector<pair<pii, pii>> vst;

struct Node {
    int fa, size;
} ARRAY[MAXN];

template<tpn T> struct DSU {
    DSU(){
        for( T i = 0 ; i < vst.sz ; ++i ){
            ARRAY[i].fa = i;
            ARRAY[i].size = ( vst[i].S.F - vst[i].F.F ) * ( vst[i].S.S - vst[i].F.S );
        }
    }
    T SZ( T ask ){ return ARRAY[query(ask)].size; }
    T query( T ask ){ return ARRAY[ask].fa == ask ? ask : query(ARRAY[ask].fa); }
    void comb( T ask, T askb ){
        T faa = query(ask);
        T fab = query(askb);

        if( faa != fab ){
            if( faa > fab ) swap(faa, fab);
            
            ARRAY[fab].fa = faa;
            ARRAY[faa].size += ARRAY[fab].size;
        }

        return;
    }
};

inline void solve(){
    cin >> n >> x >> y;

    st.insert({{0, 0}, {x, y}});

    for( int i = 0 ; i < n ; ++i ){
        cin >> tp >> a >> b;

        tmp_st.clear();
        if( tp == 'X' ){
            for( auto [lb, rt] : st ){
                if( lb.X < a && rt.X > a ){
                    tmp_st.insert({{lb.X, lb.Y - b}, {a, rt.Y - b}});
                    tmp_st.insert({{a, lb.Y + b}, {rt.X, rt.Y + b}});
                }else{
                    if( lb.X < a ) tmp_st.insert({{lb.X, lb.Y - b}, {rt.X, rt.Y - b}});
                    else tmp_st.insert({{lb.X, lb.Y + b}, {rt.X, rt.Y + b}});
                }
            }
        }else{
            for( auto [lb, rt] : st ){
                if( lb.Y < a && rt.Y > a ){
                    tmp_st.insert({{lb.X - b, lb.Y}, {rt.X - b, a}});
                    tmp_st.insert({{lb.X + b, a}, {rt.X + b, rt.Y}});
                }else{
                    if( lb.Y < a ) tmp_st.insert({{lb.X - b, lb.Y}, {rt.X - b, rt.Y}});
                    else tmp_st.insert({{lb.X + b, lb.Y}, {rt.X + b, rt.Y}});
                }
            }
        }
        
        swap(st, tmp_st);
    }

    for( auto i : st ) vst.pb(i);
    
    DSU<int> dsu;
    for( int i = 0 ; i < vst.sz ; ++i ){
        auto [lb, rt] = vst[i];
        for( int j = i + 1 ; j < vst.sz ; ++j ){
            auto [nlb, nrt] = vst[j];

            if( rt.X == nlb.X || nrt.X == nlb.X ){
                if( max(lb.Y, nlb.Y) < min(rt.Y, nrt.Y) ) dsu.comb(i, j);
            }else if( rt.Y == nlb.Y || lb.Y == nrt.Y ){
                if( max(lb.X, nlb.X) < min(rt.X, nrt.X) ) dsu.comb(i, j);
            }
        }
    }

    set<pii> res;

    for( int i = 0 ; i < vst.sz ; ++i ){
        res.insert({dsu.SZ(i), dsu.query(i)});
    }

    cout << res.sz << "\n";
    for( auto i : res ) cout << i.F << " ";
    cout << "\n";
}

signed main(){
    IO;

    int T = 1;
    // cin >> T;
    while( T-- ){
        solve();
    }
}