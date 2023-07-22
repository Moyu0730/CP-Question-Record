/* Question : UVa 291. The House Of Santa Claus */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define f first
#define s second

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 5 + 50;
const int Mod = 1e9 + 7;
bool visited[MAXN][MAXN];
vector<int> r;
vector<vector<int>> graph;

void run( vector<int>& route, int root, int step ){
    if( step == 8 ){
        for( auto i : route ) cout << i;
        cout << "\n";
    }

    for( int i : graph[root] ){
        if( !visited[root][i] && !visited[i][root] ){
            visited[root][i] = true;
            visited[i][root] = true;
            route.push_back(i);
            run(route, i, step+1);
            route.pop_back();
            visited[root][i] = false;
            visited[i][root] = false;
        }
    }
}

signed main(){
    opt;
    graph.resize(5+5);
    graph[1] = {2, 3, 5};
    graph[2] = {1, 3, 5};
    graph[3] = {1, 2, 4, 5};
    graph[4] = {3, 5};
    graph[5] = {1, 2, 3, 4};

    r.push_back(1);
    run(r, 1, 0);
}