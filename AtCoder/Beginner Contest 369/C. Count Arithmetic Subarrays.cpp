/* Question : OJ Number */

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
const int MAXN = 4e5 + 50;
const int Mod = 1e9 + 7;
const int LLINF = 1e18;
const int INF = 1e9;

int n, dif, res, arr[MAXN];
vector<pii> v;
pii cnt;

signed main(){
    #ifndef LOCAL
        opt;
    #endif

    cin >> n;
    cnt = {0, LLINF};
    for( int i = 0 ; i < n ; i++ ){
        cin >> arr[i];

        if( i != 0 ){
            dif = arr[i] - arr[i-1];
            if( cnt.F == 0 || dif != cnt.S ){
                v.pb(cnt);
                
                cnt = {1, dif};
            }else{
                cnt.F++;
            }
        }
    }
    v.pb(cnt);

    for( int i = 0 ; i < v.size() ; i++ ){
        res += v[i].F * ( v[i].F + 1 ) / 2;
    }

    res += n;

    cout << res << "\n";
}
