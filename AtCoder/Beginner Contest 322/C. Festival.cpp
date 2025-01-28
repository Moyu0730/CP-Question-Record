/* Question : AtCoder Beginner Contest 322 - C. Festival */

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
int n, m, ind;
int arr[MAXN];

signed main(){
    opt;
    cin >> n >> m;
    for( int i = 0 ; i < m ; i++ ) cin >> arr[i];

    for( int i = 1 ; i <= n ; i++ ){
        ind = lower_bound(arr, arr+m, i) - arr;
        cout << arr[ind] - i << "\n";
    }
}