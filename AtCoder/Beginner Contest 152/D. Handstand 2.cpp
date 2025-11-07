/* Question : AtCoder Beginner Contest 152 - D - Handstand 2 */

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
const int MAXN = 1e4 + 50;
const int Mod = 1e9 + 7;
int n, ans, arr[MAXN][MAXN];

int topN( int val ){
    while( val >= 10 ) val /= 10;
    return val;
}


signed main(){
    opt;
    cin >> n;
    for( int i = 1 ; i <= n ; i++ ){
        int t = topN(i);
        int b = i % 10;
        arr[t][b]++;
    }

    for( int i = 1 ; i <= 9 ; i++ ){
        for( int j = 1 ; j <= 9 ; j++ ){
            ans += arr[i][j] * arr[j][i];
        }
    }

    cout << ans << "\n";
}