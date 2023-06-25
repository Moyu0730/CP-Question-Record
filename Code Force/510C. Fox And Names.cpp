/* Question : CF 510C. Fox And Names */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int MAXN = 1e2 + 50;
const int Mod = 1e9 + 7;
int n, indegree[MAXN];
bool flag = false;
string st[MAXN], sol;
vector<vector<int>> graph;
vector<int> todo;

signed main(){
    opt;
    cin >> n;
    for( int i = 0 ; i < n ; i++ ) cin >> st[i];

    graph.resize(50);
    for( int i = 0 ; i < n-1 ; i++ ){
        if( st[i].size() > st[i+1].size() ) flag = true;
        for( int j = 0 ; j < min( st[i].size(), st[i+1].size() ) ; j++ ){
            if( st[i][j] != st[i+1][j] ){
                graph[st[i][j]-'a'].push_back(st[i+1][j]-'a');
                indegree[st[i+1][j]-'a']++;
            }
        }
    }

    for( int i = 0 ; i < 26 ; i++ ){
        if( indegree[i] == 0 ) todo.push_back(i);
    }

    while( !todo.empty() ){
        int a = todo.back();
        todo.pop_back();
        for( int i = 0 ; i < graph[a].size() ; i++ ){
            indegree[graph[a][i]]--;
            if( indegree[graph[a][i]] == 0 ){
                todo.push_back(graph[a][i]);
            }
        }
        sol.push_back((char)(a+'a'));
    }

    if( sol.size() == 26 && flag == false ) cout << sol << "\n";
    else cout << "Impossible\n";
}