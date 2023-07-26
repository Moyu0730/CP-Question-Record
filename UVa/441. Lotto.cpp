/* Question : UVa 441. Lotto */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define f first
#define s second

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 13 + 50;
const int Mod = 1e9 + 7;
int k, arr[MAXN], out[MAXN];
bool flag;

void print( int t, int cnt ){
    if( t == 0 ){
        for( int i = 0 ; i < 6 ; i++ ) cout << out[i] << " \n"[i==5];
        return;
    }
    if( cnt >= k ) return;

    // Pick
    out[6-t] = arr[cnt];
    print(t-1, cnt+1);

    // Doesn't Pick
    print(t, cnt+1);
}

signed main(){
    opt;
    while( cin >> k ){
        if( k == 0 ) break;
        if( flag ) cout << "\n";
        flag = true;
        for( int i = 0 ; i < k ; i++ ) cin >> arr[i];
        print(6, 0);
    }
}