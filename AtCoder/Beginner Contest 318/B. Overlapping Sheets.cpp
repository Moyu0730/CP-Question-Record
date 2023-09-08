/* Question : AtCoder Beginner Contest 318 - B - Overlapping Sheets */

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

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e2 + 50;
const int Mod = 1e9 + 7;
int n, m, p, reg[MAXN][5], G[MAXN][MAXN], side, depth;

signed main(){
    opt;
    cin >> n;
    for( int i = 0 ; i < n ; i++ ){
        cin >> reg[i][0] >> reg[i][1] >> reg[i][2] >> reg[i][3];
        depth = max(depth, reg[i][1]);
        side = max(side, reg[i][3]);
    }
    
    for( int t = 0 ; t < n ; t++ ){
        for( int i = reg[t][0] ; i < reg[t][1] ; i++ ){
            for( int j = reg[t][2] ; j < reg[t][3] ; j++ ) G[i][j]++;
        }
    }

    int res = 0;
    for( int i = 0 ; i <= depth ; i++ ){
        for( int j = 0 ; j <= side ; j++ ){
            // cout << G[i][j] << " ";
            if( G[i][j] >= 1 ) res++;
        }
        // cout << "\n";
    }

    cout << res << "\n";
}