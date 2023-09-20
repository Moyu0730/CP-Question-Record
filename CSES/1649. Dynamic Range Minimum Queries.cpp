/* Question : CSES 1649. Dynamic Range Minimum Queries */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pirq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define f first
#define s second
#define int long long

#define nL cnt * 2
#define nR cnt * 2 + 1

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
int n, q, arr[MAXN], seg[MAXN * 4];

int query( int L, int R, int ql, int qr, int cnt ){
    if( R < L || ql > R || qr < L ) return 1e18;
    if( qr >= R && ql <= L ) return seg[cnt];

    int M = (L + R) / 2;
    return min( query(L, M, ql, qr, nL), query(M+1, R, ql, qr, nR) );
}

void modify( int L, int R, int m, int val, int cnt ){
    if( R < L || m > R || m < L ) return;
    if( m == R && m == L ){
        seg[cnt] = val;
        return;
    }

    int M = (L + R) / 2;
    modify(L, M, m, val, nL);
    modify(M+1, R, m, val, nR);
    seg[cnt] = min(seg[nL], seg[nR]);
}

void build( int L, int R, int cnt ){
    if( L == R ){
        seg[cnt] = arr[L];
        return;
    }

    int M = (L + R) / 2;
    build(L, M, nL);
    build(M+1, R, nR);
    seg[cnt] = min( seg[nL], seg[nR] );
}

signed main(){
    // opt;
    cin >> n >> q;
    mem(seg, 0x3F);
    for( int i = 1 ; i <= n ; i++ ) cin >> arr[i];
    build(1, n, 1);

    // for( int i = 1 ; i <= 15 ; i++ ) cout << seg[i] << " \n"[i==15];

    while( q-- ){
        int t, x, y;
        cin >> t >> x >> y;
        if( t == 1 ){
            modify(1, n, x, y, 1);
            // for( int i = 1 ; i <= 15 ; i++ ) cout << seg[i] << " \n"[i==15];
        }else{
            cout << query(1, n, x, y, 1) << "\n";
        }
    }
}