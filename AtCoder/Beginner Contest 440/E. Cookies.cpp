/* Question : AtCoder Beginner Contest 440 - E. Cookies */

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
#define LB(_A, _V) lower_bound(ALL(_A), _V)
#define UB(_A, _V) upper_bound(ALL(_A), _V)
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
const int     MAXN = 1e7 + 50;
const int      Mod = 1e9 + 7;
const int      INF = 0x7FFFFFFF;
const int    LLINF = 0x7FFFFFFFFFFFFFFF;
const int MEMLLINF = 0x3F3F3F3F3F3F3F3F;

int n, k, x, arr[MAXN];
set<vector<int>> used;

inline void solve(){
    cin >> n >> k >> x;

    for( int i = 0 ; i < n ; ++i ) cin >> arr[i];

    sort(arr, arr + n, greater<int>());

    priority_queue<pair<int, vector<int>>> pq;
    vector<int> st(n, 0);
    st[0] = k;
    pq.push({k * arr[0], st});
    used.insert(st);

    while( x-- ){
        auto [val, v] = pq.top();
        pq.pop();

        cout << val << "\n";

        for( int i = 0 ; i < (int)v.sz ; ++i ){
            if( v[i] > 0 && i + 1 < (int)v.sz ){
                --v[i];
                ++v[i+1];

                if( used.find(v) == used.end() ){
                    pq.push({val - arr[i] + arr[i+1], v});
                    used.insert(v);
                }
                
                ++v[i];
                --v[i+1];
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