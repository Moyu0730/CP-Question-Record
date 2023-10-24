/* Question : Atcoder DP Contest - F. LCS */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define priq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define F first
#define S second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 3e3 + 50;
const int Mod = 1e9 + 7;
string s, t, res;
int dp[MAXN][MAXN];

signed main(){
    opt;
    cin >> s >> t;

    int n = s.size(), m = t.size();
    for( int i = n-1 ; i >= 0 ; i-- ){
        for( int j = m-1 ; j >= 0 ; j-- ){
            if( s[i] == t[j] ) dp[i][j] = dp[i+1][j+1] + 1;
            else dp[i][j] = max( dp[i+1][j], dp[i][j+1] );
        }
    }
    
    int i = 0, j = 0;
    while( i != n && j != m ){
        if( s[i] == t[j] ){
            res += s[i];
            i++;
            j++;
        }else if( dp[i+1][j] > dp[i][j+1] ) i++;
        else j++;
    }
    
    cout << res << "\n";
}