/* Question : AtCoder Beginner Contest 396 - D. Minimum XOR Path */

#include<bits/stdc++.h>
using namespace std;

/* Pragma */
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

/* Self Define */
#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pirq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define vsort(x) sort(x.begin(), x.end());
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define F first
#define S second
#define X first
#define Y second
#define int long long
#define ll long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e1 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;
const int MEMINF = 0x3F;
const int MEMINF_VAL = 0x3F3F3F3F;
const int MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int n, m, u, v, w, res;
vector<vector<pii>> edge;
bool used[MAXN];

void dfs( int root, int val ){
    if( root == n ){
        res = min(res, val);
        return;
    }

    for( auto [nxt, w] : edge[root] ){
        if( used[nxt] ) continue;
    
        used[nxt] = true;
        dfs(nxt, val ^ w);
        used[nxt] = false;
    }
}

signed main(){
    opt;
    
    cin >> n >> m;

    edge.resize(n + 5);

    for( int i = 0 ; i < m ; ++i ){
        cin >> u >> v >> w;

        edge[u].pb({v, w});
        edge[v].pb({u, w});
    }

    mem(used, false);

    res = LLINF;

    used[1] = true;
    dfs(1, 0);

    cout << res << "\n";
}