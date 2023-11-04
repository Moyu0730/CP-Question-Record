/* Question : AtCoder Beginner Contest 327 - C. Number Place */

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
#define x first
#define y second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 9 + 50;
const int Mod = 1e9 + 7;
int amt, grid[MAXN][MAXN];
bool valid, used[MAXN];

void col( int cnt ){
    mem(used, false);
    amt = 0;

    for( int i = 1 ; i <= 9 ; i++ ){
        if( !used[grid[i][cnt]] ){
            used[grid[i][cnt]] = true;
            amt++;
        }
    }

    if( amt != 9 ) valid = false;
    
    return;
}

void row( int cnt ){
    mem(used, false);
    amt = 0;

    for( int j = 1 ; j <= 9 ; j++ ){
        if( !used[grid[cnt][j]] ){
            used[grid[cnt][j]] = true;
            amt++;
        }
    }

    if( amt != 9 ) valid = false;
    
    return;
}

void sq( pii cnt ){
    mem(used, false);
    amt = 0;

    for( int i = cnt.F ; i <= cnt.F + 2 ; i++ ){
        for( int j = cnt.S ; j <= cnt.S + 2 ; j++ ){
            if( !used[grid[i][j]] ){
                used[grid[i][j]] = true;
                amt++;
            }
        }
    }
    if( amt != 9 ) valid = false;
    
    return;
}

signed main(){
    opt;
    for( int i = 1 ; i <= 9 ; i++ ){
        for( int j = 1 ; j <= 9 ; j++ ) cin >> grid[i][j];
    }

    valid = true;

    for( int i = 1 ; i <= 9 ; i++ ){
        row(i);
        col(i);
    }

    for( int i = 1 ; i <= 9 ; i += 3 ){
        for( int j = 1 ; j <= 9 ; j += 3 ) sq({i, j});
    }

    if( valid ) cout << "Yes\n";
    else cout << "No\n";
}