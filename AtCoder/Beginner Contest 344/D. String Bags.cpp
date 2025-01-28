/* Question : AtCoder Beginner Contest 344 - D. String Bags */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pirq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
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
const int MAXN = 1e2 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;
const int MEMINF = 0x3F;
int n, a, dp[MAXN][MAXN];
string t;
vector<vector<string>> str;

signed main(){
    opt;
    
    cin >> t >> n;

    str.resize(n);
    for( int i = 0 ; i < n ; ++i ){
        cin >> a;

        str[i].resize(a);
        for( int j = 0 ; j < a ; ++j ) cin >> str[i][j];
    }

    mem(dp, MEMINF);

    dp[0][0] = 0;
    for( int i = 0 ; i < n ; ++i ){
        for( int pre = 0 ; pre < MAXN ; ++pre ) dp[i+1][pre] = pre == 0 ? 0 : dp[i][pre];
        
        for( int j = 0 ; j < str[i].size() ; ++j ){
            /* Preprocessing */
            string cnt = str[i][j];
            int len = cnt.size();
            

            for( int k = 0 ; k + cnt.size() <= t.size() ; ++k ){

                /* Compare */
                bool flag = true;
                for( int it = 0 ; it < cnt.size() ; ++it ){
                    if( cnt[it] != t[k+it] ){
                        flag = false;
                        break;
                    }
                }

                if( flag ) dp[i+1][k+len] = min(dp[i+1][k+len], dp[i][k] + 1);
            }
        }
    }

    if( dp[n][t.size()] > 100 ) cout << "-1\n";
    else cout << dp[n][t.size()] << "\n";
}