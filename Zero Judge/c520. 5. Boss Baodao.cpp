/* Question : ZeroJudge c520. 5. Boss Baodao */

#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma loop-opt(on)
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,tune=native")
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
const int MAXN = 6e3 + 50;
const int Mod = 1e9 + 7;
int h, w, n, res, x, y;
char grid[MAXN][MAXN];
bool used[MAXN][MAXN];
vector<pii> q, nxtq;

signed main(){
    opt;
    cin >> h >> w;
    for( int i = 0 ; i < h ; i++ ) cin >> grid[i];

    cin >> n;
    for( int i = 0 ; i < n ; i++ ){
        cin >> x >> y;
        x--; y--;
        if( !used[x][y] ){
            used[x][y] = true;
            q.pb({x, y});
        }

        while ( !q.empty() ) {
            auto [x, y] = q.back(); 
            q.pop_back();
            res++;

            for( int d = 0 ; d < 4 ; d++ ){
                int nx = x + dir[d].f;
                int ny = y + dir[d].s;

                if( nx < 0 || nx >= h || ny < 0 || ny >= w ) continue;
                if( grid[nx][ny] == '#' ) continue;
                if( used[nx][ny] == true ) continue;

                used[nx][ny] = true;
                nxtq.pb({nx, ny});
            }
        }

        swap(q, nxtq);
        cout << res << '\n';
    }
}