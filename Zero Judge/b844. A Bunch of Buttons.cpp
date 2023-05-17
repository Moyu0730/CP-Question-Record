/* Question : ZeroJudge b844. A Bunch of Buttons */

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

const int MAXN = 5e5 + 50;
const int Mod = 1e9 + 7;
int op[MAXN];
int n, q, p;

signed main(){
    opt;
    while( cin >> n >> q ) {    // Infinity Input ( Title Doesn't Specified QQ )
        for( int i = 0 ; i < n ; i++ ) cin >> op[i];
        sort(op, op+n);

        while( q-- ){
            cin >> p;
            int ind = upper_bound(op, op+n, p) - op;    // Upper_bound : Get the Ops which > val

            if( ind % 2 ) cout << "1\n";
            else cout << "0\n";
        }
    }
}