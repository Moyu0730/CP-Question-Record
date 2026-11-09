/* Question : UVa 160. Factors and Factorials */

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
#define rz resize
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
const int         MAXN = 3e4 + 60;
const int          Mod = 1e9 + 7;
const int          INF = 0x7FFFFFFF;
const ll         LLINF = 0x7FFFFFFFFFFFFFFF;
const int       MEMINF = 0x3F;
const int   MEMINF_VAL = 0x3F3F3F3F;
const ll  MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

vector<int> primes;
int n;
vector<map<int, int>> arr, mp;

inline void solve(){
    for( int i = 2 ; i <= 100 ; ++i ){
        bool flag = false;
        for( int j = 2 ; j * j <= i ; ++j ){
            if( i % j == 0 ){
                flag = true;
                break;
            }
        }

        if( !flag ) primes.pb(i);
    }

    arr.rz(100 + 50);
    mp.rz(100 + 50);

    for( int i = 2 ; i <= 100 ; ++i ){
        int cnt = i;
        for( auto j : primes ){
            if( j > cnt ) break;
            
            while( cnt % j == 0 ){
                ++mp[i][j];
                cnt /= j;
            }
        }
    }

    for( int i = 2 ; i <= 100 ; ++i ){
        arr[i] = arr[i-1];

        for( auto j : mp[i] ) arr[i][j.F] += j.S;
    }

    while( cin >> n && n != 0 ){
        cout << setw(3) << right << n << "! =";

        int counter = 0;
        for( auto i : arr[n] ){
            if( counter == 15 ){ 
                cout << "\n      ";
                counter = 0;
            }
            cout << setw(3) << i.S;
            ++counter;
        }
        cout << "\n";
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