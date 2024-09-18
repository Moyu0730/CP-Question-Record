/* Question : AtCoder Beginner Contest 352 - E. Sightseeing Tour */

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
#define ll long long
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 1e18;
const int INF = 1e9;

int n, m, k, q, res, u[MAXN], v[MAXN], t[MAXN], arr[MAXN], dis[450][450];

void dfs( int amt, int cnt, int cost ){
    if( cost > res ) return;

    cnt = cnt == u[arr[amt]] ? v[arr[amt]] : u[arr[amt]];
    cost += t[arr[amt]];

    if( amt == k ){
        cost += dis[cnt][n];
        res = min(res, cost);
        return;
    }

    dfs(amt+1, u[arr[amt+1]], cost + dis[cnt][u[arr[amt+1]]]);
    dfs(amt+1, v[arr[amt+1]], cost + dis[cnt][v[arr[amt+1]]]);

    return;
}

signed main(){
    #ifndef LOCAL
        opt;
    #endif

    cin >> n >> m;
    
    mem(dis, 0x3F);
    for( int i = 1 ; i <= m ; i++ ){
        cin >> u[i] >> v[i] >> t[i];

        dis[u[i]][v[i]] = min(dis[u[i]][v[i]], t[i]);
        dis[v[i]][u[i]] = min(dis[v[i]][u[i]], t[i]);
    }

    // Flyod-Warshall
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= n ; j++ ) dis[i][j] = ( i == j ) ? 0 : dis[i][j];
    }

    for( int k = 1 ; k <= n ; k++ ){
        for( int i = 1 ; i <= n ; i++ ){
            for( int j = 1 ; j <= n ; j++ ){
                if( i == j ) continue;
                
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    cin >> q;
    while( q-- ){
        cin >> k;

        for( int i = 1 ; i <= k ; i++ ) cin >> arr[i];

        res = LLINF;
        sort(arr + 1, arr + 1 + k);
        do{
            dfs(1, u[arr[1]], dis[1][u[arr[1]]]);
            dfs(1, v[arr[1]], dis[1][v[arr[1]]]);
        }while( next_permutation(arr + 1, arr + 1 + k) );

        cout << res << "\n";
    }
}