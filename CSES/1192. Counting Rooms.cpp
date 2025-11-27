/* Question : CSES 1192. Counting Rooms */

#include<bits/stdc++.h>
using namespace std;
 
int n, m, ans, tmp;
string s;
char gph[1005][1005];
bool visited[1005][1005];
queue< vector<int> > q;
auto dir = vector< pair<int, int> > ({ {0, 1}, {1, 0}, {-1, 0}, {0, -1} });
 
signed main (){
	cin >> n >> m;
	for( int i = 1 ; i <= n ; i++ ){
		cin >> s;
 		int l = s.size();
 		for( int j = 1 ; j <= l ; j++ ){
  		    gph[i][j] = s[j-1];
 		}
	}
 
    memset(visited, 0, sizeof(visited));
    ans = 0;
	for( int i = 1 ; i <= n ; i++ ){
		for( int j = 1 ; j <= m ; j++ ){
		    if( visited[i][j] == 0 && gph[i][j] == '.' ){
		        q.push({i, j});
		        visited[i][j] = 1;
    			while( !q.empty() ){
    				int len = q.size();
    				while( len-- ){
    					int a = q.front()[0];
    					int b = q.front()[1];
    					q.pop();
    
    					for( int k = 0 ; k < 4 ; k++ ){
    						int x = a + dir[k].first;
    						int y = b + dir[k].second;
    
    						if( gph[x][y] == '.' ){
    							if( visited[x][y] == 0 ){
    							    visited[x][y] = 1;
    							    q.push({x, y});
    							}
    						}
    					}
    				}
    			}
    			ans++;   
		    }
		}
	}
	cout << ans;
}