/* Question : TCIRC d097. AP325 P-7-10 Pit Jumping */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mem(x) memset(x, 0x3F, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define f first
#define s second

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 500 + 50;
const int Mod = 1e9 + 7;
int n, m, k;
int graph[MAXN][MAXN], area[MAXN][MAXN], num, ma, res, ans;
pii p[MAXN][MAXN];
vector<pii> spot;

pii query( int i, int j ){
    if( p[i][j] == make_pair(i, j) ) return { i, j };
    else return p[i][j] = query( p[i][j].f, p[i][j].s );
}

void mix( int i, int j ){
    if( graph[i][j] != 1 ) return;
    
    for( int t = 0 ; t < 4 ; t++ ){
        int x = i + dir[t].f;
        int y = j + dir[t].s;

        if( x < 1 || x > m || y < 1 || y > n ) continue;
        if( graph[x][y] == 1 ){
            // Connect Parents
            pii a = query(i, j), b = query(x, y);
            if( a == b ) continue;
            p[a.f][a.s] = b;

            // Update Max Area
            area[b.f][b.s] += area[a.f][a.s];
            ma = max( ma, area[b.f][b.s] );

            // Update Pond Num
            num--;
        }
    }
}

signed main(){
    opt;
    cin >> m >> n >> k;
    spot.resize(k+5);
    for( int i = 1 ; i <= m ; i++ ){
        for( int j = 1 ; j <= n ; j++ ){
            cin >> graph[i][j];
            p[i][j] = {i, j};
            area[i][j] = 1;
            num += graph[i][j];
        }
    }
    for( int i = 0 ; i < k ; i++ ) cin >> spot[i].f >> spot[i].s;

    for( int i = 1 ; i <= m ; i++ ){
        for( int j = 1 ; j <= n ; j++ ){
            mix(i, j);
        }
    }

    res += ma;
    ans += num;
    for( int i = 0 ; i < k ; i++ ){
        int x = spot[i].f;
        int y = spot[i].s;

        if( graph[x][y] == 1 ) continue;

        num++;
        graph[x][y] = 1;
        mix(x, y);
        res += ma;
        ans += num;
    }
    cout << res << "\n" << ans << "\n";
}