/* Question : AtCoder Beginner Contest 398 - C. Uniqueness */

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

int n, res, arr[MAXN];
map<int, int> mp;

signed main(){
    opt;

    cin >> n;

    for( int i = 0 ; i < n ; ++i ){
        cin >> arr[i];

        if( mp[arr[i]] == 0 ) mp[arr[i]] = i + 1;
        else mp[arr[i]] = -1 * ( i + 1 );
    }

    if( n == 1 ){
        cout << "1\n";
        exit(0);
    }

    res = -1;
    for( auto i = mp.rbegin() ; i != mp.rend() ; i++ ){
        if( i->second > 0 ){
            res = i->second;
            break;
        }
    }

    cout << res << "\n";
}