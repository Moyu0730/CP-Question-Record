/* Question : Luogu P1901. Transmitting Station */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define priq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define f first
#define s second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e6 + 50;
const int Mod = 1e9 + 7;
int n, height[MAXN], val[MAXN], res[MAXN], ma;
stack<int> st;

signed main(){
    opt;
    cin >> n;
    for( int i = 0 ; i < n ; i++ ) cin >> height[i] >> val[i];

    st.push(0);
    for( int i = 1 ; i < n ; i++ ){
        while( !st.empty() && height[i] >= height[st.top()] ){
            res[i] += val[st.top()];
            st.pop();
        }

        if( !st.empty() ) res[st.top()] += val[i];

        st.push(i);
    }

    ma = -1;
    for( int i = 0 ; i < n ; i++ ) ma = max( ma, res[i] );

    cout << ma << "\n";
}