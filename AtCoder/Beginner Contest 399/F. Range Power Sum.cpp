/* Question : AtCoder Beginner Contest 399 - F. Range Power Sum */

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
#define all(v) x.begin(), v.end()
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
const int Mod = 998244353;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;
const int MEMINF = 0x3F;
const int MEMINF_VAL = 0x3F3F3F3F;
const int MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int n, k, res, arr[MAXN], T[MAXN][10 + 5], C[10 + 5][10 + 5];

/* PreCalculate Combination */
void pre(){
    for( int i = 0 ; i <= k ; ++i ){
        C[i][0] = 1;
        C[i][i] = 1;

        for( int j = 1 ; j < i ; ++j ) C[i][j] = ( C[i-1][j-1] + C[i-1][j] ) % Mod;
    }
}

int ksm( int base, int power ){
    int res = 1;

    while( power > 0 ){
        if( power & 1 ) res = ( res * base ) % Mod;

        power >>= 1;
        base = ( base * base ) % Mod;
    }

    return res % Mod;
}

signed main(){
    opt;

    cin >> n >> k;
    for( int i = 1 ; i <= n ; ++i ) cin >> arr[i];

    pre();

    for( int i = 1 ; i <= n ; ++i ){
        for( int j = 0 ; j <= k ; ++j ){
            T[i][j] = ksm(arr[i], j);
            
            for( int t = 0 ; t <= j ; ++t ){
                T[i][j] = ( T[i][j] + ( ( C[j][t] * ksm(arr[i], j-t) ) % Mod * T[i-1][t] ) % Mod ) % Mod;
            }
        }
    }

    res = 0;
    for( int i = 1 ; i <= n ; ++i ) res = ( res + T[i][k] ) % Mod;

    cout << res << "\n";
}