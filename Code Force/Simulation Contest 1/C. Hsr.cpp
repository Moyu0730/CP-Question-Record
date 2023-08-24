/* Question : CF 【2023 MD Player Training】 Simulation Contest 1 - C. Hsr */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pirq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define f first
#define s second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
int n, a[MAXN], b[MAXN], c[MAXN], dp[MAXN][5];

signed main(){
    opt;
    cin >> n;
    for( int i = 1 ; i <= n ; i++ ) cin >> a[i];
    for( int i = 1 ; i <= n ; i++ ) cin >> b[i];
    for( int i = 1 ; i <= n ; i++ ) cin >> c[i];

    dp[0][1] = 0; // On A
    dp[0][2] = 0; // On B
    for( int i = 1 ; i <= n ; i++ ){
        dp[i][1] = min( dp[i-1][1] + a[i], dp[i-1][2] + c[i] + a[i] );
        
        if( i == 1 ) dp[i][2] = dp[i-1][1] + c[i] + b[i];
        else dp[i][2] = min( dp[i-1][2] + b[i], dp[i-1][1] + c[i] + b[i] );
    }

    cout << min( dp[n][1], dp[n][2] ) << "\n";
}