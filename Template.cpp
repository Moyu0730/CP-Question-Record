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
template<tpn T> struct NODE {
    T val, tag, len;
    NODE() : val(0), tag(0), len(0) {}
    T gV(){ return val + (tag * len); }
};

NODE<int> ARRAY[MAXN * 4];

template<tpn T> struct SEG {
    #define nL (x<<1)
    #define nR (x<<1) + 1

    SEG(){ build(1, n, 1); }
    T FUNC( T vL, T vR ){ return vL + vR; }

    void push( int x ){
        ARRAY[nL].tag += ARRAY[x].tag;
        ARRAY[nR].tag += ARRAY[x].tag;
        ARRAY[x].val = ARRAY[x].gV();
        ARRAY[x].tag = 0;
    }

    void build( int L, int R, int x ){
        ARRAY[x].len = R - L + 1;

        if( R == L ){
            ARRAY[x].val = arr[L];
            return;
        }

        int M = (L + R) / 2;
        build(L, M, nL);
        build(M+1, R, nR);
        ARRAY[x].val = FUNC( ARRAY[nL].gV(), ARRAY[nR].gV() );
    }

    T query( int qL, int qR ){ return query(1, n, qL, qR, 1); }
    T query( int L, int R, int qL, int qR, int x ){
        if( R < L || qL > R || qR < L ) return 0;
        if( qL <= L && R <= qR ) return ARRAY[x].gV();

        push(x);

        int M = (L + R) / 2;
        return FUNC( query(L, M, qL, qR, nL), query(M+1, R, qL, qR, nR) );
    }

    void update( int mL, int mR, T mV ){ update(1, n, mL, mR, mV, 1); }
    void update( int L, int R, int mL, int mR, T mV, int x ){
        if( R < L || mL > R || mR < L ) return;
        if( mL <= L && R <= mR ){
            ARRAY[x].tag += mV;
            return;
        }

        int M = (L + R) / 2;
        update(L, M, mL, mR, mV, nL);
        update(M+1, R, mL, mR, mV, nR);
        ARRAY[x].val = FUNC( ARRAY[nL].gV(), ARRAY[nR].gV() );
    }
};

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
template<tpn T> struct BIT {
    T ARR[MAXN];
    BIT(){ clear(); }
    int lowbit( int x ){ return x & -x; }
    T query( int pos ){
        T ans = 0;
        while( pos ){
            ans += ARR[pos];
            pos -= lowbit(pos);
        }
        return ans;
    }
    void update( int x, T val ){
        while( x < MAXN ){
            ARR[x] += val;
            x += lowbit(x);
        }
    }
    T sum( int l, int r ){
        if( l > r ) return 0;
        return query(r) - query(l - 1);
    }
    T LowerB( T val ){ // lower_bound by sum
        T res = 0, step = MAXN - 1;
        while( step != 0 ){
            if( query(res + step) >= val ) step /= 2;
            else res += step;
        }
        return res + 1;
    }
    void clear(){ MEM(ARR, 0); }
};

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

/* Matrix Exponentiation */
template<typename T> vector<vector<T>> mat( const vector<vector<T>>& x, const vector<vector<T>>& y ){
    int p = x.size(), q = x[0].size(), r = y[0].size();
    vector<vector<T>> res( p, vector<T>(r, 0) );
    for( int i = 0; i < p; i++ ){
        for( int j = 0; j < r; j++ ){
            for( int k = 0; k < q; k++ ){
                res[i][j] = (res[i][j] + x[i][k] * y[k][j]) % Mod;
            }
        }
    }
    return res;
}

template<typename T> void mpow( vector<vector<T>> &x, int y ){
    int n = x.size();
    vector<vector<T>> ret(n, vector<T>(n, 0));
    
    for( int i = 0 ; i < n ; i++ ) ret[i][i] = 1;
    while( y ){
        if( y & 1 ) ret = mat(ret, x);
        x = mat(x, x);
        y >>= 1;
    }

    x = ret;
    return;
}

/* Network Flow */
struct DINIC {
    struct EDGE {
        int v, flow, rev; // rev is the pos in reverse edge
    };

    int n, s, t, level[MAXN];
    vector<EDGE> edge[MAXN];

    DINIC( int _n, int _s, int _t ){
        n = _n, s = _s, t = _t;
        for( int i = 0 ; i < n ; i++ ) edge[i].clear();
    }

    void add_edge( int u, int v, int w ){
        edge[u].pb({v, w, (int)edge[v].sz});
        edge[v].pb({u, 0, (int)edge[u].sz - 1});
    }

    bool bfs(){
        MEM(level, -1);
        queue<int> q;
        q.push(s);
        level[s] = 0;
        while( !q.empty() ){
            int cnt = q.front();
            q.pop();
            for( auto i : edge[cnt] ){
                if( i.flow > 0 && level[i.v] == -1 ){
                    level[i.v] = level[cnt] + 1;
                    q.push(i.v);
                }
            }
        }

        return level[t] != -1;
    }

    int dfs( int cnt, int remFlow ){
        if( cnt == t ) return remFlow;
        int res = 0;
        
        for( auto &i : edge[cnt] ){
            if( i.flow > 0 && level[i.v] == level[cnt] + 1 ){
                int blockFlow = dfs(i.v, min(remFlow, i.flow));
                res += blockFlow, remFlow -= blockFlow, i.flow -= blockFlow;
                edge[i.v][i.rev].flow += blockFlow;
                if( remFlow == 0 ) return res;
            }
        }

        if( !res ) level[cnt] = -1;
        return res;
    }

    int flow( int res = 0 ){
        while( bfs() ) res += dfs( s, INF );

        return res;
    }
};

/* Heavy-Light Decomposition */
struct HLD {
    struct NODE {
        int size, fa, depth, hson, id, chain;
    } node[MAXN];

    int timer = 0, id2pos[MAXN];
    vector<vector<int>> edge;
    
    void init(){
        build(1, 0);
        decomposition(1, 1);
    }
    
    int build( int root, int dep ){
        node[root].hson = 0;
        node[node[root].hson].size = 0;
        node[root].depth = dep;
        node[root].size = 1;
        for( auto i : edge[root] ){
            if( i == node[root].fa ) continue;
            node[i].fa = root;
            node[root].size += build(i, dep + 1);
            if( node[i].size > node[node[root].hson].size ){
                node[root].hson = i;
            }
        }
    
        return node[root].size;
    }
    
    void decomposition( int root, int chain ){
        node[root].chain = chain;
        node[root].id = ++timer;
        id2pos[node[root].id] = root;
        if( node[root].hson != 0 ){
            decomposition(node[root].hson, chain);
            for( auto i : edge[root] ){
                if( i == node[root].fa || i == node[root].hson ) continue;
                decomposition(i, i);
            }
        }
    }
};
