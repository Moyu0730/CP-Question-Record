/* Question : TCIRC d013. AP325 Q-2-4. Exponentiation by Squaring — Integers Less than 200 Digits */

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
int x, y, z;
string s;

int PreMod( string str, int Mod ){
    int res = 0;
    for( auto i : str ) res = ( ( res * 10 ) % Mod + ( i - '0' ) ) % Mod;

    return res;
}

int ksm( int base, int power, int Mod ){

    int res = 1;
    while( power > 0 ){
        if( power & 1 ){
            res = ( res * base ) % Mod;
        }

        base = ( base * base ) % Mod;
        power >>= 1;
    }

    return res;
}

signed main(){
    opt;
    cin >> s >> y >> z;
    
    x = PreMod(s, z);
    cout << ksm(x, y, z) << "\n";
}