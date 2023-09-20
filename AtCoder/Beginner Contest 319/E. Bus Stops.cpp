/* Question : AtCoder Beginner Contest 319 - E - Bus Stops */

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
const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
int n, x, y, cnt, q;
vector<pii> bus;

signed main(){
    opt;
    cin >> n >> x >> y;
    bus.resize(n+1);
    for( int i = 0 ; i < n-1 ; i++ ) cin >> bus[i].f >> bus[i].s;
    
    cin >> q;
    while( q-- ){
        cin >> cnt;
        cnt += x;
        for( int i = 0 ; i < n-1 ; i++ ){
            if( cnt % bus[i].f != 0 ) cnt += ( ( cnt / bus[i].f ) + 1 ) * bus[i].f - cnt;
            cnt += bus[i].s;
        }
        cnt += y;
        cout << cnt << "\n";
    }
}