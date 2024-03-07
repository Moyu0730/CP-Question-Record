/* Question : TCIRC d052. AP325 P-4-13. Maximum Continuous Subpermutation（Same As P-5-2） */

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
const int MAXN = 1e5 + 50;
const int Mod = 1e9 + 7;
const int INF = 1e9;
int n, res, arr[MAXN], dp[MAXN];

signed main(){
    opt;
    cin >> n;
    dp[0] = 0;
    for( int i = 1 ; i <= n ; i++ ){
        cin >> arr[i];
        dp[i] = max(arr[i], dp[i-1] + arr[i]);
        res = max(res, dp[i]);
    }

    cout << res << "\n";
}