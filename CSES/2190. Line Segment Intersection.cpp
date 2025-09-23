/* Question : CSES 2190. Line Segment Intersection */

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
#define REV(_vector) _vector.reverse()
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
const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1},  {-1, 0}, {0, -1}, 
                                            {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
const int         MAXN = 1e7 + 50;
const int          Mod = 1e9 + 7;
const int          INF = 0x7FFFFFFF;
const ll         LLINF = 0x7FFFFFFFFFFFFFFF;
const int       MEMINF = 0x3F;
const int   MEMINF_VAL = 0x3F3F3F3F;
const ll  MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

struct Pt {
    int x, y;

    Pt( int _x = 0, int _y = 0 ) : x(_x), y(_y) {}
    Pt operator-( const Pt &a ) const { return Pt( x - a.x, y - a.y ); }
    int operator^( const Pt &a ) const { return x * a.y - y * a.x; } // Point Cross
    bool operator<( const Pt &a ) const { return x < a.x || ( x == a.x && y < a.y ); }
    bool operator==( const Pt &a ) const { return x == a.x && y == a.y; }
};

int cross( Pt &a, Pt &b, Pt &c ){
    Pt ab = b - a;
    Pt ac = c - a;
    return ab ^ ac;
}

bool cmp( Pt &a, Pt &b ){
    return ( a.x == b.x ) ? ( a.y < b.y ) : ( a.x < b.x );
}

bool mid( Pt a, Pt b, Pt c ){
    vector<Pt> tmp = {a, b, c};
    sort( ALL(tmp), cmp );

    return tmp[1] == c;
}

int sgn( int x ){
    return ( x > 0 ) - ( x < 0 );
}

int t;
Pt a, b, c, d;

inline bool solve(){
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;

    if( cross(a, b, c) == 0 && mid(a, b, c) ) return true;
    if( cross(a, b, d) == 0 && mid(a, b, d) ) return true;
    if( cross(c, d, a) == 0 && mid(c, d, a) ) return true;
    if( cross(c, d, b) == 0 && mid(c, d, b) ) return true;
    
    if( sgn(cross(a, b, c)) != sgn(cross(a, b, d)) && sgn(cross(c, d, a)) != sgn(cross(c, d, b)) ) return true;
    else return false;
}

signed main(){
    IO;

    int T = 1;
    cin >> T;
    while( T-- ){
        if( solve() ) cout << "YES\n";
        else cout << "NO\n";
    }
}