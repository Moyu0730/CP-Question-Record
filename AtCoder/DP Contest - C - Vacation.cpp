/* Question :  Number */

/*
 * 定義：dp[i][j] = 
 *                  i : The Max Cost from 0 to i (Include)
 *                  j : The Type of Activity
 * 轉移：dp[i][j] = 
 *                  max()
 * 基底：dp[0] = 0, dp[1] = abs(stone[1] - stone[0])
 */


#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<math.h>
#include<algorithm>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int MAXN = 1e5 + 50;
const int Mod = 1e9 + 7;
int act[MAXN][3+5];
int dp[MAXN][3+5];
int n;
auto tp = vector<pair<int, int>> { {1, 2}, {0, 2}, {0, 1} };

int sol( int ind, int type ){
    int res = max( dp[ind-1][tp[type].first], dp[ind-1][tp[type].second] );
    return res;
}

signed main(){
    opt;
    cin >> n;
    for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j < 3 ; j++ ){
            cin >> act[i][j];
        }
    }

    dp[0][0] = act[0][0], dp[0][1] = act[0][1], dp[0][2] = act[0][2];
    for( int i = 1 ; i < n ; i++ ){
        for( int j = 0 ; j < 3 ; j++ ){
            dp[i][j] = sol(i, j) + act[i][j];
        }
    }
    
    int ans = max( dp[n-1][0], max( dp[n-1][1], dp[n-1][2] ) );
    
    cout << ans;
}