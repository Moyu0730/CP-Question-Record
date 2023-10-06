/* Question : CSES 1666. Building Roads */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define priq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define f first
#define s second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e5 + 50;
const int Mod = 1e9 + 7;
int n, m, u, v;
bool visited[MAXN];
vector<int> res;
vector<vector<int>> graph;

void dfs( int node ){
    visited[node] = true;

    for( auto i : graph[node] ){
        if( visited[i] == true ) continue;
        dfs(i);
    }

    return;
}

signed main(){
    opt;
    cin >> n >> m;
    graph.resize(n+1);
    for( int i = 0 ; i < m ; i++ ){
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    dfs(1);

    res.pb(1);
    for( int i = 2 ; i <= n ; i++ ){
        if( visited[i] != true ){
            res.pb(i);
            dfs(i);
        }
    }

    cout << res.size() - 1 << "\n";
    for( int i = 0 ; i < res.size() - 1 ; i++ ) cout << res[i] << " " << res[i+1] << "\n";
}