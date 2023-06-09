/* Question : CSES 1674. Subordinates */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
int n, tmp;
vector<vector<int> > tree;
vector<int> dep;

int dfs( int node ){
	if( tree[node].size() == 0 ) return 1;
	for( auto v : tree[node] ) dep[node] += dfs(v);
	return dep[node] + 1;
}

signed main(){
    opt;
	cin >> n;

	tree.resize(n+5);
	dep.resize(n+5);
	for( int i = 2 ; i <= n ; i++ ){
		cin >> tmp;
		tree[tmp].push_back(i);
	}

	dfs(1);
	for( int i = 1 ; i <= n ; i++ ) cout << dep[i] << " ";
}