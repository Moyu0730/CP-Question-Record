/* Question : Luogu P3385.【Tempate】Negative Cycle */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
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
const int MAXN = 3e5 + 50;
const int Mod = 1e9 + 7;
const int LLINF = 1e18;
const int INF = 0x3F3F3F3F;

int t, n, m, ind, from[MAXN], to[MAXN], weight[MAXN], dis[MAXN];

bool bell(){
    mem(dis, INF);
    dis[1] = 0;
    
    for( int i = 0 ; i <= n ; i++ ){
        for ( int j = 0 ; j < ind ; j++ ){
            if( i == n && dis[to[j]] > dis[from[j]] + weight[j] && dis[to[j]] < INF ){
                return true;
            }
            
            dis[to[j]] = min(dis[to[j]], dis[from[j]] + weight[j]);
        }
    }

    return false;
}
signed main(){
    opt;
    cin >> t;
    while( t-- ){
        cin >> n >> m;

        ind = 0;
        for( int i = 0 ; i < m ; i++, ind++ ){    
            cin >> from[ind] >> to[ind] >> weight[ind];

            if( weight[ind] >= 0 ){
                ind++;
                from[ind] = to[ind-1];
                to[ind] = from[ind-1];  
                weight[ind] = weight[ind-1];
            }
        }

        if( bell() ) cout << "YES\n";
        else cout << "NO\n";
    }
}