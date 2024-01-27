/* Question : TCIRC d033. AP325 P-3-9. Most Color Bands */

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
int n, l, color[MAXN], cnt[MAXN], now, res;

signed main(){
    opt;
    cin >> n >> l;
    
    for( int i = 1 ; i <= n ; i++ ){
        cin >> color[i];

        if( i <= l ){
            if( cnt[color[i]] == 0 ) now++;

            cnt[color[i]]++;
        }else{
            if( cnt[color[i-l]] == 1 ) now--;
            cnt[color[i-l]]--;

            if( cnt[color[i]] == 0 ) now++;
            cnt[color[i]]++;
        }

        res = max(res, now);
    }

    cout << res << "\n";
}