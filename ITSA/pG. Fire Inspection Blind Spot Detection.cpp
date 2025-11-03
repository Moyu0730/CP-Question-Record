/* Question : ITSA 202510 - pG. Fire Inspection Blind Spot Detection */

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
const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1},  {-1, 0}, {0, -1} };
const int         MAXN = 6 + 50;
const int          Mod = 1e9 + 7;
const int          INF = 0x7FFFFFFF;
const ll         LLINF = 0x7FFFFFFFFFFFFFFF;
const int       MEMINF = 0x3F;
const int   MEMINF_VAL = 0x3F3F3F3F;
const ll  MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int n, m, amt, arr[MAXN][MAXN];
bool used[MAXN][MAXN];
pii cnt;

inline bool solve(){
    cin >> n >> m;

    for( int i = 0 ; i < n ; ++i ){
        for( int j = 0 ; j < m ; ++j ){
            cin >> arr[i][j];

            if( arr[i][j] == 0 ) ++amt;
        }
    }

    cin >> cnt.F >> cnt.S;

    queue<pii> q;
    if( arr[cnt.F][cnt.S] == 0 ) q.push(cnt);
    --amt;
    used[cnt.F][cnt.S] = true;

    while( !q.empty() ){
        cnt = q.front();
        q.pop();

        for( int t = 0 ; t < 4 ; ++t ){
            pii nxt = { cnt.F + dir[t].F, cnt.S + dir[t].S };

            if( nxt.F < 0 || nxt.F >= n || nxt.S < 0 || nxt.S >= m ) continue;
            if( used[nxt.F][nxt.S] ) continue;
            if( arr[nxt.F][nxt.S] == 1 ) continue;
            
            --amt;
            used[nxt.F][nxt.S] = true;
            q.push(nxt);
        }
    }

    return (amt == 0);
}

signed main(){
    IO;

    int T = 1;
    // cin >> T;
    while( T-- ){
        if( solve() ) cout << "false\n";
        else cout << "true\n";
    }
}