/* Question : TOJ 630. EatAllLeftMost */

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

#define nL cnt * 2
#define nR cnt * 2 + 1

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 5e5 + 50;
const int Mod = 1e9 + 7;
int n, k, ans, val, pre[MAXN];
set<int> st;

signed main(){
    opt;
    cin >> n >> k;
    st.insert(-1);
    for( int i = 1 ; i <= n ; i++ ){
        cin >> val;
        pre[i] = ( pre[i-1] + val ) % k;

        st.insert(pre[i]);
        auto it = st.upper_bound(pre[i]);

        if( it != st.end() ) ans = max( ans, pre[i] - *it + k );
        
        ans = max(ans, pre[i]);
    }

    cout << ans << "\n";
}