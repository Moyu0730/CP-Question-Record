/* Question : AtCoder Beginner Contest 182 - D. Wandering */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define priq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define f first
#define s second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
int n, cnt, res, last;
int arr[MAXN], pre[MAXN];
vector<int> valid;

signed main(){
    cin >> n;

    valid.pb(0);
    for( int i = 1 ; i <= n ; i++ ){
        cin >> arr[i];
        if( arr[i] > 0 ) valid.pb(i);
        pre[i] = pre[i-1] + arr[i];
    }

    cnt = 0;
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j < (int)valid.size() ; j++ ){
            if( valid[j] > i ) break;

            last = valid[j];

            cnt += pre[valid[j]] - pre[valid[j-1]];

            res = max(res, cnt);
        }

        if( last != i ) cnt += pre[i] - pre[last];
    }

    cout << res << "\n";
}
