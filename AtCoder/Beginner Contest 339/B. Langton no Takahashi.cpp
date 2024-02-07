/* Question : AtCoder Beginner Contest 339 - B. Langton's Takahashi */

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

const auto dir = vector<pii> { {-1, 0}, // Up
                               {0, 1}, // Right
                               {1, 0}, // Down
                               {0, -1} }; // Left   
                                            
const int MAXN = 1e4 + 50;
const int Mod = 1e9 + 7;
int h, w, n, face;
char grid[MAXN][MAXN];
pii cnt;

signed main(){
    // opt;
    cin >> h >> w >> n;

    mem(grid, '.');

    cnt = {1, 1};
    face = 0;
    for( int i = 0 ; i < n ; i++ ){
        if( grid[cnt.F][cnt.S] == '.' ){
            grid[cnt.F][cnt.S] = '#';
            face = face == 3 ? 0 : face + 1;
            cnt = {cnt.F + dir[face].F, cnt.S + dir[face].S};
        }else{
            grid[cnt.F][cnt.S] = '.';
            face = face == 0 ? 3 : face - 1;
            cnt = { cnt.F + dir[face].F, cnt.S + dir[face].S };
        }

        if( cnt.F == 0 ) cnt.F = h;
        if( cnt.F == h+1 ) cnt.F = 1;
        if( cnt.S == 0 ) cnt.S = w;
        if( cnt.S == w+1 ) cnt.S = 1;
    }

    cout << "\n";
    for( int i = 1 ; i <= h ; i++ ){
        for( int j = 1 ; j <= w ; j++ ) cout << grid[i][j];
        cout << "\n";
    }
}