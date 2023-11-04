/* Question : AtCoder Beginner Contest 327 - D. Good Tuple Problem */

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

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
int n, m, a[MAXN], b[MAXN], color[MAXN];
bool valid = true;
vector<vector<int>> graph;

void dfs( int node, int c ){
    color[node] = c;

    for( auto i : graph[node] ){
        if( color[i] == color[node] ){
            valid = false;
            return;
        }

        if( !color[i] && c == 1 ) dfs(i, 2);
        else if( !color[i] && c == 2 ) dfs(i, 1);
    }

    return;
}

signed main(){
    opt;
    cin >> n >> m;

    graph.resize(n+5);
    for( int i = 0 ; i < m ; i++ ) cin >> a[i];
    for( int i = 0 ; i < m ; i++ ){
        cin >> b[i];
        graph[a[i]].pb(b[i]);
        graph[b[i]].pb(a[i]);
    }

    for( int i = 1 ; i <= n ; i++ ){
        if( !color[i] ) dfs(i, 1);
        if( valid == false ) break;
    }

    if( valid == false ) cout << "No\n";
    else cout << "Yes\n";
}