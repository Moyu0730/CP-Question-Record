/* Question : AtCoder Beginner Contest 315 - F - Shortcuts */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pirq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define f first
#define s second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e4 + 50;
const int Mod = 1e9 + 7;
vector<pii> node;
int n, x, y, ksm[50];
double dp[MAXN][50];

double dis( int u, int v ){
    int dx = abs( node[u].f - node[v].f );
    int dy = abs( node[u].s - node[v].s );

    return sqrt( dx * dx + dy * dy );
}

int pen( int t ){
    if( t == 1 ) return ksm[0];
    else return ksm[t-1] - ksm[t-2];
}

signed main(){
    opt;
    cin >> n;
    for( int i = 0 ; i < n ; i++ ){
        cin >> x >> y;
        node.pb({x, y});
    }

    ksm[0] = 1;
    for( int i = 1 ; i <= 30 ; i++ ) ksm[i] = ksm[i-1] * 2;

    for( int i = 1 ; i <= n ; i++ ){
        for( int c = 0 ; c <= 30 ; c++ ){
            dp[i][c] = c == 0 ? dp[i-1][c] + dis(i-1, i) : min(dp[i-1][c] + dis(i-1, i), dp[i-1][c-1] + pen(c) );
        }
    }

    for( int i = 1 ; i <= n ; i++ ){
        for( int c = 0 ; c <= 6 ; c++ ){
            cout << dp[i][c] << " ";
        }
        cout << "\n";
    }

    double ans = 1e9;
    for( int i = 0 ; i <= 30 ; i++ ) ans = min(ans, dp[n][i]);
    
    cout << ans << "\n";
}