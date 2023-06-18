/* Question : Luogu P1036. [ NOIP2002 Popularization Group ] Selection Number */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long

const int MAXN = 20 + 5;
const int Mod = 1e9 + 7;
int n, k, ans, tmp;
int num[MAXN];

bool isPrime( int x ){
    for( int i = 2 ; i * i <= x ; i++ ){
        if( x % i == 0 ) return false;
    }
    return true;
}

void pmt( int i, int j, int sum ){
    if( j == 0 ){
        if( isPrime(sum) ) ans++;
        return;
    }else if( i < n ){
        pmt(i+1, j-1, sum + num[i]);
        pmt(i+1, j, sum);
    }
}

signed main(){
    opt;
    cin >> n >> k;
    for( int i = 0 ; i < n ; i++ ) cin >> num[i];
    pmt(0, k, 0);

    cout << ans;
}