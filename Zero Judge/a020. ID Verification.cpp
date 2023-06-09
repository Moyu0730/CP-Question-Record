/* Question : ZeroJudge a020. ID Verification */

#include<bits/stdc++.h>
using namespace std;

string str;
int ch[30] = { 10, 11, 12, 13, 14, 15, 16, 17, 34, 18, 19, 20, 21, 22, 35, 23, 24, 25, 26, 27, 28, 29, 32, 31, 31, 33 };

int main(){
    cin >> str;

    int res = 0, dif = 10;
    for( int i = 0 ; i <= str.size() ; i++ ){
        if( i == 0 ) res += ch[( (int)str[0] - 65 )] / 10;
        else if( i == 1 ){
            res += ( ch[( (int)str[0] - 65 )] % 10 ) * dif;
        }else{
            if( dif == 0 ) dif = 1;

            res += ( (int)str[i-1] - 48 ) * dif;
        }
        dif--;
    }

    if( res % 10 == 0 ) cout << "real\n";
    else cout << "fake\n";
}