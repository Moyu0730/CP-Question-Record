/* Question : AtCoder Beginner Contest 429 - D. On AtCoder Conference */

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
const int         MAXN = 1e7 + 50;
const int          Mod = 1e9 + 7;
const int          INF = 0x7FFFFFFF;
const ll         LLINF = 0x7FFFFFFFFFFFFFFF;
const int       MEMINF = 0x3F;
const int   MEMINF_VAL = 0x3F3F3F3F;
const ll  MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int n, m, c, res, cnt, acc;
int tmp[MAXN], pos[MAXN]; 
vc(int) arr, pfx, dst;

void discretization(){
    sort(tmp, tmp + n);

    dst.pb(tmp[0]);
    for( int i = 1 ; i < n ; i++ ){
        if( tmp[i] != tmp[i-1] ) dst.pb(tmp[i]);
    }

    for( int i = 0 ; i < n ; i++ ) arr[i] = LB(dst, arr[i]) - dst.begin();
}

inline void solve(){
    cin >> n >> m >> c;

    arr.resize(n);
    for( int i = 0 ; i < n ; ++i ){
        cin >> arr[i];
        tmp[i] = arr[i];
    }
    
    discretization();

    pfx.resize(dst.sz + 1, 0);
    for( auto i : arr ) ++pfx[i+1];

    for( int i = 1 ; i <= dst.sz ; ++i ) pfx[i] += pfx[i-1];

    // pV(pfx);

    res = 0;
    for( int i = 0 ; i < dst.sz ; ++i ){
        acc = 0;

        cnt = i;
        while( acc < c ){
            int nxt = LB(pfx, pfx[cnt] + c - acc) - pfx.begin();

            if( nxt == pfx.sz ){
                acc += pfx[nxt-1] - pfx[cnt];
                cnt = 0;
            }else{
                acc += pfx[nxt] - pfx[cnt];
                cnt = nxt;
            }
        }

        pos[i] = acc;
    }

    res += (dst[0] - 0) * pos[0];
    for( int i = 0 ; i < dst.sz - 1 ; ++i ){
        res += (dst[i+1] - dst[i]) * pos[i+1];
    }
    res += ( m - dst.back() ) * pos[0];

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