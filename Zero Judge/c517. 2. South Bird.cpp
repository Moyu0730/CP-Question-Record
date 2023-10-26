/* Question : ZeroJudge c517. 2. South Bird */

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
pii cnt, r, l;
int res;

signed main(){
    opt;
    cin >> cnt.f >> cnt.s;
    cin >> l.f >> l.s;
    cin >> r.f >> r.s;

    if( cnt.f < l.f ) res += abs(l.f - cnt.f);
    else if( cnt.f > r.f ) res += abs(cnt.f - r.f);

    if( cnt.s > r.s ) res += abs(cnt.s - r.s);
    else if( cnt.s < l.s ) res += abs(cnt.s - l.s);

    cout << res << "\n";
}