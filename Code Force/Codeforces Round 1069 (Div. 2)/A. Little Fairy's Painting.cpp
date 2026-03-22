/* Question : Codeforces Round 1069 (Div. 2) - A. Little Fairy's Painting */

#include<bits/stdc++.h>
using namespace std;

/* Pragma */ 
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
/* Self Define */ 
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); 
#define MEM(_A, _V) memset(_A, _V, sizeof(_A)) 
#define ALL(_A) _A.begin(), _A.end() 
#define LB(_A, _V) lower_bound(ALL(_A), v) 
#define UB(_A, _V) upper_bound(ALL(_A), v) 
#define pii pair<int, int> 
#define sz size() 
#define cr clear()
#define rz resize
#define pb push_back 
#define F first 
#define S second 
#define int long long 
#define tpn typename 
 
/* Self Define Template Function */ 
template<tpn A, tpn B> ostream& operator<<( ostream& _os, pair<A, B> _p ){  
    return _os << '(' << _p.F << ", " << _p.S << ')'; 
}

/* Self Define Const */
const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1},  {-1, 0}, {0, -1}, 
                                            {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
const int         MAXN = 1e3 + 50;
const int          Mod = 1e9 + 7;
const int          INF = 0x7FFFFFFF;
const int         LLINF = 0x7FFFFFFFFFFFFFFF;
const int       MEMINF = 0x3F;
const int   MEMINF_VAL = 0x3F3F3F3F;
const int MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int n, tmp, res, amt[MAXN];

inline void solve(){
    cin >> n;

    res = 0;
    MEM(amt, 0);
    for( int i = 0 ; i < n ; ++i ){
        cin >> tmp;

        ++amt[tmp];

        if( amt[tmp] == 1 ) ++res;
    }

    int st = res;
    while( amt[res] ){
        ++amt[res];
        ++res;
    }

    cout << res << "\n";
}

signed main(){
    IO

    int T = 1;
    cin >> T;
    while( T-- ){
        solve();
    }
}