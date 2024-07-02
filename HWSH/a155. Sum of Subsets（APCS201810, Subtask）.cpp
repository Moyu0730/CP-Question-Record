/* Question : HWSH a155. Sum of Subsets（APCS201810, Subtask） */

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
const int MAXN = 26 + 50;
const int Mod = 1e9 + 7;
const int INF = 1e9;
int n, p, a[MAXN];
int res;

void solve( int i, int sum ){
    if( i >= n ){
        if( sum <= p ) res = max(res, sum);
        return;
    }

    solve( i + 1, sum + a[i] );
    solve( i + 1, sum );
}

signed main(){
    cin >> n >> p;
    for( int i = 0; i < n; i++ ) cin >> a[i];

    res = 0;
    solve(0, 0);
    cout << res << "\n";
}