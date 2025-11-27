/* Question : AtCoder Beginner Contest 432 - E. Clamp */

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
#define rz resize
#define cr clear()
#define pb push_back
#define F first
#define S second
#define X first
#define Y second
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
    return _os << '(' << _pair.F << ", " << _pair.S << ')';
}

/* Self Define Const */
const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1},  {-1, 0}, {0, -1}, 
                                            {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
const int         MAXN = 5e5 + 50;
const int          Mod = 1e9 + 7;
const int          INF = 0x7FFFFFFF;
const ll         LLINF = 0x7FFFFFFFFFFFFFFF;
const int       MEMINF = 0x3F;
const int   MEMINF_VAL = 0x3F3F3F3F;
const ll  MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int n, q, tp, a, b, arr[MAXN];

template<tpn T> struct NODE {
    T val, amt;
    NODE() : val(0), amt(0) {}
    T gV(){ return val * amt; }
};

NODE<int> ARRAY[MAXN * 4];

template<tpn T> struct SEG {
    #define nL (x<<1)
    #define nR (x<<1) + 1
    #define M ( L + R ) / 2

    // SEG(){ build(1, n, 1); }
    pii FUNC( pii vL, pii vR ){ return {vL.F + vR.F, vL.S + vR.S}; }

    // void push( int x ){
    //     ARRAY[nL].tag += ARRAY[x].tag;
    //     ARRAY[nR].tag += ARRAY[x].tag;
    //     ARRAY[x].val = ARRAY[x].gV();
    //     ARRAY[x].tag = 0;
    // }

    // void build( int L, int R, int x ){

    //     if( R == L ){
    //         ARRAY[x].val = L;
    //         return;
    //     }

    //     int M = (L + R) / 2;
    //     build(L, M, nL);
    //     build(M+1, R, nR);
    //     ARRAY[x].val = FUNC( ARRAY[nL].gV(), ARRAY[nR].gV() );
    // }

    pii query( int qL, int qR ){ return query(1, MAXN, qL, qR, 1); }
    pii query( int L, int R, int qL, int qR, int x ){
        if( R < L || qL > R || qR < L ) return {0, 0};
        if( qL <= L && R <= qR ) return { ARRAY[x].amt, ARRAY[x].val };

        // push(x);

        return FUNC( query(L, M, qL, qR, nL), query(M+1, R, qL, qR, nR) );
    }

    void update( int mL, int mR, T mV ){ update(1, MAXN, mL, mR, mV, 1); }
    void update( int L, int R, int mL, int mR, T mV, int x ){
        if( R < L || mL > R || mR < L ) return;
        if( mL <= L && R <= mR ){
            ARRAY[x].amt += mV;
            ARRAY[x].val = (L-1) * ARRAY[x].amt;
            return;
        }

        update(L, M, mL, mR, mV, nL);
        update(M+1, R, mL, mR, mV, nR);
        ARRAY[x].amt = ARRAY[nL].amt + ARRAY[nR].amt;
        ARRAY[x].val = ARRAY[nL].val + ARRAY[nR].val;
    }
};

inline void solve(){
    cin >> n >> q;

    SEG<int> seg;
    for( int i = 1 ; i <= n ; ++i ){
        cin >> arr[i];
        ++arr[i];
        seg.update(arr[i], arr[i], 1);
    }

    while( q-- ){
        cin >> tp >> a >> b;

        if( tp == 1 ){
            ++b;
            seg.update(arr[a], arr[a], -1);
            seg.update(b, b, 1);
            arr[a] = b;
        }else{
            ++a, ++b;
            if( a >= b ) cout << (a-1) * n << "\n";
            else{
                int res = 0;

                res += seg.query(1, a).F * (a-1);
                res += seg.query(b, MAXN).F * (b-1);
                res += seg.query(a+1, b-1).S;

                cout << res << "\n";
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