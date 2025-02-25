/* Question : CSES 1140. Projects */

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
const int MAXN = 4e5 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;
const int MEMINF = 0x3F;
const int MEMINF_VAL = 0x3F3F3F3F;
const int MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

const int EDGE = 5e7;

int n, BIT[MAXN];
vector<pair<pii, int>> arr;
vector<int> distinct, tmp;

int lowbit( int x ){ return x & -x; }
 
int query( int pos ){
    int ans = 0;

    while( pos ){
        ans = max(ans, BIT[pos]);
        pos -= lowbit(pos);
    }
    
    return ans;
}
 
void update( int x, int val ){
    while( x < MAXN ){
        BIT[x] = max(BIT[x], val);
        x += lowbit(x);
    }
}

bool cmp( pair<pii, int> x, pair<pii, int> y ){
    return x.F.S < y.F.S;
}

signed main(){
    opt;

    cin >> n;
    arr.resize(n);
    for( int i = 0 ; i < n ; i++ ){
        cin >> arr[i].F.F >> arr[i].F.S >> arr[i].S;
        tmp.pb(arr[i].F.F);
        tmp.pb(arr[i].F.S);
    }

    vsort(tmp);

    distinct.pb(tmp[0]);
    for( int i = 1 ; i < tmp.size() ; i++ ){
        if( tmp[i] != tmp[i-1] ) distinct.pb(tmp[i]);
    }

    for( int i = 0 ; i < arr.size() ; ++i ){
        arr[i].F.F = lower_bound(distinct.begin(), distinct.end(), arr[i].F.F) - distinct.begin() + 1;
        arr[i].F.S = lower_bound(distinct.begin(), distinct.end(), arr[i].F.S) - distinct.begin() + 1;
    }

    sort(arr.begin(), arr.end(), cmp);

    for( auto i : arr ){
        int cnt = query(i.F.S);
        int q = query(i.F.F - 1);

        if( q + i.S > cnt ) update(i.F.S, q + i.S);
    }

    cout << query(arr.back().F.S) << "\n";
}