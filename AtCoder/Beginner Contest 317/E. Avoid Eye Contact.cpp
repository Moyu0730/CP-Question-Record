/* Question : AtCoder Beginner Contest 317 - E - Avoid Eye Contact */

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
const int MAXN = 2e3 + 50;
const int Mod = 1e9 + 7;
int n, m, res = -1;
char grid[MAXN][MAXN];
pii st, ed;
vector<pii> p;
queue<pii> q;
int dis[MAXN][MAXN];

void bfs(){
    q.push(st);
    mem(dis, -1);
    dis[st.f][st.s] = 0;
    while( !q.empty() ){
        pii cnt = q.front();
        q.pop();

        for( int t = 0 ; t < 4 ; t++ ){
            pii nxt = {cnt.f + dir[t].f, cnt.s + dir[t].s};

            if( nxt.f >= n || nxt.f < 0 || nxt.s >= m || nxt.s < 0 ) continue;
            if( grid[nxt.f][nxt.s] == '#' || grid[nxt.f][nxt.s] == '!' ) continue;
            if( dis[nxt.f][nxt.s] != -1 ) continue;

            dis[nxt.f][nxt.s] = dis[cnt.f][cnt.s] + 1;
            q.push(nxt);
        }
    }
}

signed main(){
    opt;
    cin >> n >> m;
    for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j < m ; j++ ){
            cin >> grid[i][j];
            if( grid[i][j] == '^' || grid[i][j] == 'v' || grid[i][j] == '<' || grid[i][j] == '>' ) p.pb({i, j});
            if( grid[i][j] == 'S' ) st = {i, j};
            if( grid[i][j] == 'G' ) ed = {i, j};
        }
    }

    for( auto i : p ){
        if( grid[i.f][i.s] == '^' ){
            for( int d = i.f - 1 ; d >= 0 ; d-- ){
                if( grid[d][i.s] != '.' && grid[d][i.s] != '!' ) break;
                grid[d][i.s] = '!';
            }
        }else if( grid[i.f][i.s] == 'v' ){
            for( int d = i.f + 1 ; d < n ; d++ ){
                if( grid[d][i.s] != '.' && grid[d][i.s] != '!' ) break;
                grid[d][i.s] = '!';
            } 
        }else if( grid[i.f][i.s] == '<' ){
            for( int d = i.s - 1 ; d >= 0 ; d-- ){
                if( grid[i.f][d] != '.' && grid[i.f][d] != '!' ) break;
                grid[i.f][d] = '!';
            }
        }else if( grid[i.f][i.s] == '>' ){
            for( int d = i.s + 1 ; d < m ; d++ ){
                if( grid[i.f][d] != '.' && grid[i.f][d] != '!' ) break;
                grid[i.f][d] = '!';
            }
        }
        grid[i.f][i.s] = '#';
    }

    bfs();

    // cout << "\n";
    // for( int i = 0 ; i < n ; i++ ){
    //     for( int j = 0 ; j < m ; j++ ){
    //         cout << grid[i][j];
    //     }
    //     cout << "\n";
    // }

    // cout << "\n";
    // for( int i = 0 ; i < n ; i++ ){
    //     for( int j = 0 ; j < m ; j++ ){
    //         cout << dis[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << dis[ed.f][ed.s] << "\n";
}