/* Question : Kattis Tajna */

#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<math.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int MAXN = 100 + 5; // For the Larger Prime Number, This Must Be Bigger then 97 ( Largest Prime Number Lower then 100 )
const int Mod = 1e9 + 7;
string s;
string arr[MAXN][MAXN];

signed main(){
    opt;
    cin >> s;

    int len = s.size(), row = 0, col;
    for( int i = 1 ; i <= sqrt(len) ; i++ ){
        if( len % i == 0 ) row = max(row, i);
    }
    col = len / row;

    int ind = 0;
    for( int i = 0 ; i < col ; i++ ){
        for( int j = 0 ; j < row ; j++ ){
            arr[j][i] = s[ind];
            ind++;
        }
    }

    for( int i = 0 ; i < row ; i++ ){
        for( int j = 0 ; j < col ; j++ ){
            cout << arr[i][j];
        }
    }
}