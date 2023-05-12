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
string key, text;
vector<char> res;
char grid[30][30];
bool isUnique[30];
vector<pair<int, int>> pos;

struct node {
    int i;
    int j;
    int ind;
    char ch;
};

signed main(){
    // opt;
    int ch, n = 0;
    getline(cin, key);
    getline(cin, text);

    for( int i = 0 ; i < 30 ; i++ ) isUnique[i] = true;
    isUnique[16] = false;
    pos.resize(30);

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
                grid[i][j] = char((int)ch-32);
                isUnique[asc] = false;
                pos[asc].first = i;
                pos[asc].second = j;
                rem--;
                ind++;
            }else{
                rem++;
                i = j == 0 ? i-1 : i;
                j = j == 0 ? 4 : j-1;       
            }

            if( ind == key.size() - 1 ) isEnd = true;
        }else{
            for( int t = prev ; t <= 26 ; t++ ){
                if( isUnique[t] == true ){
                    grid[i][j] = char(t+97-32);
                    isUnique[t] = false;
                    pos[t].first = i;
                    pos[t].second = j;
                    rem--;
                    prev = t;
                    break;
                }
            }
        }

        i = j == 4 ? i+1 : i;
        j = j == 4 ? 0 : j+1;        
    }

    for( int i = 0 ; i < text.size() ; i++ ) if( text[i] != ' ' ) res.emplace_back(text[i]);

    node f, s;
    int index = 0;
    while( index != res.size() ){
        // Classification First Char and Second Char in Digraphs
        f.ch = res[index]; f.ind = index;
        if( index < res.size() ){
            index++;
            s.ch = res[index]; s.ind = index;
        }else{
            s.ch == ' ';
        }
        
        if( f.ch == s.ch ){
            res.insert(res.begin()+index, 'x');
            s.ch = res[index]; 
            s.ind = index;
        }
        
        if( index >= res.size()-1 && res.size() % 2 ){
            s.ch = 'x';
            res.emplace_back(s.ch);
            s.ind = res.size()-1;
        }

        f.i = pos[(int)f.ch-97].first; 
        f.j = pos[(int)f.ch-97].second;

        s.i = pos[(int)s.ch-97].first; 
        s.j = pos[(int)s.ch-97].second;

        if( f.i == s.i ){
            f.j = f.j == 4 ? 0 : f.j + 1;
            res[f.ind] = grid[f.i][f.j];
            s.j = s.j == 4 ? 0 : s.j + 1;
            res[s.ind] = grid[s.i][s.j];
        }else if( f.j == s.j ){
            f.i = f.i == 4 ? 0 : f.i + 1;
            res[f.ind] = grid[f.i][f.j];
            s.i = s.i == 4 ? 0 : s.i + 1;
            res[s.ind] = grid[s.i][s.j];
        }else{
            res[f.ind] = grid[f.i][s.j];
            res[s.ind] = grid[s.i][f.j];
        }
        
        index++;
    }

    cout << "\n";
    for( auto i : res ) cout << i;
}