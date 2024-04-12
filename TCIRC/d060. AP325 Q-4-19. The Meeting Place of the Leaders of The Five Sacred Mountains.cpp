/* Question : TCIRC d060. AP325 Q-4-19. The Meeting Place of the Leaders of The Five Sacred Mountains */

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
const int INF = 1e9;
int n, res, m, s, e;
vector<pii> t;

bool cmp( pii a, pii b ){
    if( a.F != b.F ) return a.F < b.F;
    else return a.S > b.S;
}

signed main(){
    opt;
    cin >> n;

    for( int i = 0 ; i < n ; i++ ){
        cin >> m >> s >> e;
        t.pb({s, m});
        t.pb({e, -1 * m});
    }

    sort( t.begin(), t.end(), cmp );

    int cnt, acc = 0;
    for( int i = 0 ; i < t.size() ; ){
        cnt = t[i].F;

        while( t[i].F == cnt ){
            acc += t[i].S;
            
            res = max(res, acc);
            i++;
        }
    }

    cout << res << "\n";
}