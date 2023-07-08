/* Question : CSES 1096. Repetitions */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mem(x) memset(x, 0x3F, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define f first
#define s second

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
string str;
char pre;
int ans, tmp;

signed main(){
    opt;
    cin >> str;
    pre = str[0];
    ans = 1;
    for( int i = 0 ; i < str.size() ; i++ ){
        if( str[i] == pre ){
            tmp++;
        }else{
            ans = max( ans, tmp );
            tmp = 1;
            pre = str[i];
        }
    }
    ans = max( tmp, ans );
    
    cout << ans;
}