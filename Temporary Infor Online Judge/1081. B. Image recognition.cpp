/* Question : TIOJ 1081. B. Image recognition */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); 

const int MAXN = 1e3 + 50;
const int Mod = 1e9 + 7;
int m, n, res, x, y, a, b;
bool flag;
string str;
int graph[MAXN][MAXN];
bool visited[MAXN][MAXN];
queue<pair<int, int>> q;
auto dir = vector<pair<int, int> > { {-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {0, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1} };

signed main(){
    // opt;
    while( cin >> n >> m ){
        if( n == 0 && m == 0 ) break;

        memset( visited, false, sizeof(visited));
        for( int i = 0 ; i < n ; i++ ){
            cin >> str;
            for( int j = 0 ; j < m ; j++ ){
                graph[i][j] = str[j] - 48;
            }
        }

        res = 0;
        
        for( int i = 0 ; i < n ; i++ ){
            for( int j = 0 ; j < m ; j++ ){
                flag = false;
                if( visited[i][j] == false ){
                    q.push({i, j});
                    while( !q.empty() ){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        for( int t = 0 ; t < 8 ; t++ ){
                            int a = x + dir[t].first;
                            int b = y + dir[t].second;

                            if( a < 0 || b < 0 || a >= n || b >= m ) continue;
                            if( visited[a][b] == true ) continue;
                            if( graph[a][b] == 0 ){
                                visited[a][b] = true;
                            }else{
                                visited[a][b] = true;
                                q.push({a, b});
                                if( flag == false ){
                                    res++;
                                    flag = true;
                                }
                            }
                        }
                    }
                }
            }
        }

        cout << res << "\n";
    }
}