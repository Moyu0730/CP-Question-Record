/* Question : CSES 1745. Money Sums */

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
const int MAXN = 1e2 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 1e5 + 50;
const int MEMINF = 0x3F;
const int MEMINF_VAL = 0x3F3F3F3F;
const int MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int n, arr[MAXN];
bool dp[INF];
set<int> res;
vector<pii> v;

signed main(){
    opt;

    cin >> n;

    for( int i = 0 ; i < n ; ++i ) cin >> arr[i];

    sort(arr, arr + n);

    for( int i = 0 ; i < n ; ++i ){
        if( i == 0 || arr[i] != v.back().F ) v.pb({arr[i], 1});
        else ++v.back().S;
    }

    dp[0] = true;
    for( int i = 0 ; i < v.size() ; ++i ){
        for( int j = 0 ; j < v[i].F ; ++j ){
            int amt = 0;
            for( int k = j ; k < INF ; k += v[i].F ){
                if( dp[k] ) amt = v[i].S;
                else if( amt > 0 ){
                    amt--;
                    dp[k] = true;
                    res.insert(k);
                }
            }
        }
    }

    cout << res.size() << "\n";
    for( auto& i : res ) cout << i << " ";
    cout << "\n";
}