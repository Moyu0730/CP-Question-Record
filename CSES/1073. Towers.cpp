/* Question : CSES 1073. Towers */

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
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
const int INF = 1e9;
int n, t[MAXN];
multiset<int> st;

signed main(){
    opt;
    cin >> n;

    for( int i = 0 ; i < n ; i++ )  cin >> t[i];
    for( int i = 0 ; i < n ; i++ ){
        if( !st.empty() && t[i] < *st.rbegin() ){
            auto it = st.upper_bound(t[i]);
            if( t[i] != *it ) st.erase(it);
        }
        
        st.insert(t[i]);
    }

    cout << st.size() << "\n";
}