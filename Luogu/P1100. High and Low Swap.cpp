/* Question : Luogu P1100. High and Low Swap */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
unsigned int n;

signed main(){
    opt;
    cin >> n;
    cout << ( ( n >> 16 ) + ( n << 16 ) );
}