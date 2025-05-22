#include<bits/stdc++.h>
using namespace std;

#define int long long
#define F first
#define S second

string a, b, ask;
map<string, string> mp;

signed main(){
    while( getline(cin, a) && a != "" ){
        for( int i = 0 ; i < a.size() ; ++i ){
            if( a[i] == ' ' ){
                mp[a.substr(i+1, a.size() - i)] = a.substr(0, i);
                break;
            }
        }
    }

    while( cin >> ask ){
        if( mp.find(ask) != mp.end() ) cout << mp[ask] << "\n";
        else cout << "eh\n";
    }
}
