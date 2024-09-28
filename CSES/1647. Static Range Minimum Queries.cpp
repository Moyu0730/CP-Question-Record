/* Question : CSES 1647. Static Range Minimum Queries */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define F first
#define S second
#define X first
#define Y second
#define int long long

#define nL v * 2
#define nR v * 2 + 1

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
const int LLINF = 1e18;
const int INF = 1e9;

int n, q, l, r, arr[MAXN];

struct Node {
    int val = 0, tag = 0, len;
    int getValue(){
        return val + (tag * len);
    }
} SEG[MAXN * 4];

void build( int L, int R, int v ){
    SEG[v].len = R - L + 1;

    if( R == L ){
        SEG[v].val = arr[L];
        return;
    }

    int M = (L + R) / 2;
    build(L, M, nL);
    build(M+1, R, nR);
    SEG[v].val = min( SEG[nL].val, SEG[nR].val );
}

int query( int L, int R, int ql, int qr, int v ){
    if( R < L || ql > R || qr < L ) return INF;
    if( ql <= L && R <= qr ) return SEG[v].getValue();

    int M = (L + R) / 2;
    return min( query(L, M, ql, qr, nL), query(M+1, R, ql, qr, nR) );
}

signed main(){
    #ifndef LOCAL
        opt;
    #endif

    cin >> n >> q;

    for( int i = 1 ; i <= n ; i++ ) cin >> arr[i];

    build(1, n, 1);

    while( q-- ){
        cin >> l >> r;
        cout << query(1, n, l, r, 1) << "\n";
    }
}