/* Question : CF ( 2023 MD Subject Ability Intramural Competition ) B. Tim Chen no Loli Base */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int MAXN = 2e4 + 50;
const int Mod = 1e9 + 7;
int item[MAXN], arr[MAXN];
int n, tmp, m = 0;

signed main(){
    opt;
    cin >> n;
    
    // Input
    for( int i = 1 ; i <= n ; i++ ){
        cin >> tmp;
        arr[i] = tmp;
        m = max(m, tmp);
    }
    memset(item, -1, sizeof(item));
    for( int i = 1 ; i <= n ; i++ ) cin >> item[arr[i]];

    // Dealt
    for( int i = 1 ; i <= m ; i++ ){
        for( int j = i - 1 ; j >= 1 ; j-- ){
            if( item[i] == -1 || i <= 2 ) continue;
            if( item[j] == -1 || item[i-j] == -1 ) continue;
            if( j == i-j ) continue;

            item[i] = min( item[i], item[j] + item[i-j] );
        }
    }

    // Output
    for( int i = 1   ; i <= n ; i++ ) cout << item[arr[i]] << " ";
}