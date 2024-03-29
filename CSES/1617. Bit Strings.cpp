/* Question : CSES 1617. Bit Strings */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mem(x) memset(x, 0x3F, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define f first
#define s second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
int n;

signed main(){
    opt;
    cin >> n;
    int ans = 1;
    for( int i = 0 ; i < n ; i++ ){
        ans <<= 1;
        ans %= Mod;
    }
    cout << ans << "\n";
}