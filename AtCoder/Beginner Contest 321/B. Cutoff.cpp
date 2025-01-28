/* Question : AtCoder Beginner Contest 321 - B. Cutoff */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define priq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define f first
#define s second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e2 + 50;
const int Mod = 1e9 + 7;
int n, tar, sum, arr[MAXN];

signed main(){
    opt;
    cin >> n >> tar;
    for( int i = 0 ; i < n-1 ; i++ ) cin >> arr[i];

    sort(arr, arr + n - 1);
    
    for( int i = 0 ; i < n - 1 ; i++ ){
        if( i != 0 && i != n - 2 ) sum += arr[i];
    }

    
    int dif = tar - sum;

    if( sum + arr[0] >= tar ) cout << "0\n";
    else if( dif <= arr[n-2] && dif >= arr[0] ) cout << dif << "\n";
    else if( sum + arr[n-2] > tar ) cout << arr[n-2] << "\n";
    else cout << "-1\n";
}