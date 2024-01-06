/* Question : TCIRC d028. AP325 P-3-4. The Closest Taller（APCS201902, Subtask） */

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
int n, res, cnt;
stack<pii> st;

signed main(){
    opt;
    cin >> n;
    st.push({1e8, 0});
    for( int i = 1 ; i <= n ; i++ ){
        cin >> cnt;
        
        pii last = st.top();
        while( last.F <= cnt ){
            st.pop();
            last = st.top();
        }
        
        res += i - st.top().S;
        st.push({cnt, i});
    }

    cout << res << "\n";
}