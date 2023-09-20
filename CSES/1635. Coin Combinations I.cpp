/* Question : CSES 1635. Coin Combinations */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define f first
#define s second

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e6 + 50;
const int Mod = 1e9 + 7;
int n, x, cnt;
int coin[MAXN], dp[MAXN];

signed main(){
    opt;
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> coin[i];
    
    dp[0] = 1;
    for (int i = 0 ; i < x; i++ ){
        for (int j = 0 ; j < n ; j++ ){
            if ( i + coin[j] > x) continue;
            dp[i + coin[j]] += dp[i];
            dp[i + coin[j]] %= Mod;
        }
    }
    cout << dp[x] << "\n";
}