/* Question : OJ Number */

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
const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
const int INF = 1e9;
int n, r, a, b, res;
map<pii, int> mp;

int dis( pii a, pii b ){
    int dx = abs( a.F - b.F );
    int dy = abs( a.S - b.S );

    return dx * dx + dy * dy;
}

signed main(){
    opt;
    cin >> n >> r;

    while( n-- ){
        cin >> a >> b;
        for( int i = a - r ; i <= a + r ; i++ ){
            for( int j = b - r ; j <= b + r ; j++ ){
                if( dis({i, j}, {a, b}) <= r * r ) mp[{i, j}]++;
            }
        }
    }

    for( auto i = mp.begin() ; i != mp.end() ; i++ ){
        if( (*i).second % 2 ) res++;
    }

    cout << res << "\n";
}