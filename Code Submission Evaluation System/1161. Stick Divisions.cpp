/* Question : CSES 1161. Stick Divisions */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define f first
#define s second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
int x, n, res, tmp, a, b;
multiset<int> stick;

signed main(){
    opt;
    cin >> x >> n;
    for( int i = 0 ; i < n ; i++ ){
        cin >> tmp;
        stick.insert(tmp);
    }

    res = 0;
    while( stick.size() > 1 ){
        a = *stick.begin();
        stick.erase(stick.begin());
        b = *stick.begin();
        stick.erase(stick.begin());

        res += (a+b);
        stick.insert(a+b);
    }

    cout << res << "\n";
}