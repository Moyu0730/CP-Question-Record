/* Question : CSES 1746. Array Description */

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
int n, m, a, dp[MAXN][1000];

signed main(){
    opt;
    cin >> n >> m >> a;

    if( a == 0 ){
        for (int i = 1; i <= m; i++) dp[0][i] = 1;
    }
    else dp[0][a] = 1;

    for( int i = 1 ; i < n ; i++ ){
        cin >> a;

        if( a == 0 ){
            for( int a = 1 ; a <= m ; a++ ){
                dp[i][a] += dp[i-1][a-1];
                dp[i][a] %= Mod;
                dp[i][a] += dp[i-1][a];
                dp[i][a] %= Mod;
                dp[i][a] += dp[i-1][a+1];
                dp[i][a] %= Mod;
            }
        }else{
            dp[i][a] += dp[i-1][a-1];
            dp[i][a] %= Mod;
            dp[i][a] += dp[i-1][a];
            dp[i][a] %= Mod;
            dp[i][a] += dp[i-1][a+1];
            dp[i][a] %= Mod;
        }
    }

    int ans = 0;
    for( int i = 1 ; i <= m ; i++ ){
        ans += dp[n-1][i];
        ans %= Mod;
    }

    cout << ans << "\n";
}