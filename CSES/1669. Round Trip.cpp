/* Question : CSES 1669. Round Trip */

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
#define x first
#define y second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e5 + 50;
const int Mod = 1e9 + 7;
int n, m, u, v, fa[MAXN];
vector<vector<int>> graph;
vector<int> res;

void dfs( int node, int pre ){
    for( auto i : graph[node] ){
        if( i == pre ) continue;
        if( fa[i] ){
            res.pb(node);
            while( res.back() != i ){
                res.pb(fa[res.back()]);
            }
            res.pb(node);

            cout << res.size() << "\n";
            for( auto v : res ) cout << v << " ";
            cout << "\n";

            exit(0);
        }
        fa[i] = node;
        dfs(i, node);
    }

    return;
}

signed main(){
    opt;
    cin >> n >> m;

    graph.resize(n+5);
    for( int i = 0 ; i < m ; i++ ){
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    for( int i = 1 ; i <= n ; i++ ){
        if( !fa[i] ){
            fa[i] = i;
            dfs(i, -1);
        }
    }

    cout << "IMPOSSIBLE\n";
}