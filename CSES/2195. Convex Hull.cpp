/* Question : CSES 2195. Convex Hull */

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
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
int n, m;
vector<pii> pt, res;

double cross( pii o, pii a, pii b ){
	return (a.f - o.f) * (b.s - o.s) - (a.s - o.s) * (b.f - o.f);
}

bool cmp( pii a, pii b ){
    return a.f < b.f || ( a.f == b.f && a.s < b.s );
}

signed main(){
    opt;
    cin >> n;
    pt.resize(n);
    res.resize(n);
    for( int i = 0 ; i < n ; i++ ) cin >> pt[i].f >> pt[i].s;

    sort(pt.begin(), pt.end(), cmp);
    m = 0;

    // Upper
    for( int i = 0 ; i < n ; i++ ){
        while( m >= 2 && cross(res[m-2], res[m-1], pt[i]) < 0 ) m--;

        res[m++] = pt[i];
    }

    // Lower
    for( int i = n-2, t = m+1; i >= 0 ; i-- ){
        while( m >= t && cross(res[m-2], res[m-1], pt[i]) < 0 ) m--;
        
        res[m++] = pt[i];
    }

    m--;
    cout << m << "\n";
    for( int i = 0 ; i < m ; i++ ) cout << res[i].f << " " << res[i].s << "\n";
}