/* Question : AtCoder Beginner Contest 396 - C. Buy Balls */

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
const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;
const int MEMINF = 0x3F;
const int MEMINF_VAL = 0x3F3F3F3F;
const int MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int n, m, val, res, amt, lst;
vector<int> arr, w;

signed main(){
    opt;

    cin >> n >> m;
    for( int i = 0 ; i < n ; ++i ){
        cin >> val;
        arr.pb(val);
    }

    for( int j = 0 ; j < m ; ++j ){
        cin >> val;
        if( val >= 0 ) w.pb(val);
    }

    sort(arr.begin(), arr.end(), greater<int>());
    sort(w.begin(), w.end(), greater<int>());

    m = w.size();

    for( int i = 0 ; i < n ; ++i ){
        if( i >= m ){
            if( arr[i] > 0 ) res += arr[i];
        }else{
            if( arr[i] + w[i] > 0 ) res += arr[i] + w[i];
            else break;
        }
    }

    cout << res << "\n";
}