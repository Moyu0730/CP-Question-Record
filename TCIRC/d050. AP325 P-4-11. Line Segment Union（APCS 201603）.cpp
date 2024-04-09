/* Question : TCIRC d050. AP325 P-4-11. Line Segment Union（APCS 201603） */

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

const int MAXN = 1e4 + 50;
const int Mod = 1e9 + 7;
vector<pair<int, int>> v;
int n;

signed main(){
    opt;
    cin >> n;
    int x, y;
    for( int i = 0 ; i < n ; i++ ){
        cin >> x >> y;
        v.push_back({x, +1});
        v.push_back({y, -1});
    }
    sort(v.begin(), v.end());

    int count = 0, ind = 0, ans = 0;
    for( int i = 1 ; i <= 100000050 ; i++ ){
        while( v[ind].first == i ){
            count += v[ind].second;
            ind++;
        }
        if( count != 0 ) ans++;
    }
    cout << ans;
}