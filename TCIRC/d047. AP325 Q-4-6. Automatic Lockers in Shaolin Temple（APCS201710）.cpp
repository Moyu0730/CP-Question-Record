/* Question : TCIRC d047. AP325 Q-4-6. Automatic Lockers in Shaolin Temple（APCS201710） */

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
int n, weight, res;

struct Item {
    int w, f;
} arr[MAXN];

bool cmp( Item a, Item b ){
    return a.w * b.f < b.w * a.f;
}

signed main(){
    opt;
    cin >> n;
    for( int i = 0 ; i < n ; i++ ) cin >> arr[i].w;
    for( int i = 0 ; i < n ; i++ ) cin >> arr[i].f;

    sort(arr, arr + n, cmp);

    for( int i = 1 ; i < n ; i++ ){
        weight += arr[i-1].w;
        res += weight * arr[i].f;
    }

    cout << res << "\n";    
}