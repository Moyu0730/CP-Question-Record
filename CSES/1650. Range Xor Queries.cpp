/* Question : CSES 1650. Range Xor Queries */

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

#define nL cnt * 2
#define nR cnt * 2 + 1

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;

int n, q, x, y, arr[MAXN], pfx[MAXN];

signed main(){
    opt;
    cin >> n >> q;
    for( int i = 1 ; i <= n ; i++ ){
        cin >> arr[i];
        pfx[i] = pfx[i-1] ^ arr[i];
    }
 
    while( q-- ){
        cin >> x >> y;
        cout << (pfx[y] ^ pfx[x-1]) << "\n";
    }
}