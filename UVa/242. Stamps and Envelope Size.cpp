/* Question : UVa 242. Stamps and Envelope Size */

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
    for( int i = 1 ; i < _vector.sz ; ++i ) cout << setw(3) << setfill(' ') << _vector[i];
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
const int         MAXN = 1e3 + 50;
const int          Mod = 1e9 + 7;
const int          INF = 0x7FFFFFFF;
const ll         LLINF = 0x7FFFFFFFFFFFFFFF;
const int       MEMINF = 0x3F;
const int   MEMINF_VAL = 0x3F3F3F3F;
const ll  MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int s, n, m, tmp, res, dp[MAXN + 5];
vc(vc(int)) arr;

bool cmp( vc(int) a, vc(int) b ){
    if( a[0] != b[0] ) return a[0] < b[0];
    else if( a.sz != b.sz ) return a.sz < b.sz;
    else return a.back() < b.back();
}

inline void solve(){
    while( cin >> s && s != 0 ){
        cin >> n;

        arr.clear();
        arr.resize(n);
        res = 0;
        for( int t = 0 ; t < n ; ++t ){
            cin >> m;
            arr[t].pb(0);
            for( int i = 1 ; i <= m ; ++i ){
                cin >> tmp;
                arr[t].pb(tmp);
            }

            MEM(dp, MEMINF);
            dp[0] = 0;
            for( int i = 1 ; i <= m ; ++i ){
                for( int j = MAXN ; j >= arr[t][i] ; --j ){
                    for( int amt = 1 ; amt <= s && j >= amt * arr[t][i] ; ++amt ){
                        dp[j] = min(dp[j], dp[j - ( amt * arr[t][i] )] + amt);
                    }
                }
            }

            for( int i = 0 ; i <= MAXN ; ++i ){
                if( dp[i] > s ){
                    arr[t][0] = i;
                    res = max(res, i);
                    break;
                }
            }
        }

        sort(ALL(arr), cmp);

        for( auto i : arr ){
            if( i[0] == res ){
                cout << "max coverage =" << setw(4) << setfill(' ') << i[0]-1 << " :";
                pV(i);
                break;
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