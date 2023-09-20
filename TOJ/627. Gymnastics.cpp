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
const int MAXN = 1e5 + 50;
const int Mod = 1e9 + 7;
int n, m, x, y, arr[MAXN];

signed main(){
    opt;
    cin >> n;
    for( int i = 1 ; i <= n ; i++ ) cin >> arr[i];

    cin >> m;
    while( m-- ){
        cin >> x >> y;
        if( x < y ) swap(x, y);
        int dif = x - y;
        cout << arr[ y  + ( dif / 2 ) ] << "\n";
    }
}