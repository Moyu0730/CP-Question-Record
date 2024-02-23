/* Question : TCIRC d049. AP325 P-4-9. Base Station（APCS201703） */

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
const int MAXN = 5e4 + 50;
const int Mod = 1e9 + 7;
const int INF = 1e9;
int n, k, res, p[MAXN];

bool valid( int r ){
    int rt = p[0] + r, amt = 1;

    for( int i = 0 ; i < n ; i++ ){
        if( p[i] <= rt ){
            continue;
        }else{
            rt = p[i] + r;
            amt++;
        }
    }

    return amt <= k;
}

signed main(){
    opt;
    cin >> n >> k;

    for( int i = 0 ; i < n ; i++ ) cin >> p[i];
    sort(p, p + n);

    int step = 1e9;
    while( step > 0 ){
        if( !valid(step + res) ) res += step;
        else step /= 2;
    }

    cout << res + 1 << "\n";
}