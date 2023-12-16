/* Question : TCIRC d012. Exponentiation by Squaring */

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
int x, y, p;

int ksm( int base, int power, int Mod ){
    int res = 1;
    while( power > 0 ){
        if( power & 1 ){
            res = ( res * base ) % Mod;
        }

        power >>= 1;
        base = ( base * base ) % Mod;
    }

    return res;
}

signed main(){
    opt;
    cin >> x >> y >> p;
    cout << ksm(x, y, p) << "\n";
}