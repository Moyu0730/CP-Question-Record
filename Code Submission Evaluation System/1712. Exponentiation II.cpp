/* Question : CSES 1712. Exponentiation II */

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
int n, a, b, c;

int ksm( int base, int power, int M ){
    int ans = 1;
    while( power > 0 ){
        if( power & 1 ) ans = ( ans * base ) % M;
        power >>= 1;
        base = ( base * base ) % M;
    }

    return ans;
}

signed main(){
    opt;
    cin >> n;
    while( n-- ){
        cin >> a >> b >> c;
        int p = ksm(b, c, Mod-1);
        cout << ksm(a, p, Mod) << "\n";
    }
}