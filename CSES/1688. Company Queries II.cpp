/* Question : CSES 1688. Company Queries II */

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

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
int n, q, a, b, fa[MAXN][25], dep[MAXN];
vector<vector<int>> tree;

void dfs( int cnt ){

    dep[cnt] = dep[fa[cnt][0]] + 1;

    for( int i = 1 ; i < 20 ; i++ ) fa[cnt][i] = fa[ fa[cnt][i-1] ][i-1];
    
    for( auto i : tree[cnt] ) dfs(i);

    return;
}

signed main(){
    opt;
    cin >> n >> q;
    tree.resize(n+5);
    for( int i = 2 ; i <= n ; i++ ){
        cin >> fa[i][0];
        tree[fa[i][0]].pb(i);
    }

    dfs(1);

    // for( int i = 1 ; i <= n ; i++ ) cout << dep[i] << " \n"[i==n];

    // for( int i = 1 ; i <= n ; i++ ){
    //     cout << i << " | ";
    //     for( int j = 0 ; j <= 3 ; j++ ){
    //         cout << fa[i][j] << " \n"[j==3];
    //     }
    // }

    while( q-- ){
        cin >> a >> b;
        if( dep[a] > dep[b] ) swap(a, b);

        int tmp = dep[b] - dep[a];
        for( int i = 0 ; tmp ; i++, tmp >>= 1 ){
            if( tmp & 1 ) b = fa[b][i];
        }

        if( a == b ) cout << a << "\n";
        else{
            int step = 20;
            while( step >= 0 ){
                // cout << step << " ";
                if( fa[a][step] == fa[b][step] ) step--;
                else{
                    a = fa[a][step];
                    b = fa[b][step];
                }
            }

            cout << fa[a][0] << "\n";
        }
    }
}