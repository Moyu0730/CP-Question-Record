/* Question : CSES 1619. Restaurant Customers */

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
const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
int n, a, b, res, cnt;
vector<pii> t;

signed main(){
    opt;
    cin >> n;
    for( int i = 0 ; i < n ; i++ ){
        cin >> a >> b;
        t.pb({a, 1});
        t.pb({b, -1});
    }

    sort(t.begin(), t.end());

    res = -1;
    for( auto i : t ){
        cnt += i.s;
        res = max(res, cnt);
    }

    cout << res << "\n";
}