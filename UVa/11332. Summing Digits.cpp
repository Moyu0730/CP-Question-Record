#include<bits/stdc++.h>
using namespace std;

#define pb(val) push_back(val)

int n;

signed main(){
    while( cin >> n && n != 0 ){
        while( n >= 10 ){
            int newVal = 0;
            while( n > 0 ){
                newVal += n % 10;
                n /= 10;
            }

            n = newVal;
        }

        cout << n << "\n";
    }
}
