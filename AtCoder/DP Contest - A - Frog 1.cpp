/* Question : AtCoder DP Contest - A - Frog 1 */

/*
 * 定義： dp[i] = The Less Cost from 0 to i (Include)
 * 轉移： dp[i] = min( abs(stone[i] - stone[i-1]) + dp[i-1], abs(stone[i] - stone[i-2]) + dp[i-2])
 * 基底： dp[0] = 0, dp[1] = abs(stone[1] - stone[0])
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
int n;
int stone[MAXN], dp[MAXN];

signed main(){
    opt;
    cin >> n;
    for( int i = 0 ; i < n ; i++ ) cin >> stone[i];
    
    dp[1] = abs(stone[1] - stone[0]);
    for( int i = 2 ; i < n ; i++ ){
        dp[i] = min( abs(stone[i] - stone[i-1]) + dp[i-1], abs(stone[i] - stone[i-2]) + dp[i-2]);
    }

    cout << dp[n-1];
}