/* Question : AtCoder Beginner Contest 450 - E. Fibonacci String */

#include<bits/stdc++.h>
using namespace std;

/* Pragma */
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

/* Self Define */
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MEM(_A, _V) memset(_A, _V, sizeof(_A))
#define ALL(_A) _A.begin(), _A.end()
#define LB(_A, _V) lower_bound(ALL(_A), _V)
#define UB(_A, _V) upper_bound(ALL(_A), _V)
#define pii pair<int, int>
#define az assign
#define sz size()
#define cr clear()
#define rz resize
#define pb push_back
#define F first
#define S second
#define int long long
#define tpn typename

/* Self Define Template Function */
template<tpn T> void pV( vector<T> _A ){
    for( auto _I : _A ) cout << _I << " ";
    cout << "\n";
}

template<tpn A, tpn B> ostream& operator<<( ostream& _OS, pair<A, B> _P ){
    return _OS << "(" << _P.F << ", " << _P.S << ")";
}

/* Self Define Const */
const auto dir = vector<pii> { {1, 0}, {0, 1},  {-1, 0}, {0, -1},
                               {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
const int     MAXN = 1e4 + 50;
const int      Mod = 1e9 + 7;
const int      INF = 0x7FFFFFFF;
const int    LLINF = 0x7FFFFFFFFFFFFFFF;
const int MEMLLINF = 0x3F3F3F3F3F3F3F3F;

int q, l, r;
vector<int> len;
char ch;
string x, y;
map<int, int> mp[MAXN], mpx[MAXN], mpy[MAXN];

int query( int amt, int cnt ){
    if( amt == 0 ) return 0;

    if( cnt == 1 ) return mpx[amt-1][ch];
    if( cnt == 2 ) return mpy[amt-1][ch];

    if( amt == len[cnt] ) return mp[cnt][ch];
    else if( amt == len[cnt-1] ) return mp[cnt-1][ch];
    else if( amt > len[cnt-1] ) return mp[cnt-1][ch] + query(amt - len[cnt - 1], cnt - 2);
    else return query(amt, cnt-1);
}

inline void solve(){
    cin >> x >> y >> q;

    len.pb(0);
    len.pb(x.sz);
    ++mpx[0][x[0]];
    for( int i = 1 ; i < x.sz ; ++i ){
        mpx[i] = mpx[i-1];
        ++mpx[i][x[i]];
    }

    len.pb(y.sz);
    ++mpy[0][y[0]];
    for( int i = 1 ; i < y.sz ; ++i ){
        mpy[i] = mpy[i-1];
        ++mpy[i][y[i]];
    }

    mp[1] = mpx[x.sz-1];
    mp[2] = mpy[y.sz-1];
    for( int i = 3 ; len[i-1] < 1e18 ; ++i ){
        len.pb(len[i-1] + len[i-2]);

        for( char j = 'a' ; j <= 'z' ; ++j ) mp[i][j] = mp[i-1][j] + mp[i-2][j];
    }

    while( q-- ){
        cin >> l >> r >> ch;

        l--;

        // cout << "R | idx_r: " << idx_r << ", query(r, idx_r): " << query(r, idx_r) << "\n";
        // cout << "L | idx_l: " << idx_l << ", query(l, idx_l): " << query(l, idx_l) << "\n";
        // cout << "ANSWER | ";

        cout << query(r, len.sz - 1) - query(l, len.sz - 1) << "\n";
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