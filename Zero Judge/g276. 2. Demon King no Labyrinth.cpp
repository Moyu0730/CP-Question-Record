/* Question : ZeroJudge g276. 2. Demon King no Labyrinth */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define F first
#define S second
#define X first
#define Y second

// const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 500 + 50;
const int Mod = 1e9 + 7;
const int INF = 1e9;

int n, m, k, amt, remain, idx;
int pos[MAXN][10], dir[MAXN][10], rmv[MAXN];
bool valid[MAXN][MAXN], live[MAXN];

signed main(){
    opt;
    cin >> n >> m >> k;

    for( int i = 0 ; i < k ; i++ ) cin >> pos[i][0] >> pos[i][1] >> dir[i][0] >> dir[i][1];
    
    memset(live, true, sizeof(live)); // Set live array default value to true
    memset(valid, true, sizeof(valid)); // Set live array default value to true

    remain = k;
    while( remain > 0 ){
        idx = -1;

        for( int i = 0 ; i < k ; i++ ){
            if( !live[i] ) continue;
            if( !valid[pos[i][0]][pos[i][1]] ) continue;

            // Position the Bomb
            valid[pos[i][0]][pos[i][1]] = false;

            // Increase the Amount of Bomb
            amt++;
        }

        for( int i = 0 ; i < k ; i++ ){
            if( !live[i] ) continue;
                
            // Move
            pos[i][0] += dir[i][0];
            pos[i][1] += dir[i][1];

            // Boundary Judgment
            if( pos[i][0] < 0 || pos[i][0] >= n || pos[i][1] < 0 || pos[i][1] >= m ){
                live[i] = false;
                remain--;
                continue;
            }

            // Check Whether Ctn Position Has Bomb
            if( !valid[pos[i][0]][pos[i][1]] ){
                live[i] = false;
                remain--;
                idx++;
                rmv[idx] = i;
            }
        }

        if( idx != -1 ){
            // Bomb Explosion
            for( int i = 0 ; i <= idx ; i++ ){
                int cnt = rmv[i];
                if( valid[pos[cnt][0]][pos[cnt][1]] ) continue;

                // Remove the Bomb
                amt--;
                valid[pos[cnt][0]][pos[cnt][1]] = true;
            }
        }
    }

    cout << amt << "\n";
}