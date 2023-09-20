/* Question : CSES 1620. Factory Machines */

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

const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
int n, t, res;
int machine[MAXN];

bool valid( int time ){
    int total = 0;
    for( int i = 0 ; i < n ; i++ ){
        total += time / machine[i];
        if( total >= t ) return true;   // 這裡要注意，如果超過就直接回傳了，不然 long long 裝不下
    }
    return false;
}

signed main(){
    opt;
    cin >> n >> t;
    for( int i = 0 ; i < n ; i++ ) cin >> machine[i];

    int step = 1e18;
    while( step > 0 ){
        if( valid(res+step) ) step /= 2;
        else res += step;
    }

    cout << res+1;
}