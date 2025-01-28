/* Question : AtCoder Beginner Contest 326 - C. Peak */

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
int n, m, tmp, res;
vector<int> v;

signed main(){
    opt;
    cin >> n >> m;

    for( int i = 0 ; i < n ; i++ ){
        cin >> tmp;
        v.pb(tmp);
    }

    sort(v.begin(), v.end());

    for( int i = 0 ; i < v.size() ; i++ ){
        int ind = upper_bound(v.begin(), v.end(), v[i]+m) - v.begin();
        int tmp = ind - i;
        if( v[i] + m == v[ind-1] ) tmp--;

        res = max(res,  tmp);
    }

    cout << res << "\n";
}