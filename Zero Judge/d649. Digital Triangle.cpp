/* Question : ZJ d649. Digital Triangle */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define F first
#define S second
#define X first
#define Y second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
const int INF = 1e9;

int n;

signed main(){
    opt;

    while( cin >> n ){
        if( n == 0 ) break;

        for( int i = 1 ; i <= n ; i++ ){
            for( int j = 1 ; j <= n - i ; j++ ){
                cout << "_";
            }

            for( int j = 1 ; j <= i ; j++ ){
                cout << "+";
            }

            cout << "\n";
        }

        cout << "\n";
    }
}