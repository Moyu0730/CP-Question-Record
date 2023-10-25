/* Question : CSES 2191. Polygon Area */

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
int n, res;
vector<pii> pt;

int cross( pii a, pii b ){
    return (a.f * b.s) - (a.s * b.f);
}

signed main(){
    opt;
    cin >> n;
    pt.resize(n);
    cin >> pt[0].f >> pt[0].s;
    for( int i = 1 ; i < n ; i++ ){
        cin >> pt[i].f >> pt[i].s;
        res += cross(pt[i-1], pt[i]);
    }

    res += cross(pt[n-1], pt[0]);
    cout << abs(res) << "\n";
}