/* Question : Luogu P3376.【Template】Maximum Network Flow */

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
// #define int long long
#define ll long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e5 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;

struct EDGE{
    int ed, nxt;
    ll cap, flow;
    // End Vertex, Next Edge, Capacity, Current Flow
} edge[MAXN];

int n, m, s, t, u, v, w, amt, cnt[MAXN], last[MAXN], level[MAXN];
ll res;

ll dfs( int x, ll limit ){
    if( x == t || !limit ) return limit;

    ll ans = 0;
    for( int& i = cnt[x] ; i != -1 ; i = edge[i].nxt ){
        int to = edge[i].ed;
        ll d;

        if( (level[to] == level[x] + 1) && (d = dfs(to, min(limit - ans, edge[i].cap - edge[i].flow))) ){
            ans += d;
            edge[i].flow += d;
            edge[i^1].flow -= d;

            if( ans == limit ) return ans;
        }
    }

    return ans;
}

bool bfs(){
    queue<int> q;
    mem(level, 0);

    level[s] = 1;
    q.push(s);
    while( !q.empty() ){
        int node = q.front();
        q.pop();

        for( int i = last[node] ; i != -1 ; i = edge[i].nxt ){
            int to = edge[i].ed;

            if( !level[to] && edge[i].cap > edge[i].flow ){
                level[to] = level[node] + 1;
                q.push(to);
            }
        }
    }

    return level[t];
}

ll dinic(){
    while( bfs() ){
        for( int i = 1 ; i <= n ; i++ ) cnt[i] = last[i];
        res += dfs(s, LLINF);
    }

    return res;
}

void add( int u, int v, int w ){
    edge[amt] = {v, last[u], w, 0};
    last[u] = amt++;
    edge[amt] = {u, last[v], 0, 0};
    last[v] = amt++;
}

signed main(){
    opt;

    cin >> n >> m >> s >> t;

    mem(last, -1);
    amt = 0;
    for( int i = 0 ; i < m ; i++ ){
        cin >> u >> v >> w;
        add(u, v, w);
    }

    cout << dinic() << "\n";
}