/* Question : AtCoder Beginner Contest 351 - C. Merge the balls */

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

int n, a;
stack<int> st;

signed main(){
    opt;

    cin >> n;
    
    for( int i = 0 ; i < n ; i++ ){
        cin >> a;

        if( st.empty() ){
            st.push(a);
            continue;
        }

        if( st.size() == 1 ){
            if( st.top() == a ){
                st.pop();
                st.push(a+1);
            }else st.push(a);

            continue;
        }

        st.push(a);
        while( st.size() >= 2 ){
            int f = st.top();
            st.pop();
            int s = st.top();

            if( f == s ){
                st.pop();
                st.push(f+1);
            }else{
                st.push(f);
                break;
            }
        }
    }

    cout << st.size() << "\n";
}