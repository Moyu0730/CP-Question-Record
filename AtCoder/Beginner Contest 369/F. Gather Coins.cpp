/* Question : AtCoder Beginner Contest 369 - F. Gather Coins */

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
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
const int LLINF = 1e18;
const int INF = 1e9;

int h, w, n, r, c;
vector<pii> coin;

signed main(){
    #ifndef LOCAL
        opt;
    #endif

    cin >> h >> w >> n;
    for( int i = 0 ; i < n ; i++ ){
        cin >> r >> c;
        coin.pb({r, c});
    }

    sort(coin.begin(), coin.end());
    
    vector<int> dp(n+5, INF), id(n+5, -1), pre(n+5);
    for( int i = 0 ; i < n ; i++ ){
        int it = upper_bound(dp.begin(), dp.end(), coin[i].S) - dp.begin();
        dp[it] = coin[i].S;
        id[it] = i;
        pre[i] = (it ? id[it-1] : -1);
    }

    int m = n;
    while( id[m] == -1 ) m--;
    vector<pii> res = { {h, w} };
    int cnt = id[m];
    while( cnt != -1 ){
        res.pb(coin[cnt]);
        cnt = pre[cnt];
    }
    res.pb({1, 1});

    cout << m+1 << "\n";
    for( int i = res.size()-1 ; i > 0 ; i-- ){
        int difD = res[i-1].F - res[i].F;
        int difR = res[i-1].S - res[i].S;

        while( difD-- ) cout << "D";
        while( difR-- ) cout << "R";
    }
    cout << "\n";
}