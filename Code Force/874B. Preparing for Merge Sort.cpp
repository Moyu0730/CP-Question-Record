/* Question : CF 874B. Preparing for Merge Sort */

#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<math.h>
#include<algorithm>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long

const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
vector< vector<int> > vec;
int n, num, ind, ctn, len;

int bs( int ctn ){
    int res = len-1, step = len-1;

    if( vec[res].back() > ctn ) return res + 1;

    while( step > 0 ){
        if( step == 0 ) break;
        if( res - step < 0 ){
            step /= 2; 
            continue;
        } 

        if( vec[res-step].back() < ctn ) res -= step;
        else step /= 2;
    }
    
    return res;
}

signed main(){
    // opt;
    cin >> n;
    vec.resize(n+5);
    while( n-- ){
        cin >> num;
        if( vec[0].empty() ){
            vec[0].emplace_back(num);
            len++;
        }else{
            ind = bs(num);
            vec[ind].emplace_back(num);

            len = ind == len ? len+1 : len;
        }
    }

    for( int i = 0 ; i < len ; i++ ){
        for( int j = 0 ; j < vec[i].size() ; j++ ) cout << vec[i][j] << " ";
        cout << "\n";
    }
}