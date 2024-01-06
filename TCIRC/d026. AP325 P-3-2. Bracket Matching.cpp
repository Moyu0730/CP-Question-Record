/* Question : TCIRC d026. AP325 P-3-2. Bracket Matching */

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
string str;

signed main(){
    // opt;
    while( cin >> str ){
        stack<char> st;

        bool flag = true;
        for( int i = 0 ; i < str.size() ; i++ ){
            if( str[i] == '(' || str[i] == '[' || str[i] == '{' ) st.push(str[i]);

            if( str[i] == ')' ){
                if( st.top() == '(' ) st.pop();
                else{
                    flag = false;
                    break;
                }
            }else if( str[i] == ']' ){
                if( st.top() == '[' ) st.pop();
                else{
                    flag = false;
                    break;
                }
            }else if( str[i] == '}' ){
                if( st.top() == '{' ) st.pop();
                else{
                    flag = false;
                    break;
                }
            }
        }

        if( flag && st.size() == 0 ) cout << "yes\n";
        else cout << "no\n";
    }
}