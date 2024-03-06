/* Question : TCIRC d068. AP325 P-6-3. Minimum Cost of Monitoring Neighbors */

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
int n, cost[MAXN], dp[MAXN];

int func( int a, int b, int c ){
    vector<int> v;
    v.pb(a); v.pb(b); v.pb(c);
    sort(v.begin(), v.end());

    return v.front();
}

signed main(){
    opt;
    cin >> n;
    for( int i = 1 ; i <= n ; i++ ) cin >> cost[i];

    dp[0] = 0;
    dp[1] = cost[1];
    if( n >= 2 ) dp[2] = cost[2];
    if( n >= 3 ) dp[3] = min(dp[1], dp[2]) + cost[3];
    for( int i = 4 ; i <= n ; i++ ) dp[i] = func(dp[i-1], dp[i-2], dp[i-3]) + cost[i];
    
    if( n == 1 ) cout << dp[1] << "\n";
    else cout << min(dp[n], dp[n-1]) << "\n";
}