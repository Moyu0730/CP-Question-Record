/* Question : AtCoder Beginner Contest 481 - E. Most Brilliant Starry Sky */

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
#define as assign
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

int n, res, tmpx, tmpy;

struct Pt { 
    int x, y; 
    Pt( int _x = 0, int _y = 0 ) : x(_x), y(_y) {} 
    Pt operator+( const Pt& a ) const { 
        return Pt( x + a.x, y + a.y ); 
    } 
    Pt operator-( const Pt& a ) const { 
        return Pt( x - a.x, y - a.y ); 
    } 
    Pt operator*( const int& a ) const { 
        return Pt( x * a, y * a ); 
    } 
    Pt operator/( const int& a ) const { 
        return Pt( x / a, y / a ); 
    } 
    int operator*( const Pt& a ) const { 
        return x * a.x + y * a.y; 
    } 
    int operator^( const Pt& a ) const { // Cross 
        return x * a.y - y * a.x; 
    } 
    bool operator<( const Pt & a ) const { 
        return x < a.x || ( x == a.x && y < a.y ); 
    } 
    bool operator==( const Pt & a ) const { 
        return x == a.x && y == a.y; 
    } 
};

inline int cross( Pt o, Pt a, Pt b ){  
    return (a - o) ^ (b - o); 
}

inline bool half( Pt p ){
    return p.y < 0 || ( p.y == 0 && p.x < 0 );
}

inline void solve(){
    cin >> n;

    vector<Pt> pt;
    for( int i = 0 ; i < n ; ++i ){
        cin >> tmpx >> tmpy;
        pt.pb({tmpx, tmpy});
    }

    sort(ALL(pt), []( Pt a, Pt b ){
        if( half(a) != half(b) ) return half(a) < half(b);
        return (a ^ b) > 0;
    });
    
    int r = 1;
    res = 0;
    for( int i = 0 ; i < n ; ++i ){
        while( r != i && cross({0, 0}, pt[i], pt[r]) > 0 ) r = ( r + 1 ) % n;
        
        res = max({res, abs(r - i), n - abs(r - i)});
    }

    cout << res << "\n";
}

signed main(){
    IO;

    int T = 1;
    cin >> T;
    while( T-- ){
        solve();
    }
}