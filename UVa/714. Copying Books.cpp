/* Question : UVa 714. Copying Books */

#include<bits/stdc++.h>
using namespace std;

/* Pragma */
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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

int n, k, amt, acc, arr[MAXN];
vector<int> ans;

inline bool valid( int cnt ){
    amt = 0, acc = 0;

    for( int i = 0 ; i < n ; ++i ){
        if( cnt < arr[i] ) return true;

        if( acc + arr[i] > cnt ){
            ++amt;
            acc = arr[i];
        }else{
            acc += arr[i];
        }
    }

    if( acc > 0 ) ++amt;

    return amt > k;
}

inline void solve(){
    cin >> n >> k;

    for( int i = 0 ; i < n ; ++i ) cin >> arr[i];

    int step = 1e18, res = 0;
    while( step > 0 ){
        if( valid(step + res) ) res += step;
        else step /= 2;
    }

    ++res;

    acc = 0;
    ans.cr;
    int remain = k - 1;
    for( int i = n - 1 ; i >= 0 ; --i ){
        if( acc + arr[i] <= res && i + 1 > remain ) ans.pb(arr[i]);
        else{
            ans.pb(-1);
            ans.pb(arr[i]);
            acc = 0;
            --remain;
        }

        acc += arr[i];
    }

    for( int i = ans.sz - 1 ; i >= 0 ; --i ){
        if( ans[i] == -1 ) cout << " /";
        else{
            if( i == ans.sz - 1 ) cout << ans[i];
            else cout << " " << ans[i];
        }
    }

    cout << "\n";
}

signed main(){
    IO;

    int T = 1;
    cin >> T;
    while( T-- ){
        solve();
    }
}