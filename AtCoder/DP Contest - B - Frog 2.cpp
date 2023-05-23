/* Question : AtCoder DP Contest - A - Frog 2 */

/*
 * 定義： dp[i] = The Less Cost from 0 to i (Include)
 * 轉移： 
 *          if( i < k ) dp[i] = min( abs(stone[i] - stone[i-1]) + dp[i-1], ... to  abs(stone[i] - stone[i-i]) + dp[i-i]);
 *          else  dp[i] = min( abs(stone[i] - stone[i-1]) + dp[i-1], ... to  abs(stone[i] - stone[i-k]) + dp[i-k]);
 * dp[i] = i < k ? min_res(i, i) : min_res(i, k);
 * 基底： dp[0] = 0
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
int n, res, k;
int stone[MAXN], dp[MAXN];

int min_res( int ind, int dif ){
    int res = 1e9;
    for( int i = 1 ; i <= dif ; i++ ) res = min(res, ( abs(stone[ind] - stone[ind-i]) + dp[ind-i] ) );
    return res;
}

signed main(){
    opt;
    cin >> n >> k;
    for( int i = 0 ; i < n ; i++ ) cin >> stone[i];
    for( int i = 1 ; i < n ; i++ ) dp[i] = i < k ? min_res(i, i) : min_res(i, k);
    cout << dp[n-1];
}