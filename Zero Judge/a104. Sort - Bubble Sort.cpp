/* Question :  ZeroJudge a104. Sort - Bubble Sort */

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
const int MAXN = 1e3 + 50;
const int Mod = 1e9 + 7;
const int INF = 1e9;
int n, arr[MAXN];

signed main(){
    opt;
    while( cin >> n ){
        for( int i = 0 ; i < n ; i++ ) cin >> arr[i];

        for( int i = 0 ; i < n ; i++ ){
            for( int j = 0 ; j < n - i - 1 ; j++ ){
                if( arr[j] > arr[j+1] ) swap(arr[j], arr[j+1]);
            }
        }

        for( int i = 0 ; i < n ; i++ ) cout << arr[i] << " \n"[i==n-1];
    }
}