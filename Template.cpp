#include<bits/stdc++.h>
using namespace std;

/* Pragma */
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

/* Self Define */
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MEM(_array, _value) memset(_array, _value, sizeof(_array));
#define ALL(_array) _array.begin(), _array.end()
#define LB(_array, v) lower_bound(ALL(_array), v)
#define UB(_array, v) upper_bound(ALL(_array), v)
#define REV(_vector) _vector.reverse();
#define vc(_data) vector<_data>
#define pii pair<int, int>
#define pdd pair<double, double>
#define mkp make_pair
#define sz size()
#define pb push_back
#define F first
#define S second
#define int long long
#define ll long long

/* Self Define Template Function */
template <typename T> void pV(vector<T> _vector ) { 
    for( auto _it : _vector ) cout << _it << " ";
    cout << "\n";
}

template <typename A, typename B> bool boundry( pair<A, B> &_pair, int _n, int _m ){ 
    return 1 <= _pair.F && _pair.F <= _n && 1 <= _pair.S && _pair.S <= _m;
}

template <typename A, typename B> istream& operator>>( istream& _is, pair<A, B> &_pair ){ 
    return _is >> _pair.F >> _pair.S;
}

template <typename A, typename B> ostream& operator<<( ostream& _os, pair<A, B> _pair ){ 
    return _os << '(' << _pair.F << ", " << _pair.S << ')';
}

/* Self Define Const */
const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1},  {-1, 0}, {0, -1}, 
                                            {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
const int         MAXN = 1e7 + 50;
const int          Mod = 1e9 + 7;
const int          INF = 0x7FFFFFFF;
const ll         LLINF = 0x7FFFFFFFFFFFFFFF;
const int       MEMINF = 0x3F;
const int   MEMINF_VAL = 0x3F3F3F3F;
const ll  MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

/* ---------- Segment Tree ---------- */
#define nL v * 2
#define nR v * 2 + 1

struct Node {
    int val = 0, tag = 0, len;
    int getValue(){ return val + (tag * len); }
} SEG[MAXN * 4];

void build( int L, int R, int v ){
    SEG[v].len = R - L + 1;
    if( R == L ){
        SEG[v].val = arr[L];
        return;
    }

    int M = (L + R) / 2;
    build(L, M, nL);
    build(M+1, R, nR);
    SEG[v].val = SEG[nL].val + SEG[nR].val;
}

void push( int v ){
    SEG[nL].tag += SEG[v].tag;
    SEG[nR].tag += SEG[v].tag;
    SEG[v].val = SEG[v].getValue();
    SEG[v].tag = 0;
}

int query( int L, int R, int qL, int qR, int v ){
    if( R < L || qL > R || qR < L ) return 0;
    if( qL <= L && R <= qR ) return SEG[v].getValue();

    push(v);
    int M = (L + R) / 2;
    return query(L, M, qL, qR, nL) + query(M+1, R, qL, qR, nR);
}

void modify( int L, int R, int mL, int mR, int val, int v ){
    if( R < L || mL > R || mR < L ) return;
    if( mL <= L && R <= mR ){
        SEG[v].tag += val;
        return;
    }

    int M = (L + R) / 2;
    modify(L, M, mL, mR, val, nL);
    modify(M+1, R, mL, mR, val, nR);
    SEG[v].val = SEG[nL].getValue() + SEG[nR].getValue();
}

/* ---------- Dijkstra ---------- */
void dij( int root ){
    pirq(pii) pq;
    pq.push({0, root});
    dis[root] = 0;
    while( !pq.empty() ){
        int d = pq.top().F;
        int node = pq.top().S;
        pq.pop();

        if( d > dis[node] ) continue;
        for( auto i : graph[node] ){
            int v = i.F;
            int w = i.S;
            if( d + w < dis[v] ){
                dis[v] = d + w;
                pq.push({dis[v], v});
            }
        }
    }
}

/* ---------- Bellman Ford ---------- */
int bellman( int root ){
    for( int i = 1 ; i <= n ; i++ ) dis[i] = INF;

    dis[root] = 0;
    
    for( int i = 1 ; i <= n ; i++ ){
        for(auto e : edge ){
            int w = e.f;
            int a = e.s.f;
            int b = e.s.s;
            if( dis[a] + w < dis[b] ){
                if( i == n ){
                    flag = true;
                }

                dis[b] = dis[a] + w;
            }
        }
    }
    
    if( flag ) return -1;
    else return dis[n];
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
int root, dep[MAXN], fa[MAXN][25];
vc(vc(int)) edge;

void dfs( int root, int parent ){
    dep[root] = dep[parent] + 1;
    
    for( int i = 1 ; (1<<i) <= dep[root] ; i++ ){
        fa[root][i] = fa[ fa[root][i-1] ][i-1];
    }
    
    for( auto i : edge[root] ){
        if( i == parent ) continue;

        fa[i][0] = root;
        dfs(i, root);
    }
}

void lca( int a, int b ){
    dfs(root, 0);

    if( dep[a] > dep[b] ) swap(a, b);

    for( int i = 20 ; i >= 0 ; --i ){
        if( dep[fa[b][i]] >= dep[a] ) b = fa[b][i];
        if( a == b ) return a;
    }

    for( int i = 20 ; i >= 0 ; --i ){
        if( fa[a][i] != fa[b][i] ){
            a = fa[a][i];
            b = fa[b][i];
        }
    }

    return fa[a][0];
}

/* ---------- BIT ---------- */
int n, BIT[MAXN];

int lowbit( int x ){ return x & -x; }

int query( int pos ){
    int ans = 0;
    
    while( pos ){
        ans += BIT[pos];
        pos -= lowbit(pos);
    }

    return ans;
}

void update( int x, int val ){
    while( x < MAXN ){
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

/* ---------- DSU ---------- */
int DSU[MAXN];

int query( int a ){
    if( DSU[a] == a ) return a;
    return DSU[a] = query(DSU[a]);
}

void mix( int a, int b ){
    int fa = query(a);
    int fb = query(b);
    DSU[fa] = fb;
}

/* ---------- Discretization ---------- */
int discretization(){
    int n, tmp[MAXN], after[MAXN], before[MAXN]; 
    vector<int> distinct;

    cin >> n;
    for( int i = 0 ; i < n ; i++ ){
        cin >> before[i];
        tmp[i] = before[i];
    }

    sort(tmp, tmp + n);

    distinct.pb(tmp[0]);
    for( int i = 1 ; i < n ; i++ ){
        if( tmp[i] != tmp[i-1] ) distinct.pb(tmp[i]);
    }

    for( int i = 0 ; i < n ; i++ ) after[i] = lower_bound(distinct.begin(), distinct.end(), before[i]) - distinct.begin();
}