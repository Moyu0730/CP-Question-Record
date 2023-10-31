/* Question : Atcoder DP Contest - D. Knapsack 1 */

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
const int MAXN = 1e2 + 50;
const int Mod = 1e9 + 7;
int n, w, weight[MAXN], val[MAXN], dp[100050];

signed main(){
    opt;
    cin >> n >> w;
    for( int i = 0 ; i < n ; i++ ) cin >> weight[i] >> val[i];

    for( int i = 0 ; i < n ; i++ ){
        for( int j = w ; j >= weight[i] ; j-- ) dp[j] = max( dp[j], dp[j-weight[i]] + val[i] );
    }

    cout << dp[w] << "\n";
}