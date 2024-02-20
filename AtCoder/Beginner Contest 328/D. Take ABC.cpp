/* Question : AtCoder Beginner Contest 328 - D. Take ABC */

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
const int MAXN = 3 + 50;
const int Mod = 1e9 + 7;
string s, res;
char tmp;
stack<char> st;

signed main(){
    opt;
    cin >> s;

    for( int i = 0 ; i < s.size() ; i++ ){
        if( st.empty() ){
            st.push(s[i]);
            continue;
        }


        if( s[i] == 'C' ){
            tmp = st.top();
            st.pop();
            
            if( st.size() != 0 && st.top() == 'A' && tmp == 'B' ){
                st.pop();
                continue;
            }else{
                st.push(tmp);
            }
        }

        st.push(s[i]);
    }

    while( !st.empty() ){
        res.pb(st.top());
        st.pop();
    }
    
    reverse(res.begin(), res.end());
    
    cout << res << "\n";
}