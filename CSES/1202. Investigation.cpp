/* Question : CSES 1202. Investigation */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pirq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pdd pair<double, double>
#define pb push_back
#define f first
#define s second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e5 + 50;
const int Mod = 1e9 + 7;
int n, m, u, v, w, dis[MAXN];
vector<vector<pii>> graph;

struct Node{
    int maxf = 0, minf = 0, routes = 0;
} dp[MAXN];

void dij( int root ){
    pirq(pii) pq;
    pq.push({0, root});
    dis[root] = 0;
    dp[root].routes = 1;
    while( !pq.empty() ){
        int d = pq.top().f;
        int node = pq.top().s;
        pq.pop();

        if( d > dis[node] ) continue;
        for( auto i : graph[node] ){
            int v = i.f;
            int w = i.s; // Weight
            if( d + w == dis[v] ){
                dp[v].routes = ( dp[v].routes + dp[node].routes ) % Mod;
                dp[v].maxf = max( dp[v].maxf, dp[node].maxf + 1);
                dp[v].minf = min( dp[v].minf, dp[node].minf + 1);
            }else if( d + w < dis[v] ){
                dis[v] = d + w;
                dp[v].routes = dp[node].routes;
                dp[v].maxf = dp[node].maxf + 1; 
                dp[v].minf = dp[node].minf + 1;
                pq.push({dis[v], v});
            }
        }
    }
}

signed main(){
    opt;
    cin >> n >> m;
    graph.resize(n+5);
    for( int i = 0 ; i < m ; i++ ){
        cin >> u >> v >> w;
        graph[u].pb({v, w});
    }

    mem(dis, 0x3F);
    dij(1);

    cout << dis[n] << " " << dp[n].routes << " " << dp[n].minf << " " << dp[n].maxf << "\n";
}