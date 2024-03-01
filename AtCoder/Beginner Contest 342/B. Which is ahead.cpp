/* Question : AtCoder Beginner Contest 342 - B. Which is ahead */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define F first
#define S second
#define X first
#define Y second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e3 + 50;
const int Mod = 1e9 + 7;
const int INF = 1e9;
int n, q, a, b, pa, pb, arr[MAXN];

signed main(){
    opt;

    cin >> n;
    for( int i = 0 ; i < n ; i++ ) cin >> arr[i];

    cin >> q;
    while( q-- ){
        cin >> a >> b;

        for( int i = 0 ; i < n ; i++ ){
            if( arr[i] == a ) pa = i;
            if( arr[i] == b ) pb = i;
        }
        
        if( pa > pb ) cout << b << "\n";
        else cout << a << "\n";
    }
}