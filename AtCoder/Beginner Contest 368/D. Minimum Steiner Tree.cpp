/* Question : AtCoder Beginner Contest 368 - D. Minimum Steiner Tree */

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
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
const int LLINF = 1e18;
const int INF = 1e9;

int n, k, a, b, res, used[MAXN];
vector<vector<int>> edge;

bool dfs( int cnt, int fa ){
    bool valid = used[cnt];

    for( auto i : edge[cnt] ){
        if( i == fa ) continue;

        valid |= dfs(i, cnt); 
    }

    res += valid;
    return valid;
}

signed main(){
    #ifndef LOCAL
        opt;
    #endif

    cin >> n >> k;

    edge.resize(n+5);
    for( int i = 0 ; i < n-1 ; i++ ){
        cin >> a >> b;
        edge[a].pb(b);
        edge[b].pb(a);
    }

    int node;
    for( int i = 0 ; i < k ; i++ ){
        cin >> node;
        used[node] = 1;
    }

    dfs(root, -1);
    cout << res << "\n";
}