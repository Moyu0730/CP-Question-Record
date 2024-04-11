/* Question : TCIRC d057. AP325 Q-4-16. Making Money and Fines */

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
int n, now, res;
vector<pii> tsk;

signed main(){
    opt;
    cin >> n;

    tsk.resize(n);
    for( int i = 0 ; i < n ; i++ ) cin >> tsk[i].F;
    for( int i = 0 ; i < n ; i++ ) cin >> tsk[i].S;

    sort(tsk.begin(), tsk.end());

    for( int i = 0 ; i < n ; i++ ){
        now += tsk[i].F;
        res += tsk[i].S - now;
    }

    cout << res << "\n";
}