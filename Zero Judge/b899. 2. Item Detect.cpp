/* Question : ZeroJudge b899. 2. Item Detect */

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
#define int double

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
vector<pii> pt;
pii res, m;
double d;

pii mid( pii a, pii b ){
    return {a.f + (b.f - a.f) / 2, a.s + (b.s - a.s) / 2};
}

double dis( pii a, pii b ){
    return sqrt(abs(a.f - b.f) * abs(a.f - b.f) + abs(a.s -b.s) * abs(a.s -b.s));
}

signed main(){
    opt;
    pt.resize(3);
    for( int i = 0 ; i < 3 ; i++ ){
        cin >> pt[i].f >> pt[i].s;

        if( i == 1 ) d = dis(pt[0], pt[1]);
        else if( i == 2 ){
            if( dis(pt[1], pt[2]) > d ){
                m = mid(pt[2], pt[1]);
                res = {m.f + (m.f - pt[0].f), m.s + m.s - pt[0].s};
            }else if( dis(pt[1], pt[2]) == d ){
                m = mid(pt[0], pt[2]);
                res = {m.f + (m.f - pt[1].f), m.s + (m.s - pt[1].s)};
            }else{
                m = mid(pt[1], pt[0]);
                res = {m.f + (m.f - pt[2].f), m.s + (m.s - pt[2].s)};
            }
        }
    }

    cout << res.f << " " << res.s << "\n";
}