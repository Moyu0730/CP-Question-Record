/* Question : CSES 1144. Salary Queries */

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
const int         MAXN = 1e6 + 50;
const int          Mod = 1e9 + 7;
const int          INF = 0x7FFFFFFF;
const ll         LLINF = 0x7FFFFFFFFFFFFFFF;
const int       MEMINF = 0x3F;
const int   MEMINF_VAL = 0x3F3F3F3F;
const ll  MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

#define nL v * 2
#define nR v * 2 + 1

int n, q, arr[MAXN], tmp[MAXN];
char op;
int a, b, counter;
vector< pair<char, pii> > ask;
vc(int) distinct;

struct Node {
    int val = 0, tag = 0, len;
    int getValue(){ return val + (tag * len); }
} SEG[MAXN * 4];

void build( int L, int R, int v ){
    SEG[v].len = R - L + 1;
    if( R == L ){
        SEG[v].val = 0;
        return;
    }

    int M = (L + R) / 2;
    build(L, M, nL);
    build(M+1, R, nR);
    SEG[v].val = SEG[nL].val + SEG[nR].val;
}

int query( int L, int R, int qL, int qR, int v ){
    if( R < L || qL > R || qR < L ) return 0;
    if( qL <= L && R <= qR ) return SEG[v].val;
    
    int M = (L + R) / 2;
    return query(L, M, qL, qR, nL) + query(M+1, R, qL, qR, nR);
}

void modify( int L, int R, int mL, int mR, int val, int v ){
    if( R < L || mL > R || mR < L ) return;
    if( mL <= L && R <= mR ){
        SEG[v].val += val;
        return;
    }

    int M = (L + R) / 2;
    modify(L, M, mL, mR, val, nL);
    modify(M+1, R, mL, mR, val, nR);
    SEG[v].val = SEG[nL].val + SEG[nR].val;
}

void disc(){
    sort(tmp, tmp + n + counter);

    distinct.pb(tmp[0]);
    for( int i = 1 ; i < n + counter ; i++ ){
        if( tmp[i] != tmp[i-1] ) distinct.pb(tmp[i]);
    }

    for( int i = 0 ; i < n + counter ; i++ ) arr[i] = lower_bound(distinct.begin(), distinct.end(), arr[i]) - distinct.begin() + 1;
}

inline void solve(){
    cin >> n >> q;

    for( int i = 1 ; i <= n ; ++i ){
        cin >> arr[i];
        tmp[i] = arr[i];
    }

    counter = 1;
    for( int i = 0 ; i < q ; ++i ){
        cin >> op >> a >> b;
        ask.pb( { op, {a, b} } );
        if( op == '!' ){
            arr[n + counter] = b;
            tmp[n + counter] = b;
            ++counter;
        }else{
            arr[n + counter] = a;
            tmp[n + counter] = a;
            ++counter;
            arr[n + counter] = b;
            tmp[n + counter] = b;
            ++counter;
        }
    }
    
    disc();
    for( int i = 1 ; i <= n ; ++i ) modify(1, n + counter, arr[i], arr[i], 1, 1);
    
    int cnt = 1;
    for( auto [x, pir] : ask ){
        auto [y, z] = pir;

        if( x == '?' ){
            y = arr[n + cnt];
            ++cnt;
            z = arr[n + cnt];
            ++cnt;
            cout << query(1, n + counter, y, z, 1) << "\n";
        }else{
            z = arr[n + cnt];
            ++cnt;
            modify(1, n + counter, arr[y], arr[y], -1, 1);
            modify(1, n + counter, z, z, 1, 1);
            arr[y] = z;
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