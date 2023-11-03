/* Question : ZeroJudge b900. 3. Squirmy Worm */

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

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e3 + 50;
const int Mod = 1e9 + 7;
int h, w, cnt;
char grid[MAXN][MAXN];

signed main(){
    opt;
    cin >> w >> h;
    for( int i = 1 ; i <= h ; i++ ){
        for( int j = 0 ; j <= w * 2 ; j++ ){
            if( j == 0 || j == w * 2 ){
                grid[i][j] = '.';
                continue;
            }
            cin >> grid[i][j];
        }
    }

    for( int i = 1 ; i <= w * 2 - 1 ; i += 2 ){
        cnt = i;
        for( int j = 1 ; j <= h ; j++ ){
            if( grid[j][cnt-1] == '-' ) cnt -= 2;
            else if( grid[j][cnt+1] == '-' ) cnt += 2;
        }

        cout << (cnt + 1)/2 << " ";
    }
    cout << "\n";
}