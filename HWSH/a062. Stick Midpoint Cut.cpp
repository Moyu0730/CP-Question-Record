/* Question : HWSH a062. Stick Midpoint Cut */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
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
const int MAXN = 5e4 + 50;
const int Mod = 1e9 + 7;
const int INF = 1e9;
int n, l, p[MAXN];

int cut( int left, int right ){
    if( right - left <= 1 ) return 0;

    int mid = ( p[right] + p[left] ) / 2;
    int idx = left;

    while( p[idx] < mid ){
        idx++;
    }

    if( p[idx-1] - p[left] >= p[right] - p[idx] ) idx--;

    return p[right] - p[left] + cut(left, idx) + cut(idx, right);
}

signed main(){
    opt;
    cin >> n >> l;

    p[0] = 0;
    p[n+1] = l;
    for( int i = 1 ; i <= n ; i++ ) cin >> p[i];

    cout << cut(0, n+1) << "\n";
}