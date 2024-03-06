/* Question : TCIRC d072. AP325 Q-6-4. Choose One of Two Levels */

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
const int MAXN = 1e5 + 50;
const int Mod = 1e9 + 7;
const int INF = 1e9;
int n, t, num[MAXN][5], dp[MAXN][5];

signed main(){
    opt;
    cin >> n >> t;
    for( int i = 1 ; i <= n ; i++ ) cin >> num[i][1] >> num[i][2];
    
    dp[1][1] = abs( t - num[1][1] );
    dp[1][2] = abs( t - num[1][2] );
    for( int i = 2 ; i <= n ; i++ ){
        dp[i][1] = min( dp[i-1][1] + abs(num[i-1][1] - num[i][1]), dp[i-1][2] + abs(num[i-1][2] - num[i][1]) );
        dp[i][2] = min( dp[i-1][1] + abs(num[i-1][1] - num[i][2]), dp[i-1][2] + abs(num[i-1][2] - num[i][2]) );
    }

    cout << min(dp[n][1], dp[n][2]) << "\n";
}