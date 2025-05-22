#include<bits/stdc++.h>
using namespace std;

stack<string> st;
string op, str;
int q;

int main(){
    cin >> q;

    while( q-- ){
        cin >> op;

        if( op == "Sleep" ){
            cin >> str;
            st.push(str);
        }else if( op == "Test" ){
            if( st.empty() ) cout << "Not in a dream\n";
            else cout << st.top() << "\n";
        }else{
            if( !st.empty() ) st.pop();
        }
    }
}
