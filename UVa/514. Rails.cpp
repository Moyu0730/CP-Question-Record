#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 50;

int n, arr[MAXN];
stack<int> st;

int main(){
    while( cin >> n && n != 0 ){
        while( cin >> arr[0] && arr[0] != 0 ){
            // Init
            while( !st.empty() ) st.pop();

            for( int i = 1 ; i < n ; ++i ) cin >> arr[i];

            int counter = 0;
            for( int i = 1 ; i <= n ; ++i ){
                st.push(i);

                while( !st.empty() && st.top() == arr[counter] ){
                    ++counter;
                    st.pop();
                }
            }

            if( st.size() > 0 ) cout << "No\n";
            else cout << "Yes\n";
        }

        cout << "\n";
    }
}
