/* Question : TCIRC d073. AP325 Q-6-5. Two-Dimensional Maximum Submatrix */

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
const int MAXN = 2e2 + 50;
const int Mod = 1e9 + 7;
const int INF = 1e9;
int m, n, res, arr[MAXN][MAXN], pre[MAXN][MAXN], dp[MAXN];

signed main(){
    opt;
    cin >> n >> m;
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= m ; j++ ) cin >> arr[i][j];
    }

    for( int i = 1 ; i <= m ; i++ ){
        for( int j = 1 ; j <= n ; j++ ) pre[j][i] = pre[j-1][i] + arr[j][i];
    }
    
    dp[0] = 0;
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = i ; j <= n ; j++ ){
            for( int k = 1 ; k <= m ; k++ ){
                dp[k] = max(pre[j][k] - pre[i-1][k], dp[k-1] + pre[j][k] - pre[i-1][k] );
                res = max(res, dp[k]);
            }
        }
    }

    cout << res << "\n";
}