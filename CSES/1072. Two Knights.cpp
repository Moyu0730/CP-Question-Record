/* Question : CSES 1072. Two Knights */

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
int n;

signed main(){
    opt;
    cin >> n;
    for( int i = 1 ; i <= n ; i++ ) cout << ( i * i ) * ( i * i - 1 ) / 2 - 4 * ( i - 1 ) * ( i - 2 ) << "\n";
}