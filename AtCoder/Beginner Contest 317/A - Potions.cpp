/* Question : AtCoder Beginner Contest 317 - A - Potions */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pirq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define f first
#define s second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e2 + 50;
const int Mod = 1e9 + 7;
int n, h, x, tar, arr[MAXN];

signed main(){
    opt;
    cin >> n >> h >> x;
    for( int i = 0 ; i < n ; i++ ) cin >> arr[i];

    tar = x - h;
    cout << lower_bound(arr, arr+n, tar) - arr + 1 << "\n";
}