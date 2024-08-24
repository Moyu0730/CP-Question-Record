/* Question : ZeroJudge a104. Sort - Merge Sort */

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

void merge( int left, int right ){
    // Terminal Condition
    if( right == left ) return;

    // Divide
    int mid = ( left + right ) / 2;
    merge(left, mid);
    merge(mid + 1, right);

    // Copy
    int L[MAXN], R[MAXN], now;
    now = 0;
    for( int i = left ; i <= mid ; i++ ) L[now++] = arr[i];
    now = 0;
    for( int i = mid + 1 ; i <= right ; i++ ) R[now++] = arr[i];

    // Merge
    int idx_L = 0, idx_R = 0;
    for( int i = left ; i <= right ; i++ ){
        if( idx_L > mid - left ) arr[i] = R[idx_R++];
        else if( idx_R > right - ( mid + 1 ) ) arr[i] = L[idx_L++];
        else if( L[idx_L] < R[idx_R] ) arr[i] = L[idx_L++];
        else arr[i] = R[idx_R++];
    }
}

signed main(){
    opt;
    while( cin >> n ){
        for( int i = 0 ; i < n ; i++ ) cin >> arr[i];

        merge(0, n-1);

        for( int i = 0 ; i < n ; i++ ) cout << arr[i] << " \n"[i==n-1];
    }
}