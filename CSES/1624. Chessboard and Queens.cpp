/* Question : CSES 1624. Chessboard and Queens */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mem(x) memset(x, 0x3F, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define f first
#define s second

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 8 + 50;
const int Mod = 1e9 + 7;
char grid[MAXN][MAXN];
int res;

void sol( int n, int l, int r, int v ){
    if( n == 9 ){
        res++;
        return;
    }

    l <<= 1;
    r >>= 1;
    for( int i = 0 ; i < 8 ; i++ ){
        if( l & ( 1 << i ) ) continue;
        if( r & ( 1 << i ) ) continue;
        if( v & ( 1 << i ) ) continue;
        if( grid[n-1][i] == '*' ) continue;

        sol( n + 1, l | ( 1 << i ), r | ( 1 << i ), v | ( 1 << i ) );
    }
}

signed main(){
    opt;
    for( int i = 0 ; i < 8 ; i++ ){
        for( int j = 0 ; j < 8 ; j++ ) cin >> grid[i][j];
    }
    sol(1, 0, 0, 0);
    cout << res;
}