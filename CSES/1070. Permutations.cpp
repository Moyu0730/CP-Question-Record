/* Question : CSES 1070. Permutations */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mem(x) memset(x, 0x3F, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define f first
#define s second

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e6 + 50;
const int Mod = 1e9 + 7;
int arr[MAXN], n;
bool flag, isPrint;

signed main(){
    opt;
    cin >> n;
    
    if( n < 4 ){
        if( n == 1 ) cout << 1 << "\n";
        else cout << "NO SOLUTION\n";
    }else{
        for( int i = 2 ; i <= n ; i += 2 ) cout << i << " ";
        for( int i = 1 ; i <= n ; i += 2 ) cout << i << " ";
        cout << "\n";
    }
}