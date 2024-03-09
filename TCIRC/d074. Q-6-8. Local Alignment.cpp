/* Question : TCIRC d074. Q-6-8. Local Alignment */

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
const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 500 + 50;
const int Mod = 1e9 + 7;
const int INF = 1e9;
string a, b;
int res, dp[MAXN][MAXN];

int cmp( int a, int b, int c, int d ){
    vector<int> v;

    v.pb(a);
    v.pb(b);
    v.pb(c);
    v.pb(d);

    sort( v.begin(), v.end() );

    return v[3];
}

signed main(){
    opt;
    cin >> a >> b;

    for( int i = 1 ; i <= a.size() ; i++ ){
        for( int j = 1 ; j <= b.size() ; j++ ){
            if( a[i-1] == b[j-1] ) dp[i][j] = max(0, dp[i-1][j-1]) + 8;
            else dp[i][j] = cmp(0, dp[i-1][j-1] - 5, dp[i][j-1] - 3, dp[i-1][j] - 3);
        }
    }

    for( int j = 1 ; j <= b.size() ; j++ ){
        for( int i = 1 ; i <= a.size() ; i++ ) res = max(res, dp[i][j]);
    }

    cout << res << "\n";
}