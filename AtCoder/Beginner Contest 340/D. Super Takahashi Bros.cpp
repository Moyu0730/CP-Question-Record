/* Question : AtCoder Beginner Contest 340 - D. Super Takahashi Bros */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define priq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define F first
#define S second
#define X first
#define Y second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
const int INF = 10000;
int n, a, b, x, dis[MAXN];
vector<vector<pii>> graph;
queue<int> q;

void dij( int root ){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, root});
    dis[root] = 0;

    while( !pq.empty() ){
        int d = pq.top().F;
        int node = pq.top().S;
        pq.pop();

        if( d > dis[node] ) continue;
        for( auto i : graph[node] ){
            int v = i.F;
            int w = i.S;
            if( d + w < dis[v] ){
                dis[v] = d + w;
                pq.push({dis[v], v});
            }
        }
    }
}

signed main(){
    opt;
    cin >> n;

    graph.resize(n+5);
    for( int i = 1 ; i <= n-1 ; i++ ){
        cin >> a >> b >> x;
        graph[i].pb({i+1, a});
        graph[i].pb({x, b});
    }

    mem(dis, INF);
    dij(1);

    cout << dis[n] << "\n";
}