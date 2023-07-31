/* Question : TOJ 36. Simple Problem */

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
int a, b, c;

int p( int a, int b, int c ){
    int ans = 1;
    while( b > 0 ){
        if( b & 1 ){
            ans = ( ans * a ) % c;
        }
        b >>= 1;
        a = ( a * a ) % c;
    }

    return ans;
}

signed main(){
    opt;
    cin >> a >> b >> c;
    cout << p(a, b, c) << "\n";
}