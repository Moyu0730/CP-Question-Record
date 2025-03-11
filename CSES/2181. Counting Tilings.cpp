/* Question : CSES 2181. Counting Tilings */

#include<bits/stdc++.h>
using namespace std;

/* Pragma */
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

/* Self Define */
#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pirq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define vsort(x) sort(x.begin(), x.end());
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define F first
#define S second
#define X first
#define Y second
#define int long long
#define ll long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;
const int MEMINF = 0x3F;
const int MEMINF_VAL = 0x3F3F3F3F;
const int MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int n, m, dp[1000 + 5][10 + 5][1 << 10 + 1];

signed main(){
    opt;

    cin >> n >> m;
    
    dp[0][0][(1<<n)-2] = 1;
    for( int i = 0 ; i < m ; i++ ){
        for( int j = 0 ; j < n ; ++j ){
            for( int bit = 0 ; bit < (1 << n) ; ++bit ){
                if( j == 0 ){
                    if( i > 0 ) dp[i][j][bit] = dp[i-1][n-1][bit ^ (1 << j)];
                }else{
                    if( bit & (1 << j) ){
                        dp[i][j][bit] = dp[i][j-1][bit ^ (1 << j)]; // for horizontal
                        
                        if( bit & (1 << (j-1)) ) dp[i][j][bit] += dp[i][j-1][bit ^ (1 << j-1)]; // for vertical
                    }else{
                        dp[i][j][bit] = dp[i][j-1][bit ^ (1 << j)];
                    }
                }

                dp[i][j][bit] %= Mod;
            }
        }
    }

    cout << dp[m-1][n-1][0] << "\n";
}