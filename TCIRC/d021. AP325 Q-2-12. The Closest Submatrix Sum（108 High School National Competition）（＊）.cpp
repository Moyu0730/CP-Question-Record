/* Question : TCIRC d021. AP325 Q-2-12. The Closest Submatrix Sum（108 High School National Competition）（＊） */

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
const int MAXN = 3e5 + 50;
const int Mod = 1e9 + 7;
int q, n, m, tmp, res, cnt[MAXN];
set<int> st;
vector<vector<int>> arr;

signed main(){
    opt;
    cin >> q >> m >> n;
    arr.resize(m+5);
    for( int i = 1 ; i <= m ; i++ ){
        arr[i].resize(n+5);
        for( int j = 1 ; j <= n ; j++ ){
            cin >> tmp;
            arr[i][j] = tmp;
        }
    }

    for( int i = 1 ; i <= m ; i++ ){
        for( int j = i ; j <= m ; j++ ){
            int sum = 0;
            st.clear();
            st.insert(0);

            for( int k = 1 ; k <= n ; k++ ){
                cnt[k] = i == j ? arr[j][k] : cnt[k] + arr[j][k];
                sum += cnt[k];

                auto val = st.lower_bound(sum - q);
                if( val != st.end() ) res = max(res, sum - *val);
                
                st.insert(sum);
            }
        }
    }

    cout << res << "\n";
}