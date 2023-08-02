/* Question : CSES 1195. Flight Discount */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define f first
#define s second
#define pb push_back
#define pirq(type) priority_queue<type, vector<type>, greater<type>>
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
int n, m, a, b, w, dis[MAXN];
vector<vector<pii>> graph;

void dij( int root ){
    pirq(pii) pq;
    pq.push({0, root});
    dis[root] = 0;
    while( !pq.empty() ){
        int d = pq.top().f;
        int node = pq.top().s;
        pq.pop();

        if( d > dis[node] ) continue;
        for( auto i : graph[node] ){
            int v = i.f;
            int w = i.s;
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
    graph.resize(n+n+5);
    for( int i = 0 ; i < m ; i++ ){
        cin >> a >> b >> w;
        graph[a].pb({b, w});
        graph[a].pb({b+n, w/2});
        graph[a+n].pb({b+n, w});
    }

    mem(dis, 0x3F);
    dij(1);

    cout << dis[n+n] << "\n";
}