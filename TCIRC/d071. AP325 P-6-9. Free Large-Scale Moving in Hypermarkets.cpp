/* Question : TCIRC d071. AP325 P-6-9. Free Large-Scale Moving in Hypermarkets */

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

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 100 + 5;
const int Mod = 1e9 + 7;
const int INF = 1e9;
int n, t, p[MAXN], w[MAXN], dp[MAXN][100001];

signed main(){
    opt;
    cin >> n >> t;

    for( int i = 1 ; i <= n ; i++ ) cin >> w[i];
    for( int i = 1 ; i <= n ; i++ ) cin >> p[i];

    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 0 ; j < w[i] ; j++ ) dp[i][j] = dp[i-1][j];
        for( int j = w[i] ; j <= t ; j++ ) dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + p[i]);
    }

    cout << dp[n][t] << "\n";
}