/* Question : CSES 1131. Tree Diameter */

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
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;

/***** 1. DFS Solution *****/
int endPoint, n, a, b, maxDepth;
vector<vector<int>> tree;

void dfs( int u, int fa, int depth ){
    if( depth > maxDepth ){
        endPoint = u;
        maxDepth = depth;
    }

    for( auto v : tree[u] ){
        if( v == fa ) continue;

        dfs(v, u, depth+1);
    }

    return;
}

signed main(){
    opt;
    cin >> n;
    tree.resize(n+5);
    for( int i = 1 ; i < n ; i++ ){
        cin >> a >> b;
        tree[a].pb(b);
        tree[b].pb(a);
    }

    dfs(1, 0, 0);

    maxDepth = 0;
    dfs(endPoint, 0, 0);

    cout << maxDepth << "\n";
}


/***** 2. Tree DP Solution *****/

int n, a, b, root, res, dp[MAXN][5];
vector<vector<int>> tree;

void dim( int node, int fa ){
    dp[node][1] = dp[node][2] = 0;  

    for( int v : tree[node] ){
        if( v == fa ) continue;
        
        dim(v, node);
        int w = dp[v][1] + 1;

        if( w > dp[node][1] ){
            dp[node][2] = dp[node][1];
            dp[node][1] = w;
        }else if( w > dp[node][2] ){
            dp[node][2] = w;
        }
    }

    res = max( res, dp[node][1] + dp[node][2] );
}

signed main(){
    opt;
    cin >> n;
    tree.resize(n+5);
    for( int i = 1 ; i < n ; i++ ){
        cin >> a >> b;
        tree[a].pb(b);
        tree[b].pb(a);
    }

    dim(1, 0);
    
    cout << res << "\n";
}