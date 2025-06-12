#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb(x) push_back(x)
#define all(v) v.begin(), v.end()

int ptr;
string str;
bool flag = false;
list<char> res;

signed main(){
    while( cin >> str ){
        res.clear();

        auto it = res.begin();
        for( int i = 0 ; i < str.size() ; ++i ){
            if( str[i] == '[' ) it = res.begin();
            else if( str[i] == ']' ) it = res.end();
            else it = next(res.insert(it, str[i]));
        }

        for( auto it = res.begin() ; it != res.end() ; ++it ) cout << *it;
        cout << "\n";
    }
}
