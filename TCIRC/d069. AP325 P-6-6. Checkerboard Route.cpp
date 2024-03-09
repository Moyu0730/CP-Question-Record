/* Question : TCIRC d069. AP325 P-6-6. Checkerboard Route */

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

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 200 + 50;
const int Mod = 1e9 + 7;
const int INF = 1e9;
int m, n, arr[MAXN][MAXN], dp[MAXN][MAXN];

signed main(){
    opt;
    cin >> m >> n;
    for( int i = 1 ; i <= m ; i++ ){
        for( int j = 1 ; j <= n ; j++ ) cin >> arr[i][j];
    }

    for( int i = 1 ; i <= m ; i++ ){
        for( int j = 1 ; j <= n ; j++ ){
            if( i == 1 && j == 1 ) dp[i][j] = arr[i][j];
            else if( i == 1 ) dp[i][j] = dp[i][j-1] + arr[i][j];
            else if( j == 1 ) dp[i][j] = dp[i-1][j] + arr[i][j];
            else dp[i][j] = max( dp[i][j-1], dp[i-1][j] ) + arr[i][j];
        }
    }

    cout << dp[m][n] << "\n";
}