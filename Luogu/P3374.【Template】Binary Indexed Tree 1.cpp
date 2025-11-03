/* Question : Luogu P3374［Template］Binary Indexed Tree 1 */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long

const int MAXN = 5e5 + 50;
const int Mod = 1e9 + 7;
int n, m, op, a, b;
int arr[MAXN];
int bit[MAXN];

int func( int x ){
    return x&(-x);
}

int query( int pos ){
    int res = 0;
    for( int i = pos ; i > 0 ; i -= func(i) ) res += bit[i];
    return res;
}

void add( int pos, int val ){
    for( int i = pos ; i <= n ; i += func(i) ) bit[i] += val;
}

signed main(){
    opt;
    cin >> n >> m;
    for( int i = 1 ; i <= n ; i++ ) cin >> arr[i];
    for( int i = 1 ; i <= n ; i++ ) add(i, arr[i]);

    for( int i = 0 ; i < m ; i++ ){
        cin >> op >> a >> b;
        if( op == 1 ) add( a, b );
        else cout << query(b) - query(a-1) << "\n";
    }
}