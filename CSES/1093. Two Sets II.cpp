/* Question : CSES 1093. Two Sets II */

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
#define sortV(x) sort(x.begin(), x.end());
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

int n, sum, dp[500 + 50][70000 + 50];

signed main(){
    opt;

    cin >> n;
    
    sum = n * ( n + 1 ) / 2;
    if( sum % 2 == 1 ) cout << "0\n";
    else{
        sum /= 2;
        for( int i = 1 ; i <= n ; ++i ){
            for( int j = 0 ; j <= sum ; ++j ){
                if( j == 0 ) dp[i][j] = 1;
                else dp[i][j] = dp[i-1][j] + ( i <= j ? dp[i-1][j-i] : 0 );

                dp[i][j] %= Mod;
            }
        }

        cout << dp[n][sum] << "\n";
    }
}