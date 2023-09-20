/* Question : OJ Number */

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
const int MAXN = 5e5 + 50;
const int Mod = 1e9 + 7;
int n, k, arr[MAXN];

struct Node{
    int prefix, suffix, sum, ans;
} seg[MAXN * 4];

void build( int L, int R, int cnt ){
    if( L == R ){
        seg[cnt].sum = arr[L] % k;
        seg[cnt].prefix = arr[L] % k;
        seg[cnt].suffix = arr[L] % k;
        seg[cnt].ans = arr[L] % k;
        return;
    }

    int M = ( L + R ) / 2;
    build(L, M, nL);
    build(M+1, R, nR);

    seg[cnt].sum = ( seg[nL].sum + seg[nR].sum ) % k;
    seg[cnt].prefix = max( seg[nL].prefix % k, ( seg[nL].sum + seg[nR].prefix ) % k );
    seg[cnt].suffix = max( ( seg[nR].sum + seg[nL].suffix ) % k, seg[nR].suffix % k );
    seg[cnt].ans = max( max( seg[nL].ans, seg[nR].ans ), ( seg[nL].suffix + seg[nR].prefix ) % k );
}

signed main(){
    opt;
    cin >> n >> k;
    for( int i = 1 ; i <= n ; i++ ) cin >> arr[i];
    build(1, n, 1);

    cout << seg[1].ans << "\n";

    for( int i = 1 ; i <= n * 4 ; i++ ) cout << seg[i].sum << " \n"[i==n*4];
    for( int i = 1 ; i <= n * 4 ; i++ ) cout << seg[i].ans << " \n"[i==n*4];
    for( int i = 1 ; i <= n * 4 ; i++ ) cout << seg[i].suffix << " \n"[i==n*4];
    for( int i = 1 ; i <= n * 4 ; i++ ) cout << seg[i].prefix << " \n"[i==n*4];
}

/* PrevSum Solution - O( N(N-1) ) */
/* Question : OJ Number */

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
const int MAXN = 5e5 + 50;
const int Mod = 1e9 + 7;
int n, k, res, amt[MAXN], pre[MAXN];

signed main(){
    opt;
    cin >> n >> k;
    for( int i = 1 ; i <= n ; i++ ){
        cin >> amt[i];
        pre[i] = pre[i-1] + amt[i];
    }

    res = -1;
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = i ; j <= n ; j++ ) res = max(res, (pre[j]-pre[i-1]) % k );
    }

    cout << res << "\n";
}