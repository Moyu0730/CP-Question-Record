#include<iostream>
#include<iomanip>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int MAXN = 1e6 + 50;
const int Mod = 1e9 + 7;
int N, m, tmp;

struct LinkedList{
    int n, nxt[MAXN];
    bool dead[MAXN];

    void init( int _n ){
        n = _n;
        for ( int i = 0 ; i <= n ; i++ ){
            if( i == n ) nxt[i] = 0;
            else nxt[i] = i + 1;
        }
    }

    void del( int k ){
        if( dead[k] == true || nxt[k] == 0 ) cout << "0u0 ...... ?\n";
        else{
            cout << nxt[k] << "\n";
            dead[nxt[k]] = true;
            nxt[k] = nxt[nxt[k]];
        }
    }
} LL;

signed main(){
    opt;
    cin >> N >> m;
    LL.init(N);
    while( m-- ){
        cin >> tmp;
        LL.del(tmp);
    }
}