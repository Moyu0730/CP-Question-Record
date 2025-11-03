/* Question : Luogu P2677. [ USACO07DEC ] Bookshelf 2 B */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int MAXN = 20 + 5;
const int Mod = 1e9 + 7;
int n, b, tmp, ans = 1e7;
int h[MAXN];

signed main(){
    opt;
    cin >> n >> b;
    for( int i = 0 ; i < n ; i++ ) cin >> h[i];
    for( int i = 0 ; i < (1<<n) ; i++ ){
        tmp = 0;
        for( int j = 0 ; j < n ; j++ ){
            if( i & (1<<j) ) tmp += h[j];
        }

        if( tmp >= b ) ans = min( tmp, ans );
    }

    cout << ans - b;
}