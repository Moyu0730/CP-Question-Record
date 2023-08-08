/* Question : Luogu P1313. [ NOIP2011 Improvement Group ] Calculation Coefficient */

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

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e4 + 50;
const int Mod = 1e4 + 7;
int a, b, k, n, m, xk, xnk, ckn, bn, am, mod[MAXN];

int ksm( int base, int power ){
    int ans = 1;
    while( power > 0 ){
        if( power & 1 ){
            ans = ( ans * base ) % Mod;
        }
        power >>= 1;
        base = ( base * base ) % Mod;
    }

    return ans;
}

tuple<int, int, int> exgcd( int a, int b ){
    if( !b )
        return make_tuple(1, 0, a);
    
    auto t = exgcd(b, a%b);
    int xx = get<0>(t), yy = get<1>(t), g = get<2>(t);

    return make_tuple(yy, xx - a / b * yy, g);
}

signed main(){
    opt;
    cin >> a >> b >> k >> n >> m;

    mod[0] = 1;
    for( int i = 1 ; i < Mod ; i++ ) mod[i] = ( i * mod[i-1] ) % Mod;

    xk = ( get<0>(exgcd( mod[n], Mod )) % Mod + Mod ) % Mod;
    xnk = ( get<0>(exgcd( mod[k-n], Mod )) % Mod + Mod ) % Mod;
    ckn = ( ( mod[k] * xk ) % Mod * xnk ) % Mod;
    bn = ksm( b, m );
    am = ksm( a, n );
    
    cout << ( ( ckn * bn ) % Mod * am ) % Mod << "\n";
}