/* Question : AtCoder Beginner Contest 274 - C. Ameba */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define priq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define F first
#define s second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 4e5 + 50;
const int Mod = 1e9 + 7;
int n, r, cnt;
vector<vector<int>> tree;
vector<int> v, res;

void dfs( int node, int level ){
    res[node] = level;

    for( auto i : tree[node] ){
        dfs(i, level+1);
    }

    return;
}

signed main(){
    // opt;
    cin >> n;
    res.resize((n*2) + 50);
    tree.resize((n*2) + 50);
    cnt = 1;
    for( int i = 0 ; i < n ; i++ ){
        cin >> r;
        tree[r].pb(cnt+1);
        tree[r].pb(cnt+2);
        cnt += 2;
    }

    dfs(1, 0);

    for( int i = 1 ; i <= n * 2 + 1 ; i++ ) cout << res[i] << "\n";
}