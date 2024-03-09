/* Question : TCIRC d070. P-6-7. LCS */

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
const int MAXN = 500 + 50;
const int Mod = 1e9 + 7;
const int INF = 1e9;
string a, b;
int dp[MAXN][MAXN];

signed main(){
    opt;
    cin >> a >> b;

    for( int i = 1 ; i <= a.size() ; i++ ){
        for( int j = 1 ; j <= b.size() ; j++ ){
            if( a[i-1] == b[j-1] ) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
        }
    }

    cout << dp[a.size()][b.size()] << "\n";
}