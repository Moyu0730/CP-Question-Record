/* Question : CSES 1625. Grid Paths */
 
#include<bits/stdc++.h>
using namespace std;
 
#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pirq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define F first
#define S second
#define X first
#define Y second
#define int long long
#define ll long long
 
const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 7 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;
 
string str;
int ans;
bool used[MAXN][MAXN];
 
void solve( int cnt, int x, int y ){
    if( used[x][y] ) return;

    /* At End Position But Step < Size */
    if( x == 1 && y == 7 && cnt < str.size() ) return;

    if( used[x-1][y] && used[x+1][y] && !used[x][y+1] && !used[x][y-1] ) return;
    if( !used[x-1][y] && !used[x+1][y] && used[x][y+1] && used[x][y-1] ) return;

    if( used[x-1][y-1] && !used[x][y-1] && !used[x-1][y] ) return;
    if( used[x+1][y-1] && !used[x][y-1] && !used[x+1][y] ) return;
    if( used[x-1][y+1] && !used[x-1][y] && !used[x][y+1] ) return;
    if( used[x+1][y+1] && !used[x+1][y] && !used[x][y+1] ) return;

    if( cnt == str.size() ){
        ans++;
        return;
    }
 
    used[x][y] = true;
 
    if( str[cnt] == 'D' ) solve(cnt+1, x, y + 1);
    if( str[cnt] == 'U' ) solve(cnt+1, x, y - 1);
    if( str[cnt] == 'L' ) solve(cnt+1, x - 1, y);
    if( str[cnt] == 'R' ) solve(cnt+1, x + 1, y);
    if( str[cnt] == '?' ) {
        for( int t = 0 ; t < 4 ; t++ ){
            solve(cnt+1, x + dir[t].F, y + dir[t].S);
        }
    }
 
    used[x][y] = false;
}

signed main(){
    opt;
 
    cin >> str;

    /* Create Already Been Used Border */
    for( int i = 1 ; i <= 7 ; i++ ){
        used[i][0] = true;
        used[8][i] = true;
        used[i][8] = true;
        used[0][i] = true;
    }

    solve(0, 1, 1);
 
    cout << ans << "\n";
}