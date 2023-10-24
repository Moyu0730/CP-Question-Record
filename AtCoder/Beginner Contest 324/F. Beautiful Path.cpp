/* Question : AtCoder Beginner Contest 324 - F. Beautiful Path */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define priq(type) priority_queue<type, vector<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pdi pair<double, int>
#define pb push_back
#define f first
#define s second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
int n, m, u, v, b, c;
double dis[MAXN], dp[MAXN];
vector<vector<pair<int, pdd>>> graph;

bool check( int root, double val ){
    mem(dp, -1e8);
    dp[root] = 0;
    for( int i = root ; i <= n ; i++ ){
        for( auto it : graph[i] ){
            int v = it.f;
            double b = it.s.f;
            double c = it.s.s;
            double w = b - (c * val);

            dp[v] = max(dp[v], dp[i] + w);
        }
    }

    return dp[n] >= 0;
}

signed main(){
    opt;
    cin >> n >> m;
    graph.resize(n+5);
    for( int i = 0 ; i < m ; i++ ){
        cin >> u >> v >> b >> c;
        graph[u].pb({v, {b, c}});
    }

    double dif = 2e9;
    double l = 0, r = 2e9;
    double res = 0;
    while( dif >= 1e-9 ){
        double mid = (l + r) / 2.0;
        
        if( check(1, mid) ) l = mid;
        else r = mid;

        dif = abs(res - mid);
        res = mid;
    }
    
    cout << fixed << setprecision(16) << res << "\n";
}