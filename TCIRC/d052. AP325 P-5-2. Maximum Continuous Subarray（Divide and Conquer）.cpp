/* Question : TCIRC d052. AP325 P-5-2. Maximum Continuous Subarray（Divide and Conquer） */

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

#define nL cnt * 2
#define nR cnt * 2 + 1

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
int n, m, a, b, arr[MAXN];

struct Node{
    int prefix, suffix, sum, ans;
} daq[MAXN * 4];

void dealt( int L, int R, int cnt ){
    if( L == R ){
        daq[cnt].sum = max((long long)0, arr[L]);
        daq[cnt].prefix = max((long long)0, arr[L]);
        daq[cnt].suffix = max((long long)0, arr[L]);
        daq[cnt].sum = arr[L];
        return;
    }

    int M = ( L + R ) / 2;
    dealt(L, M, nL);
    dealt(M+1, R, nR);

    daq[cnt].sum = daq[nL].sum + daq[nR].sum;
    daq[cnt].prefix = max( daq[nL].prefix, daq[nL].sum + daq[nR].prefix );
    daq[cnt].suffix = max( daq[nR].suffix, daq[nR].sum + daq[nL].suffix );
    daq[cnt].ans = max( max( daq[nL].ans, daq[nR].ans ), daq[nL].suffix + daq[nR].prefix );
}

signed main(){
    opt;
    cin >> n;
    for( int i = 1 ; i <= n ; i++ ) cin >> arr[i];
    dealt(1, n, 1);
    cout << daq[1].ans << "\n";
}