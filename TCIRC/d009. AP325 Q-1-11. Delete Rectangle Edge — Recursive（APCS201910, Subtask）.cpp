/* Question : TCIRC d009. AP325 Q-1-11. Delete Rectangle Edge — Recursive（APCS201910, Subtask） */

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
const int MAXN = 13 + 50;
const int Mod = 1e9 + 7;
int n, m, t, f, grid[MAXN][MAXN];

int sol( pii lu, pii dr ){
    if( lu.S == dr.S || lu.F == dr.F ) return 0;

    int res[5] = {0, 0, 0, 0, 0};

    // Up
    t = 0; f = 0;
    for( int i = lu.S ; i <= dr.S ; i++ ){
        if( grid[lu.F][i] ) t++;
        else f++;
    }

    res[0] = min(t, f) + sol({lu.F+1, lu.S}, dr);

    // Down
    t = 0; f = 0;
    for( int i = lu.S ; i <= dr.S ; i++ ){
        if( grid[dr.F][i] ) t++;
        else f++;
    }

    res[1] = min(t, f) + sol(lu, {dr.F-1, dr.S});

    // Left
    t = 0; f = 0;
    for( int i = lu.F ; i <= dr.F ; i++ ){
        if( grid[i][lu.S] ) t++;
        else f++;
    }

    res[2] = min(t, f) + sol({lu.F, lu.S+1}, dr);

    // Right
    t = 0; f = 0;
    for( int i = lu.F ; i <= dr.F ; i++ ){
        if( grid[i][dr.S] ) t++;
        else f++;
    }

    res[3] = min(t, f) + sol(lu, {dr.F, dr.S-1});

    // Res
    int ans = 1e8;
    for( int i = 0 ; i <= 3 ; i++ ) ans = min(ans, res[i]);

    return ans;
}

signed main(){
    opt;
    cin >> n >> m;
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= m ; j++ ) cin >> grid[i][j];
    }

    cout << sol({1, 1}, {n, m}) << "\n";
}