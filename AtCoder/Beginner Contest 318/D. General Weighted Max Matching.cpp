/* Question : AtCoder Beginner Contest 318 - D - General Weighted Max Matching */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pirq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define f first
#define s second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 16 + 50;
const int Mod = 1e9 + 7;
int n, res, cnt, num, graph[MAXN][MAXN];
bool flag, used[MAXN];

void dfs( int amt ){
    if( amt <= 1 ){
        res = max( res, cnt );
        return;    
    }
    
    for( int u = 1 ; u <= n ; u++ ){
        if( used[u] == true ) continue;
        for( int v = 1 ; v <= n ; v++ ){
            if( used[v] == true ) continue;

            used[u] = true;
            used[v] = true;
            cnt += graph[u][v];
            amt -= 2;
            dfs(amt);
            cnt -= graph[u][v];
            amt += 2;
            used[u] = false;
            used[v] = false;
        }
    }
}

signed main(){
    opt;
    cin >> n;
    for( int i = 1 ; i <= n-1 ; i++ ){
        for( int j = i+1 ; j <= n ; j++ ){
            cin >> graph[i][j];
            graph[j][i] = graph[i][j];
        }
    }

    num = n;
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= n ; j++ ){
            used[i] = true;
            used[j] = true;
            cnt += graph[i][j];
            num -= 2;
            dfs(num);
            cnt -= graph[i][j];
            num += 2;
            used[i] = false;
            used[j] = false;
        }
    }

    cout << res << "\n";
}