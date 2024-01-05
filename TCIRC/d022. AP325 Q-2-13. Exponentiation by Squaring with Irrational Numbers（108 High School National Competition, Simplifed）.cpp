/* Question : TCIRC d022. AP325 Q-2-13. Exponentiation by Squaring with Irrational Numbers（108 High School National Competition, Simplifed） */

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
const int Mod = 1e9 + 9;
int x, y, n, s, t;

pii mutiple( pii a, pii b ){
    pii res;

    res.F = ( ( a.F * b.F ) % Mod + ( a.S * b.S * 2 ) % Mod ) % Mod;
    res.S = ( ( a.F * b.S ) % Mod + ( a.S * b.F ) % Mod ) % Mod;

    return res;
}

void ksm( pii base, int power ){

    pii res = {1, 0};
    while( power > 0 ){
        if( power & 1 ){
            res = mutiple(res, base);
        }

        power >>= 1;
        base = mutiple(base, base);
    }

    cout << res.F << " " << res.S << "\n";

    return;
}

signed main(){
    opt;
    cin >> x >> y >> n;
    ksm({x, y}, n);
}