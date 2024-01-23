/* Question : TCIRC d025. AP325 P-3-1. Height and Root of Tree（Bottom-Up）（APCS201710） */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define priq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define F first
#define S second
#define X first
#define Y second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e5 + 10;
const int Mod = 1e9 + 7;
int n, amt, son, root, h[MAXN], indegree[MAXN];
vector<queue<int>> node;

void dfs( int cnt ){
    if( node[cnt].empty() ) return;

    while( !node[cnt].empty() ){
        int nxt = node[cnt].front();
        node[cnt].pop();
        
        dfs(nxt);
        
        h[cnt] = max(h[cnt], h[nxt] + 1);
    }
    
    return;
}

signed main(){
    opt;
    cin >> n;

    node.resize(n+5);
    for( int i = 1 ; i <= n ; i++ ){
        cin >> amt;
        for( int j = 0 ; j < amt ; j++ ){
            cin >> son;
            indegree[son]++;
            node[i].push(son);
        }
    }

    // Find Root
    for( int i = 1 ; i <= n ; i++ ){
        if( !indegree[i] ){
            root = i;
            break;
        }
    }

    dfs(root);

    int res = 0;
    for( int i = 1 ; i <= n ; i++ ) res += h[i];

    cout << root << "\n" << res << "\n";
}
