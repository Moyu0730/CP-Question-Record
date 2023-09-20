/* Question : CSES 1634. Minimizing Coins */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mem(x) memset(x, 0x3F, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define f first
#define s second

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e6 + 50;
const int Mod = 1e9 + 7;
int n, x, coins[MAXN], dp[MAXN];
bool flag = false;

signed main(){
    opt;
    cin >> n >> x;
    for( int i = 0 ; i < n ; i++ ) cin >> coins[i];
    mem(dp);
    dp[0] = 0;
    for( int i = 1 ; i <= x + 5 ; i++ ){
        for( int j = 0 ; j < n ; j++ ){
            if( i - coins[j] < 0 ) continue;
            if( i == x && dp[i-coins[j]] + 1 < dp[i] ) flag = true;
            dp[i] = min(dp[i], dp[i-coins[j]] + 1);
        }
    }
    if( flag == false ) cout << "-1\n";
    else cout << dp[x] << "\n";
}