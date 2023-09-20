/* Question : CSES 1667. Message Route  */

#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<math.h>
#include<algorithm>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int MAXN = 1e5 + 50;
const int Mod = 1e9 + 7;
int n, m, v, u;
vector<vector<int>> graph;
queue<int> q;
vector<int> dis, sor, route;

int bfs( int node ){
    q.push(node);
    dis[node] = 0;
    while( !q.empty() ){
        int t = q.front();
        q.pop();
        for( auto i : graph[t] ){
            if( dis[i] == -1 ){
                q.push(i);
                dis[i] = dis[t] + 1;
                sor[i] = t;
            }
        }
    }

    return dis[n]+1;
}

signed main(){
    opt;
    cin >> n >> m;
    
    graph.resize(n+1);
    sor.resize(n+1);
    dis.resize(n+1, -1);
    while( m-- ){
        cin >> v >> u;
        graph[v].emplace_back(u);
        graph[u].emplace_back(v);
    }

    int res = bfs(1);
    if( dis[n] == -1 ){
        cout << "IMPOSSIBLE\n";
    }else{
        cout << res << "\n";
        int ind = n;
        while( sor[ind] != 0 ){
            route.emplace_back(ind);
            ind = sor[ind];
        }
        route.emplace_back(1);
        
        for( int i = route.size() - 1 ; i >= 0 ; i-- ) cout << route[i] << " ";
    }
}