/* Question : TCIRC d029. AP325 Q-3-5. The Taller with A Bench Cooking Chicken Steaks（APCS201902） */

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
int n, h[MAXN], p, res;
set<pii> st;

signed main(){
    opt;
    cin >> n;

    st.insert({1e8, 0});
    for( int i = 1 ; i <= n ; i++ ) cin >> h[i];
    for( int i = 1 ; i <= n ; i++ ){
        cin >> p;

        auto val = st.upper_bound({h[i]+p, i});
        res += i - (*val).S - 1;

        while( st.begin()->F <= h[i] ) st.erase(st.begin());
        st.insert({h[i], i});
    }

    cout << res << "\n";
}