/* Question : CSES 1744. Rectangle Cutting */

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
const int MAXN = 5e3 + 50;
const int Mod = 1e9 + 7;
const int INF = 1e9;
int w, h, dp[MAXN][MAXN];

signed main(){
    opt;
    cin >> w >> h;
    
    for( int i = 0 ; i <= w ; i++ ){
        for( int j = 0 ; j <= h ; j++ ){
            if( i == j ) dp[i][j] = 0;
            else{
                dp[i][j] = 1e9;
                for( int k = 0 ; k <= i ; k++ ) dp[i][j] = min(dp[i][j], dp[i-k][j] + dp[k][j] + 1);
                for( int k = 0 ; k <= j ; k++ ) dp[i][j] = min(dp[i][j], dp[i][j-k] + dp[i][k] + 1);
            }
        }
    }

    cout << dp[w][h] << "\n";
}