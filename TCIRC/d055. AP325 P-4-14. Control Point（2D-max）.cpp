/* Question : TCIRC d055. AP325 P-4-14. Control Point（2D-max） */

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
const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
const int INF = 1e9;
int n, res, border, lst;
vector<pii> v;

bool cmp( pii a, pii b ){
    if( a.S != b.S ) return a.S > b.S;
    else return a.F > b.F;
}

signed main(){
    opt;
    cin >> n;

    v.resize(n);
    for( int i = 0 ; i < n ; i++ ) cin >> v[i].F;
    for( int i = 0 ; i < n ; i++ ) cin >> v[i].S;

    sort(v.begin(), v.end(), cmp);

    for( int i = 0 ; i < n ; i++ ){
        if( i == 0 ){
            res++;
            border = v[i].F;
            lst = v[i].S;
            continue;
        }

        if( v[i].S == lst ) continue;
        else{
            lst = v[i].S;
            if( v[i].F > border ){
                res++;
                border = v[i].F;
            }
        }
    }

    cout << res << "\n";
}