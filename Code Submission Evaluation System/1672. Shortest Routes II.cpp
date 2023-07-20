/* Question : CSES 1672. Shortest Routes II */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define f first
#define s second

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 5e2 + 50;
const int Mod = 1e9 + 7;
long long n, m, q, a, b, w;
long long graph[MAXN][MAXN], dp[MAXN][MAXN];

signed main(){
    opt;

    cin >> n >> m >> q;
    mem(graph, 1e15);
    for( int i = 0 ; i < m ; i++ ){
        cin >> a >> b >> w;
        graph[a][b] = min(graph[a][b], w);
        graph[b][a] = min(graph[a][b], w);
    }

    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= n ; j++ ){
            dp[i][j] = ( i == j ) ? 0 : graph[i][j]; 
        }
    }

    for( int k = 1 ; k <= n ; k++ ){
        for( int i = 1 ; i <= n ; i++ ){
            for( int j = 1 ; j <= n ; j++ ){
                if( i == j ) continue;
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    while( q-- ){
        cin >> a >> b;
        if( dp[a][b] < 1e15 ) cout << dp[a][b] << "\n";
        else cout << "-1\n";
    }
}