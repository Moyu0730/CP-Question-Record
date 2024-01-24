/* Question : TCIRC d031. AP325 P-3-7. The Closest Interval Sum of A Sequence of Positive Integers */

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
const int MAXN = 2e6 + 50;
const int Mod = 1e9 + 7;
int n, k, sum, l, r, arr[MAXN];
map<int, int> mp;

signed main(){
    opt;
    cin >> n >> k;
    for( int i = 0 ; i < n ; i++ ) cin >> arr[i];

    for( int l = 0 ; l < n ; l++ ){
        if( l != 0 ) sum -= arr[l-1];
        while( sum > k ){
            sum -= arr[l];
            l++;
        }
        while( sum + arr[r] <= k && r != n ){
            sum += arr[r];
            r++;
        }
        mp[sum]++;
    }

    cout << prev(mp.end())->F << "\n" << prev(mp.end())->S << "\n";
}