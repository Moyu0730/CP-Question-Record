/* Question : Luogu P3379.【Template】LCA */

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
const int MAXN = 1e6 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 1e18;
const int INF = 1e9;

int n, m, s, x, y, idx;
int v[MAXN], first[MAXN], nxt[MAXN], dep[MAXN], fa[MAXN][25];

void add( int a, int b ){
    idx++;
    v[idx] = b;
    nxt[idx] = first[a];
    first[a] = idx;
}

void dfs( int u, int father ){
    dep[u] = dep[father] + 1;
    for( int i = 1 ; (1<<i) <= dep[u] ; i++ ){
        fa[u][i] = fa[ fa[u][i-1] ][i-1];
    }
    for( int i = first[u] ; i ; i = nxt[i] ){
        int p = v[i];
        if(p == father) continue;
        fa[p][0] = u;
        dfs(p, u);
    }
}

int lca( int a, int b ){
    if( dep[a] < dep[b] ) swap(a, b);

    for( int i = 20 ; i >= 0 ; i-- ){
        if( dep[fa[a][i]] >= dep[b] )
            a = fa[a][i];
        if( a == b ) return a;
    }

    for( int i = 20 ; i >= 0 ; i-- ){
        if( fa[a][i] != fa[b][i] ){
            a = fa[a][i];
            b = fa[b][i];
        }
    }

    return fa[a][0];
}

signed main(){
    opt;

    cin >> n >> m >> s;
    for( int i = 1 ; i < n ; i++ ){
        cin >> x >> y;
        add(x, y); // Tere is an edge Between a and b
        add(y, x);
    }

    dfs(s, 0);

    for( int i = 1 ; i <= m ; i++ ){
        cin >> x >> y;
        cout << lca(x, y) << "\n";
    }
}