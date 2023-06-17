/* Question : Luogue P1352. Prom Without Boss */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int MAXN = 6e3 + 50;
const int Mod = 1e9 + 7;
int n, l, k, root;
int happy[MAXN];
int dp[MAXN][2+5];
int indegree[MAXN];
vector<vector<int> > tree;

int sol( int node ){
    dp[node][1] = happy[node];
    for( auto i : tree[node] ){
        sol(i);
        dp[node][0] += max( dp[i][0], dp[i][1] );
        dp[node][1] += dp[i][0];
    }

    return max( dp[node][0], dp[node][1] );
}

signed main(){
    opt;
    cin >> n;

    tree.resize(n+5);
    for( int i = 1 ; i <= n ; i++ ) cin >> happy[i];
    for( int i = 0 ; i < n-1 ; i++ ){
        cin >> l >> k;
        tree[k].push_back(l);
        indegree[l]++;
    }
    
    for( int i = 1 ; i <= n ; i++ ){
        if( tree[i].size() == 0 ){
            dp[i][0] = 0;
            dp[i][1] = happy[i];
        }

        if( indegree[i] == 0 ) root = i;
    }

    cout << sol(root);
}