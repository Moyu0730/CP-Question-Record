/* Question : CSES 1650. Range Xor Queries */

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
int n, q, x, y, arr[MAXN], seg[MAXN * 4];

void update( int cnt ){
    seg[cnt] = seg[nL] ^ seg[nR];
    return;
}

void build( int L, int R, int cnt ){
    if( L == R ){
        seg[cnt] = arr[L];
        return;
    }
    int M = ( L + R ) / 2;
    build(L, M, nL);
    build(M+1, R, nR);
    update(cnt);
}

int query( int L, int R, int ql, int qr, int cnt ){
    if( L > R || ql > R || qr < L ) return 0;
    if( ql <= L && qr >= R ) return seg[cnt];
    int M = (L + R) / 2;
    return query(L, M, ql, qr, nL) ^ query(M+1, R, ql, qr, nR);
}

signed main(){
    opt;
    cin >> n >> q;
    for( int i = 1 ; i <= n ; i++ ) cin >> arr[i];
    build(1, n, 1);

    while( q-- ){
        cin >> x >> y;
        cout << query(1, n, x, y, 1) << "\n";
    }
}