/* Question : CSES 2168. Nested Ranges Check */

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

struct Node {
    int l, r, id;
} arr[MAXN];

bool res[5][MAXN];
int a, b, n;

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
    }

    sort(arr, arr + n, cmp);

    int MAX = -1;
    for( int i = 0 ; i < n ; ++i ){
        if( arr[i].r <= MAX ) res[1][arr[i].id] = true;
        else res[1][arr[i].id] = false;

        MAX = max(MAX, arr[i].r);
    }

    int MIN = INF;
    for( int i = n - 1 ; i >= 0 ; --i ){
        if( arr[i].r >= MIN ) res[0][arr[i].id] = true;
        else res[0][arr[i].id] = false;

        MIN = min(MIN, arr[i].r);
    }
    
    for( int i = 0 ; i < n ; ++i ) cout << res[0][i] << " ";
    cout << "\n";

    for( int i = 0 ; i < n ; ++i ) cout << res[1][i] << " ";
    cout << "\n";
}