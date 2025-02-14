/* Question : CSES 1145. Increasing Subsequence */

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
#define sortV(x) sort(x.begin(), x.end());
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

int Max, n, arr[MAXN], BIT[MAXN], tmp[MAXN], before[MAXN];
vector<int> distinct;

int lowbit( int x ){
    return x & -x;
}

int query( int pos ){
    if( pos <= 0 ) return 0;

    int ans = -1;
    while( pos ){
        ans = max(ans, BIT[pos]);
        pos -= lowbit(pos);
    }

    return ans;
}

void update( int x, int val ){
    while( x <= n ){
        BIT[x] = max(BIT[x], val);
        x += lowbit(x);
    }
}

signed main(){
    opt;

    cin >> n;

    for( int i = 0 ; i < n ; i++ ){
        cin >> before[i];
        tmp[i] = before[i];
    }

    sort(tmp, tmp + n);

    distinct.pb(tmp[0]);
    for( int i = 1 ; i < n ; i++ ){
        if( tmp[i] != tmp[i-1] ) distinct.pb(tmp[i]);
    }

    for( int i = 0 ; i < n ; i++ ){
        arr[i] = lower_bound(distinct.begin(), distinct.end(), before[i]) - distinct.begin() + 1;
        Max = max(Max, arr[i]);
    }

    for( int i = 0 ; i < n ; ++i ) update(arr[i], query(arr[i] - 1) + 1);

    int res = 0;
    for( int i = 0 ; i <= Max ; ++i ) res = max(res, BIT[i]);
    
    cout << res << "\n";
}