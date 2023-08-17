/* Question : CSES 1143. Hotel Queries */

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
int n, m, p, ans, hotel[MAXN], seg[MAXN*4];

int findk( int L, int R, int val, int cnt ){
    if( L == R ){
        seg[cnt] -= val;
        return L;
    }

    int M = (L + R) / 2;
    if( seg[nL] >= val ) ans = findk(L, M, val, nL);
    else if( seg[nR] >= val ) ans = findk(M+1, R, val, nR);

    seg[cnt] = max( seg[nL], seg[nR] );
    return ans;
}

void build( int L, int R, int cnt ){
    if( L == R ){
        seg[cnt] = hotel[L];
        return;
    }

    int M = (L + R) / 2;
    build(L, M, nL);
    build(M+1, R, nR);
    seg[cnt] = max( seg[nL], seg[nR] );
}

signed main(){
    opt;
    cin >> n >> m;
    for( int i = 1 ; i <= n ; i++ ) cin >> hotel[i];
    build(1, n, 1);

    for( int i = 0 ; i < m ; i++ ){
        cin >> p;
        ans = 0;
        if( seg[1] < p ) cout << 0 << " \n"[i==m-1];
        else cout << findk(1, n, p, 1) << " \n"[i==m-1];
    }
}