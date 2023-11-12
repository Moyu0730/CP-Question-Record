/* Question : AtCoder Beginner Contest 328 - C. Consecutive */

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
int n, q, l, r, pre[MAXN];

signed main(){
    opt;
    cin >> n >> q >> str;

    for( int i = 1 ; i < str.size() ; i++ ){
        if( str[i-1] == str[i] ) pre[i] = pre[i-1] + 1;
        else pre[i] = pre[i-1];
    }
    
    while( q-- ){
        cin >> l >> r;
        cout << pre[r-1] - pre[l-1] << "\n";
    }
}