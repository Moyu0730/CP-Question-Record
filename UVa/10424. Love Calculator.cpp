#include<bits/stdc++.h>
using namespace std;

#define pb(val) push_back(val)

string a, b;
int va, vb;

signed main(){
    while( getline(cin, a) ){
        getline(cin, b);

        va = vb = 0;
        for( auto i : a ){
            if( isalpha(i) ){
                i = tolower(i);
                va += i - 'a' + 1;
            }
        }

        for( auto i : b ){
            if( isalpha(i) ){
                i = tolower(i);
                vb += i - 'a' + 1;
            }
        }

        while( va >= 10 ){
            int newVal = 0;
            while( va > 0 ){
                newVal += va % 10;
                va /= 10;
            }

            va = newVal;
        }

        while( vb >= 10 ){
            int newVal = 0;
            while( vb > 0 ){
                newVal += vb % 10;
                vb /= 10;
            }

            vb = newVal;
        }

        if( va > vb ) cout << fixed << setprecision(2) << ((double)vb / (double)va) * 100 << " %\n";
        else cout << fixed << setprecision(2) << ((double)va / (double)vb) * 100 << " %\n";
    }
}
