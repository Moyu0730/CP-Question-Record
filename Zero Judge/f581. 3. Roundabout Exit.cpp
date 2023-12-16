/* Question : ZeroJudge f581. 3. Roundabout Exit */

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
const int MAXN = 5e5 + 50;
const int Mod = 1e9 + 7;
int n, m, val, p[MAXN], pre[MAXN];

signed main(){
    opt;
    cin >> n >> m;

    pre[0] = 0;
    for( int i = 1 ; i <= n ; i++ ){
        cin >> p[i];
        pre[i] = pre[i-1] + p[i];
    }

    for( int i = n+1 ; i <= 2 * n ; i++ ) pre[i] = pre[i-1] + p[i-n];

    int now = 1, nxt;
    while( m-- ){
        cin >> val;

        nxt = lower_bound(pre + now - 1, pre + 2 * n + 1, pre[now-1] + val) - pre + 1;
        if( nxt >= n+1 ) nxt++;
    
        now = nxt % (n+1);
    }

    cout << now - 1 << "\n";
}