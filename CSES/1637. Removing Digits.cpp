/* Question : CSES 1637. Removing Digits */

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
const int MAXN = 1e6 + 50;
const int Mod = 1e9 + 7;
int num, last, tmp, dp[MAXN];

signed main(){
    opt;
    cin >> num;

    mem(dp, 1000000);
    dp[0] = 0;
    for( int i = 1 ; i <= 9 ; i++) dp[i] = 1;

    for( int i = 10 ; i <= num ; i++ ){
        tmp = i;
        while( tmp > 0 ){
            last = tmp % 10;
            dp[i] = min(dp[i], dp[i-last] + 1);
            tmp /= 10;
        }
    }

    cout << dp[num] << "\n";
}