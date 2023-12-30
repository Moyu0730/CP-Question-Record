/* Question : TCIRC d016. AP325 Q-2-7. Complementary Teams（APCS201906） */

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
int n, m;
set<int> st;
string str;

signed main(){
    opt;
    cin >> m >> n;

    for( int i = 0 ; i < n ; i++ ){
        cin >> str;

        int tmp = 0;
        for( int i = 0 ; i < str.size() ; i++ ) tmp |= (1<<(str[i]-'A'));
        
        st.insert(tmp);
    }

    int res = 0, t = (1<<m) - 1;
    for( auto it = st.begin() ; it != st.end() ; it++ ){
        int tar = t - (*it);

        if( st.find(tar) != st.end() ) res++;
    }

    cout << res / 2 << "\n";
}