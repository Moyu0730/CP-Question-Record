#include<bits/stdc++.h>
using namespace std;

int q;
string str;
stack<char> st;

int main(){
    cin >> q;
    cin.ignore();

    while( q-- ){
        getline(cin, str);

        // Init
        while( !st.empty() ) st.pop();

        bool flag = true;
        for( int i = 0 ; i < str.size() ; ++i ){
            if( str[i] == '(' || str[i] == '[' || str[i] == '{' ) st.push(str[i]);

            if( str[i] == ')' ){
                if( !st.empty() && st.top() == '(' ) st.pop();
                else{
                    flag = false;
                    break;
                }
            }else if( str[i] == ']' ){
                if( !st.empty() && st.top() == '[' ) st.pop();
                else{
                    flag = false;
                    break;
                }
            }else if( str[i] == '}' ){
                if( !st.empty() && st.top() == '{' ) st.pop();
                else{
                    flag = false;
                    break;
                }
            }
        }

        if( flag && st.size() == 0 ) cout << "Yes\n";
        else if( flag == false || st.size() > 0 ) cout << "No\n";
    }
}
