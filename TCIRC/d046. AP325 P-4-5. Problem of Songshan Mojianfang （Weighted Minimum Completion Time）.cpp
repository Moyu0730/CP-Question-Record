/* Question : TCIRC d046. AP325 P-4-5. Problem of Songshan Mojianfang （Weighted Minimum Completion Time） */

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
const int MAXN = 1e5 + 50;
const int Mod = 1e9 + 7;
int n, res, cnt;
vector<pii> arr;

bool cmp( pii a, pii b ){
    return (double)a.F / (double)a.S < (double)b.F / (double)b.S;
}

signed main(){
    opt;
    cin >> n;

    arr.resize(n);
    for( int i = 0 ; i < n ; i++ ) cin >> arr[i].F;
    for( int i = 0 ; i < n ; i++ ) cin >> arr[i].S;

    sort(arr.begin(), arr.end(), cmp);

    for( auto i : arr ){
        cnt += i.F;
        res += cnt * i.S;
    }

    cout << res << "\n";
}