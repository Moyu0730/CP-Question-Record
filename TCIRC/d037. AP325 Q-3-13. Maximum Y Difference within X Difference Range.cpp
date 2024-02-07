/* Question : TCIRC d037. AP325 Maximum Y Difference within X Difference Range */

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
int n, l, res;
vector<pii> v;
queue<int> q;
multiset<int> st;

signed main(){
    opt;
    cin >> n >> l;

    v.resize(n);
    for( int i = 0 ; i < n ; i++ ) cin >> v[i].F;
    for( int i = 0 ; i < n ; i++ ) cin >> v[i].S;
    
    sort(v.begin(), v.end());

    q.push(0);
    st.insert(v[0].S);

    for( int i = 1 ; i < n ; i++ ){
        q.push(i);
        st.insert(v[i].S);

        while( v[i].F > v[q.front()].F + l ){
            st.erase(v[q.front()].S);
            q.pop();
        }

        res = max(res, abs(*st.begin() - *st.rbegin()));
    }

    cout << res << "\n";
}