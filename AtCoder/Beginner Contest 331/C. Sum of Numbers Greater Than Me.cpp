/* Question : AtCoder Beginner Contest 331 - C. Sum of Numbers Greater Than Me */

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
int n, arr[MAXN], pre[MAXN];
vector<int> v;

signed main(){
    opt;
    cin >> n;
    for( int i = 0 ; i < n ; i++ ){
        cin >> arr[i];
        v.pb(arr[i]);
    }
    v.pb(0);

    sort(v.begin(), v.end());
    for( int i = 1 ; i <= n ; i++ ) pre[i] = pre[i-1] + v[i];

    for( int i = 0 ; i < n ; i++ ){
        int it = upper_bound(v.begin(), v.end(), arr[i]) - v.begin();
        
        if( it > n ) cout << 0 << " ";
        else cout << pre[n] - pre[it-1] << " ";
    }

    cout << "\n";
}