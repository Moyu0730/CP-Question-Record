/* Question : AtCoder Beginner Contest 340 - B. Append */

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
int q, tp, val;
vector<int> v;

signed main(){
    opt;
    cin >> q;

    while( q-- ){
        cin >> tp >> val;

        if( tp == 1 ) v.pb(val);
        else if( tp == 2 ){
            cout << v[v.size()-val] << "\n";
        }
    }
}