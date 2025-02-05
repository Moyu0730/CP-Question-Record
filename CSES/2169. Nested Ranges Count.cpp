/* Question : CSES 2169. Nested Ranges Count */

#include<bits/stdc++.h>
using namespace std;

/* Pragma */
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

/* Self Define */
#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pirq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define vsort(x) sort(x.begin(), x.end());
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define F first
#define S second
#define X first
#define Y second
#define int long long
#define ll long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;
const int MEMINF = 0x3F;
const int MEMINF_VAL = 0x3F3F3F3F;
const int MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

vector<int> disc;
int a, b, n, BIT[MAXN], res[5][MAXN], pre[MAXN];

int lowbit( int x ){
    return x & -x;
}

int query( int pos ){
    if( pos <= 0 ) return 0;

    int ans = 0;
    while( pos ){
        ans += BIT[pos];
        pos -= lowbit(pos);
    }

    return ans;
}

void update( int x, int val ){
    while( x <= MAXN ){
        BIT[x] += val;
        x += lowbit(x);
    }
}

int sum( int l, int r ){
    if( l > r ) return 0;
    return query(r) - query(l - 1);
}

struct Node {
    int l, r, id;
} arr[MAXN];

bool cmp( Node x, Node y ){
    if( x.l == y.l ) return x.r > y.r;
    else return x.l < y.l;
}

signed main(){
    opt;

    cin >> n;

    for( int i = 0 ; i < n ; ++i ){
        cin >> arr[i].l >> arr[i].r;
        arr[i].id = i;
        pre[i] = arr[i].r;
    }

    sort(pre, pre + n);

    disc.pb(pre[0]);
    for( int i = 1 ; i < n ; ++i ){
        if( pre[i] != pre[i-1] ) disc.pb(pre[i]);
    }

    for( int i = 0 ; i < n ; ++i ) arr[i].r = lower_bound(disc.begin(), disc.end(), arr[i].r) - disc.begin() + 1;

    sort(arr, arr + n, cmp);

    int MIN = INF;
    for( int i = n - 1 ; i >= 0 ; --i ){
        if( arr[i].r >= MIN ) res[0][arr[i].id] = query(arr[i].r);
        else res[0][arr[i].id] = 0;

        update(arr[i].r, 1);
        MIN = min(MIN, arr[i].r);
    }

    mem(BIT, 0);

    int MAX = -1;
    for( int i = 0 ; i < n ; ++i ){
        if( arr[i].r <= MAX ) res[1][arr[i].id] = sum(arr[i].r, MAX);
        else res[1][arr[i].id] = false;

        update(arr[i].r, 1);
        MAX = max(MAX, arr[i].r);
    }
    
    for( int i = 0 ; i < n ; ++i ) cout << res[0][i] << " ";
    cout << "\n";

    for( int i = 0 ; i < n ; ++i ) cout << res[1][i] << " ";
    cout << "\n";
}