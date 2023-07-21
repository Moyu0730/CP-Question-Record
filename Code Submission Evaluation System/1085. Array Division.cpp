/* Question : CSES 1085. Array Division */

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
int n, k, res, op, ind, tmp;
int arr[MAXN];

bool valid( int ans ){
    op = 1, ind = 0, tmp = 0;

    while( ind < n ){
        // cout << ind << " " << tmp << " " << op << "\n";
        if( arr[ind] > ans ) return false;
        if( tmp + arr[ind] <= ans ){
            tmp += arr[ind];
        }else{
            op++;
            tmp = arr[ind];
        }
        ind++;
    }

    return op <= k;
}

signed main(){
    opt;
    cin >> n >> k;
    for( int i = 0 ; i < n ; i++ ){
        cin >> arr[i];
    }

    int step = 1e18;
    while( step > 0 ){
        if( !valid( res + step ) ) res += step;
        else step /= 2;
    }

    cout << res+1 << "\n";
}