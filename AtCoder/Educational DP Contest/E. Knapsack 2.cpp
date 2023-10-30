/* Question : Atcoder DP Contest - E. Knapsack 2 */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define priq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define f first
#define s second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
int n, w, weight, val, res;
vector<int> dp;

signed main(){
    opt;
    cin >> n >> w;

    dp.resize(100050, 1e10);
    dp[0] = 0;
    for( int i = 0 ; i < n ; i++ ){
        cin >> weight >> val;
        for( int j = 100050 ; j >= val ; j-- ){
            dp[j] = min(dp[j], dp[j-val] + weight);
        }
    }

    for( int i = 1 ; i < 100050 ; i++ ){
        if( dp[i] <= w ) res = i;
    }

    cout << res << "\n";
}