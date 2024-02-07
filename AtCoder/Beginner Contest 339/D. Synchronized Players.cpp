/* Question : AtCoder Beginner Contest 339 - D. Synchronized Players */

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
const int MAXN = 60 + 10;
const int Mod = 1e9 + 7;
int n;
pii a, b;
vector<vector<char>> graph;
queue<pair<pii, pii>> q;
int used[MAXN][MAXN][MAXN][MAXN];

signed main(){
    opt;
    cin >> n;

    graph.resize(n+5);
    for( int i = 1 ; i <= n ; i++ ){
        graph[i].resize(n+5);
        for( int j = 1 ; j <= n ; j++ ){
            cin >> graph[i][j];

            if( graph[i][j] == 'P' && a.F == 0 ) a = {i , j};
            else if( graph[i][j] == 'P' ) b = {i, j};
        }
    }

    used[a.F][a.S][b.F][b.S] = 1;
    used[b.F][b.S][a.F][a.S] = 1;
    q.push({a, b});

    while( !q.empty() ){
        a = q.front().F;
        b = q.front().S;
        q.pop();

        for( int t = 0 ; t < 4 ; t++ ){
            pii x = { a.F + dir[t].F, a.S + dir[t].S };
            pii y = { b.F + dir[t].F, b.S + dir[t].S };

            if( x.F <= 0 || x.F > n || x.S <= 0 || x.S > n ) x = a;
            if( y.F <= 0 || y.F > n || y.S <= 0 || y.S > n ) y = b;
            if( graph[x.F][x.S] == '#' ) x = a;
            if( graph[y.F][y.S] == '#' ) y = b;
            if( used[x.F][x.S][y.F][y.S] != 0 ) continue;
            if( x == y ){
                cout << used[a.F][a.S][b.F][b.S] << "\n";
                exit(0);
            }

            q.push({x, y});
            used[x.F][x.S][y.F][y.S] = used[a.F][a.S][b.F][b.S] + 1;
            used[y.F][y.S][x.F][x.S] = used[a.F][a.S][b.F][b.S] + 1;
        }
    }

    cout << "-1\n";
}