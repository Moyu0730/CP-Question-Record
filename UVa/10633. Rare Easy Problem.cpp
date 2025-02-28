/* Question : UVa 10633. Rare Easy Problem */

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

int q, num;
vector<int> res;

signed main(){
    while( cin >> q && q != 0 ){
        res.clear();

        for( int i = 0 ; i <= 9 ; ++i ){
            if( ( q - i ) % 9 == 0 ){
                num = ( q - i ) / 9 * 10 + i;
                res.pb(num);
            }
        }

        vsort(res);

        for( int i = 0 ; i < res.size() ; ++i ){
            if( i == 0 ) cout << res[i];
            else cout << " " << res[i];
        }
        cout << "\n";
    }
}
