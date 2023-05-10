/* Question : CSES 1193 Labyrinth */

#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<math.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int MAXN = 1e3 + 50;
const int Mod = 1e9 + 7;
char grid[MAXN][MAXN];
bool visited[MAXN][MAXN] = {false};
int n, m;
pair<int, int> start;
auto dir = vector< tuple<int, int, string> > { {0, 1, "R"}, {1, 0, "D"}, {-1, 0, "U"}, {0, -1, "L"} };
queue< pair< vector<int>, string> > q;

signed main(){
    opt;
    cin >> n >> m;
    for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j < m ; j++ ){
            cin >> grid[i][j];

            if( grid[i][j] == 'A' ){
                start.first = i;
                start.second = j;
            }
        }
    }

    // Init
    q.push({{start.first, start.second, 0}, ""});
    visited[start.first][start.second] = true;
    bool flag = false;

    while( !q.empty() ){
        int len = q.size();
        while( len-- ){
            int x = q.front().first[0];
            int y = q.front().first[1];
            int num = q.front().first[2];
            string route = q.front().second;
            q.pop();

            for( int t = 0 ; t < 4 ; t++ ){
                int i = x + get<0>(dir[t]);
                int j = y + get<1>(dir[t]);
                string d = get<2>(dir[t]);

                // Skip Operation
                if( i < 0 || i >= n || j < 0 || j >= m ) continue;
                if( grid[i][j] == '#' ) continue;
                if( visited[i][j] ) continue;

                // Success Move
                visited[i][j] = true;
                string ctn = route + d;
                q.push({{i, j, num+1}, ctn});

                if( grid[i][j] == 'B' ){
                    flag = true;
                    break;
                }
            }

            if( flag ) break;
        }
        if( flag ) break;
    }

    if( flag ) cout << "YES\n" << q.back().first[2] << "\n" << q.back().second;
    else cout << "NO";
}