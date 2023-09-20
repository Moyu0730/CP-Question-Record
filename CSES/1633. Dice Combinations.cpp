/* Question : CSES 1633 */

#include<iostream>
#include<vector>
using namespace std;
 
int n, m, mod = 1e9 + 7;
vector<int> dp;
 
int f( int x ){
	if( dp[x] != 0 ) return dp[x];

    for( int i = 1 ; i <= 6 ; i++ ){
        if( x - i > 0 ){
            dp[x] = f(x-i);
            dp[x] % mod;
        }
    }

    return dp[x];
}
 
signed main (){
    cin >> n;
    dp.resize(n+5);
    dp[0] = dp[1] = 0;
    cout << f(n);
}