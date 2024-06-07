/* Question : Zerojudge b967. 4. Blood Relationship */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
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
const int MAXN = 1e5 + 50;
const int Mod = 1e9 + 7;
const int INF = 1e9;

int n, a, b, node, res;
bool used[MAXN];
vector<vector<int>> edge;

void dfs( int root, int dis ){
    if( dis > res ){
        node = root;
        res = dis;
    }

    for( auto i : edge[root] ){
        if( used[i] ) continue;

        used[i] = true;
        dfs(i, dis+1);   
    }
}

signed main(){
    opt;
    cin >> n;

    edge.resize(n+5);
    for( int i = 0 ; i < n-1 ; i++ ){
        cin >> a >> b;

        edge[a].pb(b);
        edge[b].pb(a);
    }

    res = -1;
    mem(used, false);
    used[0] = true;
    dfs(0, 0);

    // cout << node << "\n";

    res = -1;
    mem(used, false);
    used[node] = true;
    dfs(node, 0);

    cout << res << "\n";
}