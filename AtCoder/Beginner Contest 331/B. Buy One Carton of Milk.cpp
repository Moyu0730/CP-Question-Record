/* Question : AtCoder Beginner Contest 331 - B. Buy One Carton of Milk */

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
#define X first
#define Y second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e4 + 50;
const int Mod = 1e9 + 7;
int n, m, s, l, dp[MAXN];
pii price[MAXN];

signed main(){
    opt;
    cin >> n >> s >> m >> l;
    price[0] = {6, s};
    price[1] = {8, m};
    price[2] = {12, l};

    mem(dp, 1000000);
    dp[0] = 0;
    for( int i = 1 ; i <= n + 12 ; i++ ){
        for( int it = 0 ; it < 3 ; it++ ){
            int amt = price[it].F;
            int cost = price[it].S;
            if( i - amt >= 0 ) dp[i] = min(dp[i], dp[i-amt] + cost);
        }
    }

    int res = 100000000;
    for( int i = n ; i <= n + 12 ; i++ ) res = min(res, dp[i]);
    
    cout << res << "\n";
}