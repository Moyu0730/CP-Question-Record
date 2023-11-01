/* Question : Atcoder DP Contest - H. Grid 1 */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define priq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define f first
#define s second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e3 + 50;
const int Mod = 1e9 + 7;
int h, w, tmp, dp[MAXN][MAXN];
char graph[MAXN][MAXN];

signed main(){
    opt;

    cin >> h >> w;

    mem(dp, -1);
    for( int i = 1 ; i <= h ; i++ ){
        for( int j = 1 ; j <= w ; j++ ) cin >> graph[i][j];
    }

    dp[1][1] = 1;
    for( int i = 1 ; i <= h ; i++ ){
        for( int j = 1 ; j <= w ; j++ ){
            if( graph[i][j] == '.' ){
                tmp = 0;
                if( dp[i][j-1] != -1 ) tmp += dp[i][j-1];
                if( dp[i-1][j] != -1 ) tmp += dp[i-1][j];

                dp[i][j] = max(dp[i][j], tmp) % Mod;
            }
        }
    }

    cout << dp[h][w];
}