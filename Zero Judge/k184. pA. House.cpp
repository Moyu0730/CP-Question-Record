/* Question : ZeroJudge k184. pA. House */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
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
const int MAXN = 1e5 + 50;
const int Mod = 1e9 + 7;
const int INF = LLONG_MAX;
int n, m;
pii s[MAXN], h[MAXN];
vector<pair<int, pii>> v; // {Dis, {P, No}}

bool cmp( pair<int, pii> a, pair<int, pii> b ){
    if( a.F != b.F ) return a.F < b.F;
    else{
        if( a.S.F != b.S.F ) return a.S.F < b.S.F;
        else return a.S.S < b.S.S;
    }
}

int dis( pii a, pii b ){
    int dx = abs( a.F - b.F );
    int dy = abs( a.S - b.S );
    return dx * dx + dy * dy;
}

signed main(){
    opt;

    cin >> n >> m;
    v.resize(n);

    for( int i = 0; i < n ; i++ ){
        cin >> h[i].F >> h[i].S >> v[i].S.F;
        v[i].F = INF;
        v[i].S.S = i;
    }

    for( int i = 0 ; i < m ; i++ ) cin >> s[i].F >> s[i].S;

    for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j < m ; j++ ){
            int d = dis(h[i], s[j]);
            v[i].F = min(v[i].F, d);
        }
    }

    sort(v.begin(), v.end(), cmp);

    for( auto i : v ) cout << i.S.S + 1 << "\n";
}