/* Question : AtCoder Beginner Contest 343 - C. A+B+C */

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
const int MAXN = 3e8 + 50;
const int Mod = 1e9 + 7;
const int INF = 1e9;
int n;
vector<int> a, b, c, x;
set<int> st;
bool valid[MAXN];

signed main(){
    opt;

    cin >> n;
    a.resize(n);
    for( int i = 0 ; i < n ; i++ ) cin >> a[i];

    cin >> n;
    b.resize(n);
    for( int i = 0 ; i < n ; i++ ) cin >> b[i];

    cin >> n;
    c.resize(n);
    for( int i = 0 ; i < n ; i++ ) cin >> c[i];

    cin >> n;
    x.resize(n);
    for( int i = 0 ; i < n ; i++ ) cin >> x[i];

    for( auto i : a ){
        for( auto j : b ){
            for( auto k : c ) valid[i+j+k] = true;
        }
    }

    for( auto i : x ){
        if( valid[i] ) cout << "Yes\n";
        else cout << "No\n";
    }
}