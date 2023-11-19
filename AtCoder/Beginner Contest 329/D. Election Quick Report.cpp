/* Question : AtCoder Beginner Contest 329 - D. Election Quick Report */

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
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
int n, m, q, can[MAXN];
set<pii> st;

signed main(){
    opt;
    cin >> n >> m;

    for( int i = 0 ; i < m ; i++ ){
        cin >> q;
        
        can[q]++;
        st.insert({can[q], -q});

        cout << -1 * (*st.rbegin()).S << "\n";
    }
}