/* Question : AtCoder Beginner Contest 396 - E. Min of Restricted Sum */

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
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;
const int MEMINF = 0x3F;
const int MEMINF_VAL = 0x3F3F3F3F;
const int MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int n, m, x, y, z;
vector<vector<pii>> edge;
bool used[MAXN];
int res[MAXN], amt[32 + 5][5];

void dfs( int root, int fa ){
    used[root] = true;
    
    for( int i = 0 ; i <= 31 ; ++i ){
        if( res[root] & (1<<i) ) ++amt[i][1];
        else ++amt[i][0];
    }

    for( auto [nxt, w] : edge[root] ){
        if( nxt == fa ) continue;

        if( used[nxt] ){
            if( res[nxt] != ( res[root] ^ w ) ){
                cout << "-1\n";
                exit(0);
            }
        }else{
            res[nxt] = res[root] ^ w;
            dfs(nxt, root);
        }
    }
}

void modify( int root ){
    used[root] = true;

    for( auto [nxt, w] : edge[root] ){
        if( used[nxt] ) continue;

        res[nxt] = res[root] ^ w;
        modify(nxt);
    }
}

signed main(){
    opt;
    
    cin >> n >> m;

    edge.resize(n+5);
    for( int i = 0 ; i < m ; ++i ){
        cin >> x >> y >> z;

        edge[x].pb({y, z});
        edge[y].pb({x, z});
    }

    for( int i = 1 ; i <= n ; ++i ){
        if( used[i] ) continue;

        res[i] = 0;
        dfs(i, 0);

        for( int j = 0 ; j <= 31 ; ++j ){
            if( amt[j][1] >= amt[j][0] ) res[i] |= (1<<j);
            
            amt[j][0] = 0;
            amt[j][1] = 0;
        }
    }
    
    mem(used, false);

    for( int i = 1 ; i <= n ; ++i ){
        if( used[i] ) continue;

        modify(i);
    }

    for( int i = 1 ; i <= n ; ++i ) cout << res[i] << " \n"[i==n];
}