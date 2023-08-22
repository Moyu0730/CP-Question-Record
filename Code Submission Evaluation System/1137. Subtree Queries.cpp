/* Question : CSES 1137. Subtree Queries */

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

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
int n, q, a, b, st, timer, arr[MAXN], sz[MAXN], pos[MAXN], BIT[MAXN];
vector<vector<int>> graph;

int query( int x ){
    int res = 0;
    while( x ){
        res += BIT[x];
        x -= x & (-x);
    }
    return res;
}

void update( int x, int delta ){
    while ( x <= n ){
        BIT[x] += delta;
        x += x & (-x);
    }
}

void treeflat( int cnt, int fa ){
    pos[cnt] = ++timer;
    sz[cnt] = 1;
    for( auto i : graph[cnt] ){
        if( i == fa ) continue;
        treeflat(i, cnt);
        sz[cnt] += sz[i];
    }
}

signed main(){
    opt;
    cin >> n >> q;
    graph.resize(n+5);
    for( int i = 1 ; i <= n ; i++ ) cin >> arr[i];
    for( int i = 0 ; i < n-1 ; i++ ){
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    treeflat(1, 0);

    // Init
    for( int i = 1 ; i <= n ; i++ ) update(pos[i], arr[i]);

    while( q-- ){
        cin >> st;
        if( st == 1 ){
            cin >> a >> b;
            update(pos[a], b - arr[a]);
            arr[a] = b;
        }else{
            cin >> a;
            cout << query(pos[a] + sz[a] - 1) - query(pos[a] - 1) << "\n";
        }
    }
}