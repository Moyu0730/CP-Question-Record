/* Question : CSES 1197. Cycle Finding */

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
const int MAXN = 3e3 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;
const int MEMINF = 0x3F;
const int MEMINF_VAL = 0x3F3F3F3F;
const int MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int n, m, u, v, w;
int dis[MAXN], fa[MAXN];
bool flag;
vector<pair<int, pii>> edge;
vector<vector<pii>> graph;
vector<int> res;

void bell( int root ){
    dis[root] = 0;

    int lst = 0;
    for( int i = 0 ; i <= n ; ++i ){
        for( auto [w, node] : edge ){
            auto [a, b] = node;

            if( dis[a] + w < dis[b] ){
                if( i == n ) lst = b;

                fa[b] = a;
                dis[b] = dis[a] + w;
            }
        }
    }

    if( !lst ){
        cout << "NO\n";
        return;
    }

    for( int i = 0 ; i < n ; ++i ) lst = fa[lst];
    for( int it = lst ;  ; it = fa[it] ){
        res.pb(it);
        if( it == lst && res.size() > 1 ) break;
    }

    cout << "YES\n";
    reverse(res.begin(), res.end());
    for( auto node : res ) cout << node << " ";

    return;
}

signed main(){
    opt;

    cin >> n >> m;

    graph.resize(n + 5);
    for( int i = 0 ; i < m ; ++i ){
        cin >> u >> v >> w;

        edge.pb({w, {u, v}});
        graph[u].pb({v, w});
    }

    mem(dis, MEMINF);
    bell(1);
}