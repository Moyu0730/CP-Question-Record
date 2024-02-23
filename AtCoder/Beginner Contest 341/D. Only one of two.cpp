/* Question : AtCoder Beginner Contest 341 - D. Only one of two */

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
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
const int INF = 1e9;
int n, m, k, res, l;

int rk( int x ){
    return ( x / n ) + ( x / m ) - 2 * ( x / l );
}

signed main(){
    opt;
    cin >> n >> m >> k;

    l = ( n * m ) / __gcd(n, m);
    int step = 2e18;
    while( step > 0 ){
        if( rk(step + res) < k ) res += step;
        else step /= 2;
    }

    cout << res + 1 << "\n";
}