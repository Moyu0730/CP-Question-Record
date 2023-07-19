/* Question : Luogu P1396. Rescue */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define f first
#define s second

const int MAXN = 1e4 + 50;
const int Mod = 1e9 + 7;
int n, m, start, t, v, u, w;
int dis[MAXN];
vector<vector<pair<int, int> > > G;

void dij( int root ){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, root});
    dis[root] = 0;
    while( !pq.empty() ){
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if( d > dis[node] ) continue;
        for( auto i : G[node] ){
            int v = i.first;
            int w = max(d, i.second);
            if( w < dis[v] ){
                dis[v] = w;
                pq.push({dis[v], v});
            }
        }
    }
}

signed main(){
    opt;
    cin >> n >> m >> start >> t;
    
    G.resize(n+5);
    for( int i = 0 ; i < m ; i++ ){
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    mem(dis, 0x3F);
    dij(start);

    cout << dis[t] << "\n";
}