/* Question : TCIRC d051. AP325 P-4-12. One Transaction */

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
const int MAXN = 1e6 + 50;
const int Mod = 1e9 + 7;
const int INF = 1e9;
int n, res, p, arr[MAXN];

signed main(){
    opt;
    cin >> n;

    for( int i = 0 ; i < n ; i++ ) cin >> arr[i];
    
    p = arr[n-1];
    for( int i = n-1 ; i >= 0 ; i-- ){
        if( arr[i] > p ) p = arr[i];

        res = max(res, p - arr[i]);
    }

    cout << res << "\n";
}