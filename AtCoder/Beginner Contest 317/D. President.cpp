/* Question : AtCoder Beginner Contest 317 - D - President */

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
const int MAXN = 1e2 + 50;
const int Mod = 1e9 + 7;
int n, tz, res, elect[MAXN][5];

signed main(){
    opt;
    cin >> n;
    for( int i = 0 ; i < n ; i++ ) cin >> elect[i][0] >> elect[i][1] >> elect[i][2];   // Takahashi, Aoki, Seats
    
    for( int i = 0 ; i < n ; i++ ) tz += elect[i][2];
    vector<int> dp(tz+1, 1e18);
    dp[0] = 0;
    for( int i = 0 ; i < n ; i++ ){
        int w = max( (long long)0, ( ( elect[i][1] - elect[i][0] ) / 2 + 1 ) );
        for( int j = tz ; j >= elect[i][2] ; j-- ) dp[j] = min(dp[j], dp[j - elect[i][2]] + w);
    }

    res = 1e18;
    for( int i = tz / 2 + 1; i <= tz ; i++ ) res = min(res, dp[i]);
    cout << res << "\n";
}