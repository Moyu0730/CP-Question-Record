/* Question : AtCoder Beginner Contest 327 - B. A^A */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define priq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define F first
#define S second
#define x first
#define y second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
int val, res[20] = {0, 1, 4, 27, 256, 3125, 46656, 823543, 1677216, 387420489, 10000000000, 285311670611, 8916100448256, 302875106592253, 11112006825558016, 437893890380859375};
                    // 1  2   3    4     5      6       7        8          9           10            11             12               13                 14
signed main(){
    opt;
    cin >> val;
    
    for( int i = 1 ; i <= 15 ; i++ ){
        if( val == res[i] ){
            cout << i << "\n";
            break;
        }
        
        if( val != res[i] && i == 15 ) cout << "-1\n";
    }
}