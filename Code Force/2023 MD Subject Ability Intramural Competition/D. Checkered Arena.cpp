/* Question : CF ( 2023 MD Subject Ability Intramural Competition ) D. Checkered Arena */

#include<bits/stdc++.h>
using namespace std;
 
#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
const int MAXN = 1e3 + 50;
const int Mod = 1e9 + 7;
int n, k, a, b;
bool x[MAXN];
bool y[MAXN];
 
signed main(){
    opt;
    cin >> n >> k;
 
    memset(x, true, sizeof(x));
    memset(y, true, sizeof(y));
    for( int i = 0 ; i < k ; i++ ){
        cin >> a >> b;
        x[a] = false;
        y[n-b+1] = false;
    }
 
    int ans = 0;
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= n ; j++ ){
            if( x[i] == true && y[j] == true ) ans++;
        }
    }
 
    cout << ans << "\n";
}