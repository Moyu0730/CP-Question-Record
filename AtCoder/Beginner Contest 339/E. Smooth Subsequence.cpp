/* Question : AtCoder Beginner Contest 339 - E. Smooth Subsequence */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define priq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define F first
#define S second
#define X first
#define Y second

#define nL v*2
#define nR v*2+1

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 5e5 + 50;
const int Mod = 1e9 + 7;
const int X = 5e5;
int n, d, res, cnt, tmp;
int dp[MAXN * 4], arr[MAXN];

int query( int L, int R, int ql, int qr, int v ){
    if( R < L || ql > R || qr < L ) return 0;
    if( ql <= L && qr >= R ) return dp[v];

    int M = (L + R) / 2;
    return max( query(L, M, ql, qr, nL), query(M+1, R, ql, qr, nR) );
}

void modify( int L, int R, int ml, int mr, int val, int v ){
    if( R < L || ml > R || mr < L ) return;
    if( ml <= L && mr >= R ){
        dp[v] = val;
        return;
    }

    int M = (L + R) / 2;
    modify(L, M, ml, mr, val, nL);
    modify(M+1, R, ml, mr, val, nR);
    dp[v] = max( dp[nL], dp[nR] );
}

signed main(){
    opt;
    cin >> n >> d;

    for( int i = 1 ; i <= n ; i++ ) cin >> arr[i];

    for( int i = 1 ; i <= n ; i++ ){
        int l = max(1, arr[i] - d);
        int r = min(X, arr[i] + d);

        int mx = query(1, X, l, r, 1);
        modify(1, X, arr[i], arr[i], mx + 1, 1);
    }

    cout << query(1, X, 1, X, 1) << "\n";
}