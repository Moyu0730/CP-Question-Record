/* Question : CSES 1687. Company Queries I */

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
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
int n, q, p, v, k, fa[MAXN][20];

signed main(){
    opt;
    cin >> n >> q;
    for( int i = 2 ; i <= n ; i++ ) cin >> fa[i][0];

    for( int i = 1 ; i <= 20 ; i++ ){
        for( int j = 1 ; j <= n ; j++ ){
            fa[j][i] = fa[ fa[j][i-1] ][i-1];
        }
    }

    while( q-- ){
        cin >> v >> k;
        for (int i = 0 ; i < 20 ; i++){
            if ( k & ( 1 << i ) ) v = fa[v][i];
        }

        if ( !v ) cout << -1 << "\n";
        else cout << v << "\n";
    }
}