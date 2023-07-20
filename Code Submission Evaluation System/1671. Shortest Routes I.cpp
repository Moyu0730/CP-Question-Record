/* Question : CSES 1671. Shortest Routes I */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mem(x) memset(x, 0x3F, sizeof(x));
#define int long long

const int MAXN = 1e5 + 50;
const int Mod = 1e9 + 7;
int n, m, v, u, w, res;
int dis[MAXN];
vector<vector<pair<int, int> > > G;

void dij( int root ){
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push({0, root});
    dis[root] = 0;
    while( !pq.empty() ){
        int node = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if( d > dis[node] ) continue;
        for( auto i : G[node] ){
            int v = i.first;
            int w = i.second;
            if( d + w < dis[v] ){
                dis[v] = d + w;
                pq.push({dis[v], v});
            }
        }
    }
}

signed main(){
    opt;
    cin >> n >> m;
    G.resize(n+5);
    for( int i = 0 ; i < m ; i++ ){
        cin >> u >> v >> w;
        G[u].push_back({v, w});
    }

    mem(dis);
    dij(1);
    for( int i = 1 ; i <= n ; i++ ) cout << dis[i] << " ";
}