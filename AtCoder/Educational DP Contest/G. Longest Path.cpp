/* Question : Atcoder DP Contest - G. Longest Path */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define priq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define f first
#define s second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e5 + 50;
const int Mod = 1e9 + 7;
int n, m, u, v, res, dp[MAXN], indegree[MAXN];
vector<vector<int>> edge;
queue<int> q;

signed main(){
    opt;

    cin >> n >> m;
    edge.resize(n+5);
    mem(dp, -1);
    for( int i = 0 ; i < m ; i++ ){
        cin >> u >> v;
        edge[u].pb(v);
        indegree[v]++;
    }

    for( int i = 1 ; i <= n ; i++ ){
        if( indegree[i] == 0 ){
            dp[i] = 0;
            q.push(i);
        }
    }

    while( !q.empty() ){
        int cnt = q.front();
        q.pop();    

        res = max(res, dp[cnt]);

        for( auto i : edge[cnt] ){
            dp[i] = max(dp[i], dp[cnt] + 1);
            indegree[i]--;

            if( indegree[i] == 0 ) q.push(i);
        }
    }

    cout << res << "\n";
}