/* Question : TCIRC d054. AP325 Q-4-10. White Cloud Bear Gallbladder Pills to Restore Energy */

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
const int MAXN = 1e5 + 50;
const int Mod = 1e9 + 7;
const int INF = 1e9;
int n, m, res, p[MAXN];

bool valid( int f ){
    int amt = 0, cnt;

    cnt = f;
    for( int i = 0 ; i < n ; i++ ){
        if( cnt >= p[i] ) cnt -= p[i];
        else if( f < p[i] ) return false;
        else{
            cnt = f;
            cnt -= p[i];
            amt++;
        }
    }

    return amt <= m;
}

signed main(){
    opt;
    cin >> n >> m;
    for( int i = 0 ; i < n ; i++ ) cin >> p[i];

    int step = 1e5;
    while( step > 0 ){
        if( !valid(res + step) ) res += step;
        else step /= 2;
    }

    cout << res + 1 << "\n";
}