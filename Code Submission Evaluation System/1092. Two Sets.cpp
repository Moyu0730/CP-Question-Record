/* Question : CSES 1092. Two Sets */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mem(x) memset(x, 0x3F, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define f first
#define s second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
int mid, sum, n;
vector<int> le;
vector<int> ri;

signed main(){
    opt;
    cin >> n;
    if( (n * (n+1)) % 4 == 0 ){
        sum = n * (n+1) / 2;
        int l_val = sum / 2;
        int r_val = sum / 2;
        for( int i = n ; i > 0 ; i-- ){
            if( l_val - i >= 0 ){
                le.push_back(i);
                l_val -= i;
            }else{
                ri.push_back(i);
                r_val -= i;
            }
        }
        cout << "YES\n";
        cout << le.size() << "\n";
        for( auto i : le ) cout << i << " ";
        cout << "\n" << ri.size() << "\n";
        for( auto i : ri ) cout << i << " ";
        cout << "\n";
    }else{
        cout << "NO\n";
    }
}