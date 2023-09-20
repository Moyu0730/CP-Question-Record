/* Question : CSES 1622. Creating Strings */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pirq(type) priority_queue<type, vector<type>, greater<type>>
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
vector<string> res;
string str;

signed main(){
    opt;
    cin >> str;

    sort(str.begin(), str.end());
    do{
        res.pb(str);
    }while( next_permutation(str.begin(), str.end()) );

    cout << res.size() << "\n";
    for( auto i : res ) cout << i << "\n";
}