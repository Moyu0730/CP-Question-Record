/* Question : Luogu P12385.【Blue Bridge Cup 2023 Provincial Python B】XOR Sum */

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
const int         MAXN = 1e5 + 50;
const int          Mod = 1e9 + 7;
const int          INF = 0x7FFFFFFF;
const ll         LLINF = 0x7FFFFFFFFFFFFFFF;
const int       MEMINF = 0x3F;
const int   MEMINF_VAL = 0x3F3F3F3F;
const ll  MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int n, q, u, v, op, x, y, timer, tsz[MAXN], pos[MAXN], arr[MAXN];
vc(vc(int)) edge;

void treeflat( int cnt, int fa ){ 
    pos[cnt] = ++timer; 
    tsz[cnt] = 1; 
    for( auto i : edge[cnt] ){ 
        if( i == fa ) continue; 
        treeflat(i, cnt); 
        tsz[cnt] += tsz[i];
    } 
}

template<tpn T> struct BIT {
    T ARR[MAXN];
    BIT(){ 
        clear();
        init();
    }
    int lowbit( int x ){ return x & -x; }

    T query( int pos ){
        T ans = 0;
        while( pos ){
            ans ^= ARR[pos];
            pos -= lowbit(pos);
        }
        return ans;
    }

    void init(){
        for( int i = 1 ; i <= n ; ++i ){
            int cnt = pos[i];
            while( cnt < MAXN ){
                ARR[cnt] ^= arr[i];
                cnt += lowbit(cnt);
            }
        }
    }

    void update( int old, int x, T val ){
        int tmp = arr[old];
        arr[old] = val;
        while( x < MAXN ){
            ARR[x] ^= tmp;
            ARR[x] ^= val;
            x += lowbit(x);
        }
    }

    T get( int l, int r ){
        if( l > r ) return 0;
        return query(r) ^ query(l - 1);
    }
    T LowerB( T val ){ // lower_bound by sum
        T res = 0, step = MAXN - 1;
        while( step != 0 ){
            if( query(res + step) >= val ) step /= 2;
            else res += step;
        }
        return res + 1;
    }
    void clear(){ MEM(ARR, 0); }
};

inline void solve(){
    cin >> n >> q;

    for( int i = 1 ; i <= n ; ++i ) cin >> arr[i];

    edge.resize(n+5);
    for( int i = 0 ; i < n - 1 ; ++i ){
        cin >> u >> v;

        edge[u].pb(v);
        edge[v].pb(u);
    }

    treeflat(1, -1);
    BIT<int> bit;

    // cout << "----------\n";
    // cout << "IDX : ";
    // for( int i = 1 ; i <= n ; ++i ) cout << i << " ";
    // cout << "\n";

    // cout << "POS : ";
    // for( int i = 1 ; i <= n ; ++i ) cout << pos[i] << " ";
    // cout << "\n";

    // cout << "TSZ : ";
    // for( int i = 1 ; i <= n ; ++i ) cout << tsz[i] << " ";
    // cout << "\n";

    // cout << "BIT : ";
    // for( int i = 1 ; i <= n ; ++i ) cout << bit.query(pos[i]) << " ";
    // cout << "\n";

    while( q-- ){
        cin >> op;

        if( op == 1 ){
            cin >> x >> y;
            bit.update(x, pos[x], y);
        }else{
            cin >> x;
            cout << bit.get(pos[x], pos[x] + tsz[x] - 1) << "\n";
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