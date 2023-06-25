/* Question : ZJ k734. Open Treasure Box */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int MAXN = 1e5 + 50;
const int Mod = 1e9 + 7;
int n, m, k, t, key, box, tmp, res;
vector<vector< int > > graph;
vector<int> todo;
int indegree[MAXN];
bool visited[MAXN * 2];

signed main(){
    opt;
    cin >> n >> m >> k >> t;
    graph.resize( n + m + 5 );
    for( int i = 0 ; i < t ; i++ ){
        cin >> key;
        todo.push_back(key+n);
    }

    for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j < k ; j++ ){
            cin >> tmp;
            graph[tmp+n].push_back(i);
        }
    }

    for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j < k ; j++ ){
            cin >> tmp;
            graph[i].push_back(tmp+n);
            indegree[i]++;
        }
    }

    res = 0;
    while( !todo.empty() ){
        int ctn = todo.back();
        todo.pop_back();
        if( visited[ctn] ) continue;
        visited[ctn] = true;
        for( auto i : graph[ctn] ){
            if( ctn < n ){
                todo.push_back(i);
            }else{
                indegree[i]--;
                if( indegree[i] == 0 ){
                    todo.push_back(i);
                    res++;
                }
            }
        }
    }

    cout << res << "\n";
}