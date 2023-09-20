/* Question : OJ Number */

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
const int MAXN = 37 + 50;
const int Mod = 1e9 + 7;
int n, x, bt, cnt;
vector<vector<pii>> v;
vector<int> res;

signed main(){
    opt;
    cin >> n;

    v.resize(MAXN);
    for( int i = 1 ; i <= n ; i++ ){
        cin >> bt;
        for( int j = 0 ; j < bt ; j++ ){
            cin >> cnt;
            v[cnt].pb({bt, i});
        }
    }
    cin >> x;

    sort(v[x].begin(), v[x].end());
    int amt = 0, low = v[x][0].f;
    for( auto i : v[x] ){
        if( i.f <= low ){
            amt++;
            res.pb(i.s);
        }
    }

    cout << amt << "\n";
    if( amt != 0 ){
        for( auto i : res ) cout << i << " ";
        cout << "\n";
    }
}