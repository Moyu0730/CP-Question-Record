#include<bits/stdc++.h>
using namespace std;

#define int long long
#define F first
#define S second

string str;
int len;
map<string, int> mp;

signed main(){
    while( cin >> len >> str ){
        mp.clear();

        for( int i = 0 ; i + len < str.size() ; ++i ){
            mp[str.substr(i, len)]++;
        }

        int times = -1;
        string res;
        for( auto i : mp ){
            if( times == -1 ){
                times = i.S;
                res = i.F;
            }else{
                if( i.S > times ){
                    times = i.S;
                    res = i.F;
                }
            }
        }

        cout << res << "\n";
    }
}
