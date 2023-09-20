/* Question : CSES 1630. Tasks and Deadlines */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define f first
#define s second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
int n, a, b, ans, last, t;
vector<pii> w;

signed main(){
    opt;
    cin >> n;
    w.resize(n);
    for( int i = 0 ; i < n ; i++ ) cin >> w[i].f >> w[i].s;

    sort(w.begin(), w.end());

    t = 0;
    for( int i = 0 ; i < n ; i++ ){
        t += w[i].f;
        ans += w[i].s - t;
    }

    cout << ans << "\n";
}