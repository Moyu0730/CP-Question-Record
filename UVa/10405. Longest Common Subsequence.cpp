#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MEM(_ARRAY, _VAL) memset(_ARRAY, _VAL, sizeof(_ARRAY))
#define F first
#define sz size()
#define S second
#define pb push_back
#define vc(_TYPE) vector<_TYPE>

const int MAXN = 1e3 + 50;
const int Mod = 1e9 + 7;

string a, b;
int dp[MAXN][MAXN];

signed main(){
    while( getline(cin, a) && getline(cin, b) ){
        MEM(dp, 0);

        for( int i = 1 ; i <= a.sz ; ++i ){
            for( int j = 1 ; j <= b.sz ; ++j ){
                if( a[i-1] == b[j-1] ) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        cout << dp[a.sz][b.sz] << "\n";
    }
}