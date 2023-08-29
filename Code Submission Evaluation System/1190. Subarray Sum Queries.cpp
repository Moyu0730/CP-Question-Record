/* Question : CSES 1190. Subarray Sum Queries */

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
} seg[MAXN * 4];

void update( int L, int R, int pos, int val, int cnt ){
    if( R < L || pos > R || pos < L ) return;
    if( pos == L && pos == R ){
        seg[cnt].sum = max((long long)0, val);
        seg[cnt].prefix = max((long long)0, val);
        seg[cnt].suffix = max((long long)0, val);
        seg[cnt].sum = val;
        return;
    }

    int M = (L + R) / 2;
    update(L, M, pos, val, nL);
    update(M+1, R, pos, val, nR);

    seg[cnt].sum = seg[nL].sum + seg[nR].sum;
    seg[cnt].prefix = max( seg[nL].prefix, seg[nL].sum + seg[nR].prefix );
    seg[cnt].suffix = max( seg[nR].suffix, seg[nR].sum + seg[nL].suffix );
    seg[cnt].ans = max( max( seg[nL].ans, seg[nR].ans ), seg[nL].suffix + seg[nR].prefix );
}

void build( int L, int R, int cnt ){
    if( L == R ){
        seg[cnt].sum = max((long long)0, arr[L]);
        seg[cnt].prefix = max((long long)0, arr[L]);
        seg[cnt].suffix = max((long long)0, arr[L]);
        seg[cnt].sum = arr[L];
        return;
    }

    int M = ( L + R ) / 2;
    build(L, M, nL);
    build(M+1, R, nR);

    seg[cnt].sum = seg[nL].sum + seg[nR].sum;
    seg[cnt].prefix = max( seg[nL].prefix, seg[nL].sum + seg[nR].prefix );
    seg[cnt].suffix = max( seg[nR].suffix, seg[nR].sum + seg[nL].suffix );
    seg[cnt].ans = max( max( seg[nL].ans, seg[nR].ans ), seg[nL].suffix + seg[nR].prefix );
}

signed main(){
    opt;
    cin >> n >> m;
    for( int i = 1 ; i <= n ; i++ ) cin >> arr[i];
    build(1, n, 1);

    while( m-- ){
        cin >> a >> b;
        update(1, n, a, b, 1);
        cout << seg[1].ans << "\n";
    }
}