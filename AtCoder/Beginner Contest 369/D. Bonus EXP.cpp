/* Question : AtCoder Beginner Contest 369 - D. Bonus EXP */

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
#define ll long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
const int LLINF = 1e17;
const int INF = 1e9;

int n, dpOdd, dpEven, tmp, val;

signed main(){
    #ifndef LOCAL
        opt;
    #endif

    cin >> n;

    dpOdd = -1 * LLINF;
    dpEven = 0;
    for( int i = 0 ; i < n ; i++ ){
        cin >> val;
        tmp = dpOdd;
        dpOdd = max(dpOdd, dpEven + val);
        dpEven = max(dpEven, tmp + (2 * val));
    }

    cout << max(dpOdd, dpEven) << "\n";
}