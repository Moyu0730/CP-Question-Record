/* Question : CF 2026 NTOU Introduction to Competitive Programming Pretraining Midterm Contest - pF. All Prime Day */

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

int days[12 + 5] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int n;
bool isPrime[MAXN];

inline void getPrime(){
    MEM(isPrime, true);

    isPrime[0] = false;
    isPrime[1] = false;
    for( int i = 2 ; i < MAXN ; ++i ){
        if( isPrime[i] ){
            int cnt = i;
            int ctr = 2;
            while( i * ctr < MAXN ){
                cnt = i * ctr;
                isPrime[cnt] = false;
                ++ctr;
            }
        }
    }
}

inline bool isLeap( int y ){
    if( ( y % 100 == 0 || y % 4 == 0)  && y % 400 != 0 ) return true;
    else return false;
}

inline void add( int val ){
    int y = val / 10000;
    int m = val / 100 % 100;
    int d = val % 100;

    if( d >= days[m] ){
        if( m == 12 ){
            ++y;
            d = 1;
            m = 1;
        }else if( isLeap(y) && m == 2 && d == 28 ){
            d = 29;
        }else{
            ++m;
            d = 1;
        }
    }else ++d;

    n = y * 10000 + m * 100 + d;
}

inline bool valid( int val ){
    int tmp = 10000000;

    for( int i = 2 ; i * i <= val ; ++i ){
        if( val % i == 0 ) return false;
    }

    val %= tmp;
    tmp /= 10;

    while( val ){
        if( !isPrime[val] ) return false;

        val %= tmp;
        tmp /= 10;
    }

    return true;
}

inline void solve(){
    getPrime();
    
    cin >> n;

    while( n <= 99991231 ){
        add(n);
        
        if( valid(n) ){
            cout << n << "\n";
            return;
        }   
    }

    cout << "Too much digits!!!\n";
}

signed main(){
    IO;

    int T = 1;
    // cin >> T;
    while( T-- ){
        solve();
    }
}