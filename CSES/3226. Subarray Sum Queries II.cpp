/* Question : CSES 3226. Subarray Sum Queries II */

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
const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1},  {-1, 0}, {0, -1}, 
                                            {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
const int         MAXN = 2e5 + 50;
const int          Mod = 1e9 + 7;
const int          INF = 0x7FFFFFFF;
const ll         LLINF = 0x7FFFFFFFFFFFFFFF;
const int       MEMINF = 0x3F;
const int   MEMINF_VAL = 0x3F3F3F3F;
const ll  MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

#define nL (x<<1)
#define nR (x<<1) + 1

int n, q, a, b, arr[MAXN];

struct Node {
    int suf, pre, sum, ans;
} seg[MAXN * 4];

void build( int L, int R, int x ){
    if( L > R ) return;
    else if( L == R ){
        seg[x].suf = arr[L];
        seg[x].pre = arr[L];
        seg[x].sum = arr[L];
        seg[x].ans = arr[L];
        return;
    }

    int M = ( L + R ) / 2;
    build(L, M, nL);
    build(M+1, R, nR);

    seg[x].pre = max(seg[nL].pre, seg[nL].sum + seg[nR].pre);
    seg[x].suf = max(seg[nR].suf, seg[nR].sum + seg[nL].suf);
    seg[x].sum = seg[nL].sum + seg[nR].sum;
    seg[x].ans = max({seg[nL].ans, seg[nR].ans, seg[nL].suf + seg[nR].pre});
}

Node query( int L, int R, int qL, int qR, int x ){
    if( qL > R || qR < L ) return {0, 0, 0, 0};
    else if( qL <= L && R <= qR ){
        return seg[x];
    }

    int M = ( L + R ) / 2;
    Node rL = query(L, M, qL, qR, nL);
    Node rR = query(M+1, R, qL, qR, nR);

    Node res;
    res.pre = max(rL.pre, rL.sum + rR.pre);
    res.suf = max(rR.suf, rR.sum + rL.suf);
    res.sum = rL.sum + rR.sum;
    res.ans = max({rL.ans, rR.ans, rL.suf + rR.pre});

    return res;
}

inline void solve(){
    cin >> n >> q;

    for( int i = 1 ; i <= n ; ++i ) cin >> arr[i];

    build(1, n, 1);

    while( q-- ){
        cin >> a >> b;
        
        cout << max( (ll)0, query(1, n, a, b, 1).ans ) << "\n";
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
