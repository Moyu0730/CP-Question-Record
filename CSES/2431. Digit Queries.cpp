/* Question : CSES 2431. Digit Queries */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pirq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define f first
#define s second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e3 + 50;
const int Mod = 1e9 + 7;
int n, arr[MAXN];

signed main(){
    opt;
    cin >> n;
    for( int i = 0 ; i < n ; i++ ) cin >> arr[i];
    for( int i = 0 ; i < n ; i++ ){
        if( i <= 9 ){
            cout << i;
        }else if(){
            
        }
    }
}