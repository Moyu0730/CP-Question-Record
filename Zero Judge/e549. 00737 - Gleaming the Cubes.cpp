/* Question : ZJ e549. 00737 - Gleaming the Cubes */

#include<bits/stdc++.h>
using namespace std;

/* Pragma */
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

/* Self Define */
#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pirq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define vsort(x) sort(x.begin(), x.end());
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define F first
#define S second
#define X first
#define Y second
#define int long long
#define ll long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e7 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;
const int MEMINF = 0x3F;
const int MEMINF_VAL = 0x3F3F3F3F;
const int MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int n, a, b, c, r;
vector<vector<pii>> cube;
pii x, y, z;

pii update( pii a, pii b ){
    if( a.F > b.F ) swap(a, b);
    if( a.F == MAXN && a.S == MAXN ) return {MAXN, MAXN};

    if( a.S < b.F ) return {MAXN, MAXN};
    return {b.F, min(a.S, b.S)};
}

signed main(){
    opt;

    while( cin >> n && n != 0 ){
        cube.clear();

        for( int i = 0 ; i < n ; ++i ){
            cin >> a >> b >> c >> r;

            auto tmp = vector<pii> { {a, a + r}, {b, b + r}, {c, c + r} };

            cube.pb(tmp);
        }

        x = cube[0][0];
        y = cube[0][1];
        z = cube[0][2];

        for( int i = 1 ; i < cube.size() ; ++i ){
            x = update(x, cube[i][0]);
            y = update(y, cube[i][1]);
            z = update(z, cube[i][2]);
        }

        cout << (x.S - x.F) * (y.S - y.F) * (z.S - z.F) << "\n";
    }
}