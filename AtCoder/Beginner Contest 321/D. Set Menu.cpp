/* Question : AtCoder Beginner Contest 321 - D. Set Menu */

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
int n, m, p, res, ma[MAXN], side[MAXN], pre[MAXN];

signed main(){
    opt;
    cin >> n >> m >> p;
    for( int i = 0 ; i < n ; i++ ) cin >> ma[i];
    for( int i = 0 ; i < m ; i++ ){
        cin >> side[i];
    }

    sort(ma, ma + n);
    sort(side, side + m);

    for( int i = 0 ; i < m ; i++ ) pre[i] = i == 0 ? side[i] : pre[i-1] + side[i];

    for( int i = 0 ; i < n ; i++ ){
        int dif = p - ma[i];
        if( dif <= 0 ){
            res += m * p;
            continue;
        }

        int ind = lower_bound(side, side + m, dif) - side;
        if( ind == 0 ) res += m * p;
        else res += ma[i] * ind + pre[ind-1] + p * ( m - ind );
    }

    cout << res << "\n";
}