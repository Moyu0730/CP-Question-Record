#include<bits/stdc++.h>
using namespace std;

#define int long long
#define F first
#define S second

double t, total;
string str;
map<string, double> mp;

signed main(){
    cin >> t;
    getline(cin, str);
    getline(cin, str);

    while( t-- ){
        mp.clear();
        total = 0;

        while( getline(cin, str) && str != "" ){
            mp[str]++;
            ++total;
        }

        for( auto i : mp ){
            cout << i.F << " " << fixed << setprecision(4) << (double)(i.S / total) * 100 << "\n";
        }

        if( t - 1 >= 0 ){
            cout << "\n";
        }
    }
}
