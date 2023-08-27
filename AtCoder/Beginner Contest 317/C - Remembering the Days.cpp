/* Question : AtCoder Beginner Contest 317 - C - Remembering the Days */

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
const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
int n, m, u, v, w, res;
vector<vector<pii>> graph;
int dis[MAXN];
bool used[MAXN];

void dfs( int node, int d ){
    dis[node] = max(dis[node], d);
    res = max(res, dis[node]);

    for( auto i : graph[node] ){
        if( used[i.f] == true ) continue;

        used[i.f] = true;
        dfs(i.f, d + i.s);
        used[i.f] = false;
    }
}

signed main(){
    opt;
    cin >> n >> m;
    graph.resize(n+5);
    for( int i = 0 ; i < m ; i++ ){
        cin >> u >> v >> w;
        graph[u].pb({v, w});
        graph[v].pb({u, w});
    }

    res = 0;
    for( int i = 1 ; i <= n ; i++ ){
        mem(dis, 0);
        mem(used, false);
        used[i] = true;
        dfs(i, 0);
    }
    
    cout << res << "\n";
}