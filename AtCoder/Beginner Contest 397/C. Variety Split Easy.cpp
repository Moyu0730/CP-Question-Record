/* Question : AtCoder Beginner Contest 397 - C. Variety Split Easy */

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
const int MAXN = 3e5 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;
const int MEMINF = 0x3F;
const int MEMINF_VAL = 0x3F3F3F3F;
const int MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int n, amt[MAXN], arr[MAXN], suf[MAXN], pre[MAXN];

signed main(){
    opt;

    cin >> n;
    
    for( int i = 0 ; i < n ; ++i ) cin >> arr[i];

    for( int i = 0 ; i < n ; ++i ){
        if( amt[arr[i]] == 0 ){
            pre[i] = i == 0 ? 1 : pre[i-1] + 1;
            ++amt[arr[i]];
            continue;
        }

        pre[i] = pre[i-1];
    }

    mem(amt, 0);

    for( int i = n - 1 ; i >= 0 ; --i ){
        if( amt[arr[i]] == 0 ){
            suf[i] = i == n-1 ? 1 : suf[i+1] + 1;
            ++amt[arr[i]];
            continue;
        }

        suf[i] = suf[i+1];
    }

    int res = 0;
    for( int i = 0; i < n ; ++i ){
        int cnt;
        
        cnt = i == n-1 ? pre[n-2] + suf[n-1] : pre[i] + suf[i+1];

        res = max(res, cnt);
    }

    cout << res << "\n";
}