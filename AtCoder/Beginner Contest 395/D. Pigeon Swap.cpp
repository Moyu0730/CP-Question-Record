/* Question : AtCoder Beginner Contest 395 - D. Pigeon Swap */

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
const int MAXN = 1e6 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;
const int MEMINF = 0x3F;
const int MEMINF_VAL = 0x3F3F3F3F;
const int MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int n, q, op, a, b, pigeon[MAXN], nest[MAXN], id[MAXN];

signed main(){
    opt;

    cin >> n >> q;

    for( int i = 1 ; i <= n ; ++i ) pigeon[i] = id[i] = nest[i] = i;

    while( q-- ){
        cin >> op;

        if( op == 1 ){
            cin >> a >> b;
            pigeon[a] = nest[b];
        }else if( op == 2 ){
            cin >> a >> b;
            swap(nest[a], nest[b]);
            id[nest[a]] = a;
            id[nest[b]] = b;
        }else{
            cin >> a;
            cout << id[pigeon[a]] << "\n";
        }
    }
}