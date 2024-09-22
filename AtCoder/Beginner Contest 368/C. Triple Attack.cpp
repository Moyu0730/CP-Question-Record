/* Question : AtCoder Beginner Contest 368 - C. Triple Attack */

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
const int LLINF = 1e18;
const int INF = 1e9;

int n, res, h;
int turn[3] = {1, 1, 3};

signed main(){
    #ifndef LOCAL
        opt;
    #endif

    cin >> n;
    for( int i = 0 ; i < n ; i++ ){
        cin >> h;

        res += ( h / 5 ) * 3;
        h %= 5;
        
        while( h > 0 ){
			h -= turn[res % 3];
			res++;
		}
    }

    cout << res << "\n";
}