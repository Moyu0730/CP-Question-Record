/* Question : CSES 1661. Subarray Sums II */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pirq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define F first
#define S second
#define X first
#define Y second
#define int long long
#define ll long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;

int n, x, res;
vector<int> arr, pre;
map<int, int> mp;

signed main(){
    opt;

    cin >> n >> x;

    arr.resize(n+1);
    pre.resize(n+1);
    pre[0] = 0;
    for( int i = 1 ; i <= n ; i++ ){
        cin >> arr[i];
        pre[i] = pre[i-1] + arr[i];
    }

    mp[0] = 1;
    for( int i = 1 ; i <= n ; i++ ){
        if( mp.find(pre[i] - x) != mp.end() ) res += mp[pre[i] - x];

        mp[pre[i]]++;
    }

    cout << res << "\n";
}