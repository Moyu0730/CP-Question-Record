/* Question : CSES 1643. Maximum Subarray Sum */

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
#define x first
#define y second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
int n, res, arr[MAXN], dp[MAXN];

signed main(){
    opt;
    cin >> n;
    for( int i = 0 ; i < n ; i++ ) cin >> arr[i];

    res = arr[0];
    dp[0] = arr[0];
    for( int i = 1 ; i < n ; i++ ){
        dp[i] = max(arr[i], arr[i] + dp[i-1]);
        res = max(res, dp[i]);
    }   

    cout << res << "\n";
}