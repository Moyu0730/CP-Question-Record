/* Question : TCIRC d042. AP325 P-4-1. Shaolin Temple Tokens */

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
#define X first
#define Y second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
int n, q, res, amt;
int coin[5] = {50, 10, 5, 1};

signed main(){
    opt;
    cin >> n;
    while( n-- ){
        cin >> q;

        res = 0;
        for( int i = 0 ; i < 4 ; i++ ){
            res += q / coin[i];
            q -= ( q / coin[i] ) * coin[i];
        }

        cout << res << "\n";
    }
}