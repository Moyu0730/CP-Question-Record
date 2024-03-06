/* Question : TCIRC d067. AP325 P-6-2. Discontinuous Performance Remuneration */

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
int n, arr[MAXN], dp[MAXN];

signed main(){
    opt;
    cin >> n;
    for( int i = 1 ; i <= n ; i++ ) cin >> arr[i];

    dp[0] = 0;
    dp[1] = arr[1];
    for( int i = 1 ; i <= n ; i++ ) dp[i] = max(dp[i-1], dp[i-2] + arr[i]);
    
    cout << dp[n] << "\n";
}