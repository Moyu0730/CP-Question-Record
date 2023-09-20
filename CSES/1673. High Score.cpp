/* Question : CSES 1673. High Score */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define f first
#define s second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
int n, m, a, b, w, r, t, tmp;
bool flag = false, fg, times[MAXN];
vector<pair<int, pii>> edge;
vector<vector<int>> graph, negG;
int dis[MAXN], negc[MAXN];

int dfs( int root ){
    if( negc[root] == true ) return -1;
    if( root == 1 && negG[root].size() == 0 ) return (-1 * dis[n]);

    for( auto i : negG[root] ){
        if( negc[i] == true ) return -1;
        if( times[i] == true ) continue;
        
        times[i] = true;
        tmp = dfs(i);

        if( tmp == (-1 * dis[n]) ) break;
        if( tmp == -1 ) return -1;
    }

    return (-1 * dis[n]);
}

int bell( int root ){
    for( int i = 1 ; i <= n ; i++ ) dis[i] = 1e15;
    dis[root] = 0;
    for( int i = 1 ; i <= n ; i++ ){
        for(auto e : edge ){
            int w = e.f;
            int a = e.s.f;
            int b = e.s.s;
            if( dis[a] + w < dis[b] ){
                if( i == n-1 ){
                    flag = true;
                    negc[a] = true;
                    negc[b] = true;
                }
                dis[b] = dis[a] + w;
            }
        }
    }
    
    if( flag ) return dfs(n);
    else return (-1 * dis[n]);
}

signed main(){
    opt;
    cin >> n >> m;
    graph.resize(n+5);
    negG.resize(n+5);
    for( int i = 0 ; i < m ; i++ ){
        cin >> a >> b >> w;
        edge.push_back({(-1 * w), {a, b}});
        negG[b].push_back(a);
        graph[a].push_back(b);
    }

    if( m == 1 && n > 1 ) cout << -1 * edge[0].first << "\n";
    else if( n == 1 && m == 1 ) cout << "-1\n";
    else cout << bell(1) << "\n";
}