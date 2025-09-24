#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MEM(_ARRAY, _VAL) memset(_ARRAY, _VAL, sizeof(_ARRAY))
#define F first
#define S second
#define pb push_back
#define vc(_TYPE) vector<_TYPE>

const int MAXN = 1e7 + 50;
const int Mod = 1e9 + 7;
int n, s;
int dp[70][70][2];

void prefix(){
    dp[0][0][0] = dp[1][1][0] = dp[1][0][1] = 1;
    for( int n = 2 ; n <= 65 ; n++ ){
        for( int s = 0 ; s <= n ; s++ ){
            dp[n][s][0] += dp[n - 1][s - 1][0] + dp[n - 1][s - 1][1];
            dp[n][s][1] += dp[n - 1][s][1] + dp[n - 1][s + 1][0];
        }
    }
}

signed main(){
    prefix();
    while(cin >> n >> s && ( n > 0 || s > 0 ) ){
        cout << dp[n][s][0] + dp[n][s][1] << "\n";
    }
}