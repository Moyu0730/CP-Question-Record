/* Question : TCIRC d038. AP325 Q-3-14 Linear Function（@@） */

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
const int MAXN = 5e4 + 50;
const int Mod = 1e9 + 7;
int n, m, a, b, res, lst;
double ist[MAXN];
vector<int> p;
vector<pii> l, st;

pdd getPoint( pii x, pii y ){
    pdd res;
	double a1 = x.F, b1 = x.S;
	double a2 = y.F, b2 = y.S;
	res.F = (b2 - b1) / (a1 - a2);
	res.S = (a2 * b1 - a1 * b2) / (a2 - a1);
	return res;
}

bool discardLine( int ind ){
    if( l[ind].F == st[lst-1].F ) return true;

    pdd p1 = getPoint(l[ind], st[lst-1]); // Cnt Line and Last Line intersect Point
    pdd p2 = getPoint(st[lst-1], st[lst-2]); // Line Last One and Second Last One Intersect Point

    if( p1.F > p2.F ) return false;
    else return true;
}

signed main(){
    opt;
    cin >> n >> m;

    p.resize(m);
    st.resize(n);
    for( int i = 0 ; i < n ; i++ ){
        cin >> a >> b;
        l.pb({a, b});
    }

    for( int i = 0 ; i < m ; i++ ) cin >> p[i];
    
    sort(l.begin(), l.end());
    sort(p.begin(), p.end());

    for( int i = 0 ; i < n ; i++ ){
        while( lst >= 2 && discardLine(i) ) lst--;
        st[lst++] = l[i];
    }

    lst--;
    for( int i = 0 ; i <= lst-1 ; i++ ){
        pdd tmp = getPoint(st[i], st[i+1]);
        ist[i] = tmp.F;
    }

    int idx = 0;
    for( int i = 0 ; i < m ; i++ ){
        while( idx < lst && p[i] > ist[idx] ) idx++;
        res += st[idx].F * p[i] + st[idx].S;
    }

    cout << res << "\n";
}