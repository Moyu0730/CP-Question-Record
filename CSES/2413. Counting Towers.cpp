/* Question : CSES 2413. Counting Towers */

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
const int MAXN = 1e6 + 50;
const int Mod = 1e9 + 7;
const int INF = 1e9;
int n, t, q, dp[MAXN][3];

signed main(){
    opt;

    dp[1][1] = 1;   // --
    dp[1][2] = 1;   // **
    for( int i = 2 ; i <= 1000000 ; i++ ){
        dp[i][1] += dp[i-1][1] * 2 + dp[i-1][2];
        dp[i][1] %= Mod;
        dp[i][2] += dp[i-1][1] + 4 * dp[i-1][2];
        dp[i][2] %= Mod;
    }

    cin >> t;
    for( int i = 0 ; i < t ; i++ ){
        cin >> q;
        cout << ( dp[q][1] + dp[q][2] ) % Mod << "\n";
    }
}