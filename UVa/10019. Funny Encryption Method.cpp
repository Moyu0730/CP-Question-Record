#include<bits/stdc++.h>
using namespace std;

#define pb(val) push_back(val)

int n, q, a, b;

signed main(){
    cin >> q;

    while( q-- ){
        cin >> n;

        a = b = 0;
        for( int i = 0 ; (1<<i) <= n ; ++i ){
            if( n & (1<<i) ) ++a;
        }

        int newN = 0, counter = 1;
        while( n > 0 ){
            newN += (n % 10) * counter;
            n /= 10;
            counter *= 16;
        }

        for( int i = 0 ; (1<<i) <= newN ; ++i ){
            if( newN & (1<<i) ) ++b;
        }

        cout << a << " " << b << "\n";
    }
}
