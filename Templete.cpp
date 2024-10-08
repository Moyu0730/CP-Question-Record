#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pirq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define f first
#define s second
#define int long long

/* ---------- Segment Tree ---------- */
#define nL v*2
#define nR v*2+1

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 5e5 + 50;
const int Mod = 1e9 + 7;
int n, x, y, k, m, arr[MAXN];

struct Node {
    int val = 0, tag = 0, sz;
    int rv(){
        return val + (tag * sz);
    }
} segment_tree[MAXN * 4];

void build( int L, int R, int v ){
    segment_tree[v].sz = R - L + 1;
    if( R == L ){
        segment_tree[v].val = arr[L];
        return;
    }

    int M = (L + R) / 2;
    build(L, M, nL);
    build(M+1, R, nR);
    segment_tree[v].val = segment_tree[nL].val + segment_tree[nR].val;
}

void push( int v ){
    segment_tree[nL].tag += segment_tree[v].tag;
    segment_tree[nR].tag += segment_tree[v].tag;
    segment_tree[v].val = segment_tree[v].rv();
    segment_tree[v].tag = 0;
}

int query( int L, int R, int ql, int qr, int v ){
    if( R < L || ql > R || qr < L ) return 0;
    if( ql <= L && qr >= R ) return segment_tree[v].rv();

    push(v);
    int M = (L + R) / 2;
    return query(L, M, ql, qr, nL) + query(M+1, R, ql, qr, nR);
}

void modify( int L, int R, int ml, int mr, int val, int v ){
    if( R < L || ml > R || mr < L ) return;
    if( ml <= L && mr >= R ){
        segment_tree[v].tag += val;
        return;
    }

    int M = (L + R) / 2;
    modify(L, M, ml, mr, val, nL);
    modify(M+1, R, ml, mr, val, nR);
    segment_tree[v].val = segment_tree[nL].rv() + segment_tree[nR].rv();
}

/* ---------- Dijkstra ---------- */
void dij( int root ){
    pirq(pii) pq;
    pq.push({0, root});
    dis[root] = 0;
    while( !pq.empty() ){
        int d = pq.top().f;
        int node = pq.top().s;
        pq.pop();

        if( d > dis[node] ) continue;
        for( auto i : graph[node] ){
            int v = i.f;
            int w = i.s;
            if( d + w < dis[v] ){
                dis[v] = d + w;
                pq.push({dis[v], v});
            }
        }
    }
}

/* ---------- Bellman Ford ---------- */
vector<pair<int, pii>> edge;
int dis[MAXN], negc[MAXN];
bool flag; // Has Negative Cycle or Not

bool bell( int root ){
    for( int i = 1 ; i <= n ; i++ ) dis[i] = 1e15;
    dis[root] = 0;
    for( int i = 1 ; i <= n ; i++ ){
        for(auto e : edge ){
            int w = e.f;
            int a = e.s.f;
            int b = e.s.s;
            if( dis[a] + w < dis[b] ){
                if( i == n-1 ) flag = true;
                dis[b] = dis[a] + w;
            }
        }
    }
    
    return flag;
}

/* ---------- Flyod-Warshall ---------- */
void flyod( int n ){
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= n ; j++ ){
            dp[i][j] = ( i == j ) ? 0 : graph[i][j]; 
        }
    }

    for( int k = 1 ; k <= n ; k++ ){
        for( int i = 1 ; i <= n ; i++ ){
            for( int j = 1 ; j <= n ; j++ ){
                if( i == j ) continue;
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
}

/* ---------- LCA ---------- */
int n, q, a, b, fa[MAXN][25], dep[MAXN];
vector<vector<int>> tree;

void dfs( int cnt ){

    dep[cnt] = dep[fa[cnt][0]] + 1;

    for( int i = 1 ; i < 20 ; i++ ) fa[cnt][i] = fa[ fa[cnt][i-1] ][i-1];
    for( auto i : tree[cnt] ) dfs(i);

    return;
}

int lca( int a, int b ){
    if( dep[a] > dep[b] ) swap(a, b);

    int tmp = dep[b] - dep[a];
    for( int i = 0 ; tmp ; i++, tmp >>= 1 ){
        if( tmp & 1 ) b = fa[b][i];
    }

    if( a == b ) return a;
    else{
        int step = 20;
        while( step >= 0 ){
            if( fa[a][step] == fa[b][step] ) step--;
            else{
                a = fa[a][step];
                b = fa[b][step];
            }
        }

        return fa[a][0];
    }
}

/* ---------- BIT ---------- */
int n, BIT[MAXN];

int lowbit( int x ){
    return x & -x;
}

int query( int pos ){
    if( pos <= 0 ) return 0;

    int ans = 0;
    while( pos ){
        ans += BIT[pos];
        pos -= lowbit(pos);
    }

    return ans;
}

void update( int x, int val ){
    while( x <= n ){
        BIT[x] += val;
        x += lowbit(x);
    }
}

int sum( int l, int r ){
    if( l > r ) return 0;
    return query(r) - query(l - 1);
}

/* ---------- KSM ---------- */
int ksm( int base, int power ){
    int res = 1;
    while( power > 0 ){
        if( power & 1 ) res *= base;
        
        power >>= 1;
        base *= base;
    }

    return res;
}

/* ---------- Modular Multiplicative Inverse ---------- */
int mmi( int base, int mod ){
    int res = 1;
    int power = mod - 2;
    while( power > 0 ){
        if( power & 1 ){
            res = ( res * base ) % mod;
        }

        base = ( base * base ) % mod;
        power >>= 1;
    }

    return res;
}