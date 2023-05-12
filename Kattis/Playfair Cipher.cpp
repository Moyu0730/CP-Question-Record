/* Question : OJ Number */

#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<math.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
string key, text, tmp;
char grid[30][30];
bool isUnique[30];

signed main(){
    // opt;
    int ch, n = 0;
    getline(cin, key);
    getline(cin, text);

    for( int i = 0 ; i < 30 ; i++ ) isUnique[i] = true;

    // Generate Grid
    int ind = 0, prev = 0, rem = 25, i = 0, j = 0;
    bool isEnd = false, flag = true;
    while( rem > 0 ){

        if( !isEnd ){
            if( key[ind] == ' ' ) ind++;
            char ch = key[ind];
            int asc = (int)ch-97;

            while( isUnique[asc] == false ){
                ind++;

                if( key[ind] == ' ' ) ind++;
                ch = key[ind];
                asc = (int)ch-97;

                if( ind == key.size()-1 ){
                    if( !isUnique[asc] ) flag = false;
                    isEnd = true;
                    break;
                }
                
                if( isUnique[asc]  ) break;
            }

            if( flag ){
                grid[i][j] = ch;
                isUnique[asc] = false;
                rem--;
                ind++;
            }else{
                rem++;
                i = j == 0 ? i-1 : i;
                j = j == 0 ? 4 : j-1;       
            }

            if( ind == key.size() - 1 ) isEnd = true;
        }else{
            for( int t = prev ; t < 26 ; t++ ){
                if( isUnique[t] == true ){
                    grid[i][j] = char(t+97);
                    isUnique[t] = false;
                    rem--;
                    prev = t;
                    break;
                }
            }
        }

        i = j == 4 ? i+1 : i;
        j = j == 4 ? 0 : j+1;        
    }
}