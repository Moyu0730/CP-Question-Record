/* Question : AtCoder Beginner Contest 352 - D. Permutation Subsequence */

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
const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
const int INF = 1e9;

int n, k, res = INF;
vector<pii> v;
set<int> st;

signed main(){
    opt;

    cin >> n >> k;
    v.resize(n);
    for( int i = 0 ; i < n ; i++ ){
        cin >> v[i].F;
        v[i].S = i;
    }

    sort(v.begin(), v.end());

    for( int i = 0 ; i < n ; i++ ){
        st.insert(v[i].S);

        if( st.size() == k ){
            res = min(res, *st.rbegin() - *st.begin());
            st.erase(v[i-k+1].S);
        }
    }

    cout << res << "\n";
}