/* Question : AtCoder Beginner Contest 196 - D - Hanjo */

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

const auto dir = vector< pair<int, int> > { {0, 0}, {0, 1}, {1, 0} };
const int MAXN = 16 + 50;
const int Mod = 1e9 + 7;
int h, w, a, b, ans, m[MAXN][MAXN];
bool used[MAXN][MAXN];

void dfs( int i, int j, int a, int b ){
    if( a == 0 && b == 0 ){
        ans++; 
        return;
    }
    if( a < 0 || b < 0 ) return;
    if( i > h ) return;

    // Get Next Position
    int ni = i;
    int nj = j + 1;
    if( nj > w ){
        ni++;
        nj = 1;
    }

	if( used[i][j] ){
		dfs(ni, nj, a, b);
		return;
	}

    for( int t = 0 ; t < 3 ; t++ ){
        int y = i + dir[t].f;
        int x = j + dir[t].s;
        
        if( x > w || y > h ) continue;
        if( used[y][x] == true ) continue;

        used[i][j] = true;
        used[y][x] = true;
        if( t == 0 ){
            dfs(ni, nj, a, b-1);
        }else{
            dfs(ni, nj, a-1, b);
        }
        used[i][j] = false;
        used[y][x] = false;
    }
}

signed main(){
    // opt;
    mem(used, false);
    cin >> h >> w >> a >> b;
    dfs(1, 1, a, b);
    cout << ans << "\n";
}