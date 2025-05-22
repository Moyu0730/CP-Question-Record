#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e7 + 50;

int t, n, x, res, it, arr[MAXN];
set<int> st;

signed main(){
    cin >> t;

    while( t-- ){
        cin >> n;

        st.clear();
        res = 0;
        it = 0;
        for( int i = 0 ; i < n ; ++i ){
            cin >> arr[i];

            if( st.count(arr[i]) != 0 ){
                while( st.count(arr[i]) ){
                    st.erase(arr[it]);
                    ++it;
                }
            }

            st.insert(arr[i]);

            res = max(res, (int)st.size());
        }

        cout << res << "\n";
    }
}
