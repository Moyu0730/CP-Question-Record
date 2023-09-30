/* Question : CSES 1623. Apple Division */

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
const int MAXN = 20 + 50;
const int Mod = 1e9 + 7;
int n, res, sum, half;
bool used[MAXN], flag;
vector<int> v;

signed main(){
    opt;
    cin >> n;
    v.resize(n);
    for( int i = 0 ; i < n ; i++ ){
        cin >> v[i];
        sum += v[i];
    }

    res = 1e18;
    for( int i = 0 ; i < (1<<n) ; i++ ){
        int tmp = 0;
        for( int j = 0 ; j < n ; j++ ){
            if( i & (1<<j) ) tmp += v[j];
            // cout << i << " | " << res << " " << tmp << "\n";
            res = min( res, abs( (sum - tmp) - tmp ) );
        }
    }

    cout << res << "\n";
}