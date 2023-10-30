/* Question : AtCoder Beginner Contest 325 - C. Sensors */

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

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1} };
const int MAXN = 1e3 + 50;
const int Mod = 1e9 + 7;
int n, m, res;
char grid[MAXN][MAXN];
bool used[MAXN][MAXN];
queue<pii> q;

void bfs( int i, int j ){
    used[i][j] = true;
    q.push({i, j});

    while( !q.empty() ){
        pii cnt = q.front();
        q.pop();

        for( int t = 0 ; t < 8 ; t++ ){
            int dx = dir[t].f;
            int dy = dir[t].s;
            pii nxt = {cnt.f + dx, cnt.s + dy};

            if( nxt.f == -1 || nxt.f == n || nxt.s == -1 || nxt.s == m ) continue;
            if( used[nxt.f][nxt.s] == true ) continue;
            if( grid[nxt.f][nxt.s] == '.' ) continue;

            used[nxt.f][nxt.s] = true;
            q.push(nxt);
        }
    }

    res++;
    return;
}

signed main(){
    opt;
    cin >> n >> m;
    for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j < m ; j++ ) cin >> grid[i][j];
    }

    for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j < m ; j++ ){
            if( grid[i][j] == '#' && used[i][j] == false ) bfs(i, j);
        }
    }

    cout << res << "\n";
}