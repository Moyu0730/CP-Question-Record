/* Question : CSES 1163. Traffic Lights */

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
int x, n, q;
set<int> st;
multiset<int> res;

signed main(){
    opt;
    cin >> x >> n;

    st.insert(0);
    st.insert(x);
    res.insert(x);
    
    while( n-- ){
        cin >> q;

        int r = *st.upper_bound(q), l = *prev(st.upper_bound(q));
        int length = r - l;

        res.erase(res.find(length));
        res.insert(r-q);
        res.insert(q-l);

        st.insert(q);

        cout << *prev(res.end()) << "\n";
    }
}