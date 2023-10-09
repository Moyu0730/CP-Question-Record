/* Question : CSES 2189. Point Location Test */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define priq(type) priority_queue<type, vector<type>, greater<type>>
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
int t, d;
pii a, b, c, vl, vp;

int cross( pii a, pii b ){
    return (a.f * b.s) - (b.f * a.s);
}

signed main(){
    opt;
    cin >> t;
    while( t-- ){
        cin >> a.f >> a.s >> b.f >> b.s >> c.f >> c.s;

        vl = {(b.f - a.f), (b.s - a.s)};
        vp = {(c.f - b.f), (c.s - b.s)};

        d = cross(vp, vl);

        if( d > 0 ) cout << "RIGHT\n";
        else if( d < 0 ) cout << "LEFT\n";
        else cout << "TOUCH\n";        
    }
}