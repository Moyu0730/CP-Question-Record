/* Question : TCIRC d017. AP325 Q-2-8 Modular Multiplicative Inverse */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define priq(type) priority_queue<type, vector<type>, greater<type>>
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
int n, p, a;

int ksm( int base, int power ){
    int res = 1;
    while( power > 0 ){
        if( power & 1 ){
            res = ( res * base ) % p;
        }

        base = ( base * base ) % p;
        power >>= 1;
    }

    return res;
}

signed main(){
    opt;
    cin >> n >> p;
    for( int i = 0 ; i < n ; i++ ){
        cin >> a;
        cout << ksm(a, p-2) << " ";
    }
}