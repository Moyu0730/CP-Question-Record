/* Question : d020. AP325 P-2-11. The Closest Interval Sum（*） */

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
const int MAXN = 1e6 + 50;
const int Mod = 1e9 + 7;
int n, k, cnt, res, pfs;
set<int> st;

signed main(){
    opt;
    cin >> n >> k;

    st.insert(0);
    for( int i = 1 ; i <= n ; i++ ){
        cin >> cnt;
        pfs += cnt;
        
        auto val = st.lower_bound(pfs - k);  
        if( val != st.end() ) res = max( res, pfs - *val );

        st.insert(pfs);
    }

    cout << res << "\n";
}