/* Question : AtCoder Beginner Contest 339 - A. TLD */

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
string str;
vector<char> v;

signed main(){
    opt;
    cin >> str;
    for( int i = str.size() - 1 ; i >= 0 ; i-- ){
        if( str[i] == '.' ) break;
        v.pb(str[i]);
    }

    for( int i = v.size() - 1 ; i >= 0 ; i-- ) cout << v[i];
    cout << "\n";
}