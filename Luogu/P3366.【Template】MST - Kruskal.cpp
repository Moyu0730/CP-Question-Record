/* Question : Luogu P3366.【Template】MST - Kruskal */

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
#define ll long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;

int n, m, sz;
int fa[MAXN];

struct EDGE{
    int u, v, w;
    bool operator < (const EDGE &E) const{
        return w < E.w;
    }
} edge[MAXN];

int find( int x ){
    if( fa [x] != x ) fa[x] = find(fa[x]);
    return fa[x];
}

int kruskal(){
    int res = 0, sz = 1;
    for( int i = 1 ; i <= n ; i++ ) fa[i] = i;
    sort(edge, edge + m);
    for( int i = 0 ; i < m ; i++ ){
        int x = edge[i].u, y = edge[i].v;
        int px, py;
        if( (px = find(x)) != (py = find(y)) ){
            res += edge[i].w;
            fa[px] = py;
            sz++;
        }
    }

    if( sz == n ) return res;
    else return -1;
}


signed main(){
    opt;
    cin >> n >> m;
    for( int i = 0 ; i < m ; i++ ){
        int a, b, c;
        cin >> a >> b >> c;
        edge[i] = {.u = a, .v = b, .w = c};
    }

    int res;
    if( ( res = kruskal() ) != -1 ) cout << res << "\n";
    else cout << "orz\n";
}