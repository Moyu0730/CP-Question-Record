/* Question : CSES 1094. Increasing Array */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mem(x) memset(x, 0x3F, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define f first
#define s second
#define ll long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
int n, arr[MAXN];
ll res;

signed main(){
    opt;
    cin >> n;
    for( int i = 0 ; i < n ; i++ ) cin >> arr[i];

    for( int i = 0 ; i < n-1 ; i++ ){
        if( arr[i] > arr[i+1] ){
            res += arr[i] - arr[i+1];
            arr[i+1] = arr[i];
        }
    }

    cout << res;
}