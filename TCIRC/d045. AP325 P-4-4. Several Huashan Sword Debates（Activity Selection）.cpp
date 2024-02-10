/* Question : TCIRC d045. AP325 P-4-4. Several Huashan Sword Debates（Activity Selection） */

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
const int Mod = 1e9 + 7;
int n, s, t, lst, res;
vector<pii> v;

bool cmp( pii a, pii b ){
    if( a.S == b.S ) return a.F < b.F;
    else return a.S < b.S;
}

signed main(){
    opt;
    cin >> n;

    for( int i = 0 ; i < n ; i++ ){
        cin >> s >> t;
        v.pb({s, t});
    }
    
    sort(v.begin(), v.end(), cmp);


    for( int i = 0 ; i < n ; ){
        res++;
        lst = v[i].S;
        
        while( v[i].F <= lst && i < n ) i++;
    }
    cout << res << "\n";
}