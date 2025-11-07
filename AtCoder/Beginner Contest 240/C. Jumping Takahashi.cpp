/* Question : AtCoder Beginner Contest 240 - C - Jumping Takahashi */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int MAXN = 1e4 + 50;
const int Mod = 1e9 + 7;
int n, x, a, b;
bitset<MAXN> bs;

signed main(){
    opt;
    cin >> n >> x;
    bs[0] = 1;
    for( int i = 0 ; i < n ; i++ ){
        cin >> a >> b;
        bs = ( bs << a ) | ( bs << b );
    }

    if( bs[x] ) cout << "Yes\n";
    else cout << "No\n";
}