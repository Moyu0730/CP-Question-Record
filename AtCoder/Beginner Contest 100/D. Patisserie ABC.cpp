/* Question : AtCoder Beginner Contest 100 - D - Patisserie ABC */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define f first
#define s second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e3 + 50;
const int Mod = 1e9 + 7;
int n, m, b, t, p, res, cake[MAXN][3+5];

int Sum(){
    int ans = 0, t[MAXN];
    for( int i = 0 ; i < n ; i++ ) t[i] = cake[i][0] + cake[i][1] + cake[i][2];

    sort(t, t+n, greater<int>());
    for( int i = 0 ; i < m ; i++ ) ans += t[i];

    return ans;
}

signed main(){
    opt;
    cin >> n >> m;
    for( int i = 0 ; i < n ; i++ ) cin >> cake[i][0] >> cake[i][1] >> cake[i][2];

    res = -1;
    for( int i = 0 ; i < 2 ; i++ ){
        for( int ind = 0 ; ind < n ; ind++ ) cake[ind][0] *= -1;

        for( int j = 0 ; j < 2 ; j++ ){
            for( int ind = 0 ; ind < n ; ind++ ) cake[ind][1] *= -1;
            
            for( int k = 0 ; k < 2 ; k++ ){
                for( int ind = 0 ; ind < n ; ind++ ) cake[ind][2] *= -1;

                res = max( res, Sum() );
            }
        }
    }

    cout << res << "\n";
}