/* Question : TCIRC d034. AP325 P-3-10. Full-Color Ribbon（Requires Discretization or Dictionary）（@@） */

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
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
int n, now, res, color[MAXN], seq[MAXN], pre[MAXN], cnt[MAXN];
vector<int> arr;

signed main(){
    opt;
    cin >> n;
    for( int i = 0 ; i < n ; i++ ){
        cin >> color[i];
        pre[i] = color[i];
    }

    sort(pre, pre + n);

    arr.pb(pre[0]);
    for( int i = 1 ; i < n ; i++ ){
        if( pre[i] != pre[i-1] ) arr.pb(pre[i]);
    }

    int left = 0, c;
    res = 1e9;
    for( int right = 0 ; right < n ; right++ ){
        while( now == arr.size() ){
            res = min(res, right - left);

            c = lower_bound(arr.begin(), arr.end(), color[left]) - arr.begin();
            if( cnt[c] == 1 ) now--;

            cnt[c]--;
            left++;
        }
        
        c = lower_bound(arr.begin(), arr.end(), color[right]) - arr.begin();

        if( cnt[c] == 0 ) now++;
        cnt[c]++;
    }

    cout << res << "\n";
}