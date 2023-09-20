/* Question : CSES 1618. Trailing Zeros */

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
int n, ans, two, five, tmp;

signed main(){
    opt;
    cin >> n;
    for( int i = 5 ; i <= n ; i += 5 ){
        tmp = i;
        while( tmp % 5 == 0 ){
            ans++;
            tmp /= 5;
        }
    }

    cout << ans << "\n";
}