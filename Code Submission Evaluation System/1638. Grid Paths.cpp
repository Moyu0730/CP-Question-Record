/* Question : CSES 1638 */

#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<math.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int MAXN = 1e3 + 50;
const int Mod = 1e9 + 7;
char grid[MAXN][MAXN];
int n, dp[MAXN][MAXN];

/********** 2. Bottom Up Solution **********/
bool flag = true;
signed main(){
    opt;

    // Input
    cin >> n;
    for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j < n ; j++ ){
            cin >> grid[i][j];

            if( i == 0 && j == 0 && grid[i][j] == '*' ){
                cout << 0;
                flag = false;
                break;
            }
            
            if( grid[i][j] == '*' ) dp[i][j] = 0;
        }
    }

    // Set Known Value
    dp[n-1][n-1] = grid[n-1][n-1] == '*' ? 0 : 1;

    for ( int i = n - 1 ; i >= 0 ; i-- ){
        for( int j = n - 1 ; j >= 0 ; j-- ){
            if( grid[i][j] == '*' ) continue;
            
            // Border
            if( i + 1 < n ) dp[i][j] += dp[i+1][j];
            if( j + 1 < n ) dp[i][j] += dp[i][j+1];

            dp[i][j] %= Mod;
        }
    }

    if( flag ) cout << dp[0][0];
}
/**********/

/********** 1. Top Down Solution - TLE **********/
// int sol( int i, int j ){
//     if( dp[i][j] != 0 ) return dp[i][j];
//     if( i == n || j == n ) return 0;

//     // Down
//     if( grid[i+1][j] != '*' && i+1 < n ) dp[i][j] += sol(i+1, j);

//     // Right
//     if( grid[i][j+1] != '*' && j+1 < n ) dp[i][j] += sol(i, j+1);

//     dp[i][j] %= Mod;

//     return dp[i][j];
// }


// bool flag = true;
// signed main(){
//     opt;

//     // Input
//     cin >> n;
//     for( int i = 0 ; i < n ; i++ ){
//         for( int j = 0 ; j < n ; j++ ){
//             cin >> grid[i][j];

//             if( i == 0 && j == 0 && grid[i][j] == '*' ){
//                 cout << 0;
//                 flag = false;
//                 break;
//             }
            
//             if( grid[i][j] == '*' ) dp[i][j] = 0;
//         }
//     }

//     // Set Known Value
//     dp[n-1][n-1] = grid[n-1][n-1] == '*' ? 0 : 1;

//     if( flag ) cout << sol(0, 0);
// }
/**********/