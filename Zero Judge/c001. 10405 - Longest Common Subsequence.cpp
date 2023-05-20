/* Question : OJ Number */

/*
 * String1 : Len = n, String2 : Len = m
 * 定義： dp[i][j] = n ~ i (Start From : 0, Contain i) & m ~ j (Start From : 0, Contain j)'s LCS
 * 轉移：
 *  if( String1[i] == String2[j] ) dp[i][j] = dp[i+1][j+1] + 1;
 *  else dp[i][j] = max( dp[i+1][j], dp[i][j+1] );
 * 基底：
 *  dp[n][j] = dp[i][m] = 0
 */

#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<math.h>
#include<algorithm>
#include<cstring>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int MAXN = 1e3 + 50;
const int Mod = 1e9 + 7;
int dp[MAXN][MAXN];
string s1, s2;

signed main(){
    // opt;
    while( cin >> s1 >> s2 ){
        int n = s1.size();
        int m = s2.size();
        memset(dp, 0, sizeof(dp));
        for( int i = n-1 ; i >= 0 ; i-- ){
            for( int j = m-1 ; j >= 0 ; j-- ){
                if( s1[i] == s2[j] ) dp[i][j] = dp[i+1][j+1] + 1;
                else dp[i][j] = max( dp[i+1][j], dp[i][j+1] );
            }
        }
        cout << dp[0][0] << "\n";
    }
}