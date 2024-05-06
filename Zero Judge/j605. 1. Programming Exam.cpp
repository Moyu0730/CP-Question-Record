/* Question : ZJ j605. 1. Programming Examr */

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

int k, t, s, high, ti, err;

signed main(){
    opt;
    
    cin >> k;

    high = -10;
    for( int i = 0 ; i < k ; i++ ){
        cin >> t >> s;

        if( s == -1 ) err++;
        else if( high < s ){
            high = s;
            ti = t;
        }
    }

    int res = high - k - (err * 2);

    if( res < 0 ) cout << 0 << " " << ti << "\n";
    else cout << res << " " << ti << "\n";
}