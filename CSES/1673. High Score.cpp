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
bool flag, used[MAXN], negc[MAXN];
vector<pair<int, pii>> edge;
vector<vector<int>> graph;
int dis[MAXN];
 
bool dfs( int root, bool state ){
    bool res = false;
    if( root == n ){
        return negc[n] | state;
    }
    else{
        bool tmp = state;
        for( auto i : graph[root] ){
            if( negc[i] ) tmp = true;
            if( used[i] ) continue;
            
            used[i] = true;

            res |= dfs(i, tmp);
 
            used[i] = false;
            tmp = state;
        }

        if( root == 1 ) return res | negc[root];
        else return res;
    }
}
 
bool getCycle( int root, int init ){
    for( auto i : graph[root] ){
        if( negc[i] ) return true;
        if( used[i] ) continue;
 
        used[i] = true;
        if( getCycle(i, init) ){
            negc[i] = true;
            return true;
        }
        used[i] = false;
    }
 
    return false;
}
 
int bell( int root ){
    flag = false;
 
    for( int i = 1 ; i <= n ; i++ ) dis[i] = 1e15;
    
    dis[root] = 0;
    for( int i = 1 ; i <= n ; i++ ){
        for(auto e : edge ){
            int w = e.f;
            int a = e.s.f;
            int b = e.s.s;
            if( dis[a] + w < dis[b] ){
                if( i == n ){
                    flag = true;
                    negc[a] = true;
 
                    mem(used, false);
                    used[a] = true;
                    getCycle(a, a);
                }
                dis[b] = dis[a] + w;
            }
        }
    }
    
    mem(used, false);
    used[1] = true;
    if( flag && dfs(1, false) ) return -1;
    else return (-1 * dis[n]);
}
 
signed main(){
    opt;
    cin >> n >> m;
    graph.resize(n+5);
    for( int i = 0 ; i < m ; i++ ){
        cin >> a >> b >> w;
        edge.push_back({(-1 * w), {a, b}});
        graph[a].push_back(b);
    }
 
    if( m == 1 && n > 1 ) cout << -1 * edge[0].first << "\n";
    else if( n == 1 && m == 1 ){
        if( edge[0].f < 0 ) cout << "-1\n";
        else cout << "0\n";
    }else cout << bell(1) << "\n";
}