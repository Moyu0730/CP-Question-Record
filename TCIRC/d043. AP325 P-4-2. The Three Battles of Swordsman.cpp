/* Question : OJ Number */

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
const int MAXN = 1e5 + 50;
const int Mod = 1e9 + 7;
int n, res, op[MAXN], our[MAXN];

signed main(){
    opt;
    cin >> n;
    for( int i = 0 ; i < n ; i++ ) cin >> op[i];
    for( int i = 0 ; i < n ; i++ ) cin >> our[i];

    sort(op, op + n);
    sort(our, our + n);

    for( int i = 0, j = 0 ; j < n && i < n ; i++ ){
        if( our[i] > op[j] ){
            res++;
            j++;
        }
    }

    cout << res << "\n";
}