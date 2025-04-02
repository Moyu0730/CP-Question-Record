/* Question : AtCoder Beginner Contest 398 - F. ABCBA */

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
const int MAXN = 5e5 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;
const int MEMINF = 0x3F;
const int MEMINF_VAL = 0x3F3F3F3F;
const int MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

const int p = 48763;

string str;
int n, res, poshsh[MAXN], neghsh[MAXN], ksm[MAXN];

void pre(){
    int power = p;
    for( int i = 0 ; i < n ; ++i ){
        poshsh[i] = (i == 0) ? str[i] : ( poshsh[i-1] * p ) % Mod + str[i];
        neghsh[n-1-i] = (i == 0) ? str[n-1-i] : ( neghsh[n-1-i+1] * p ) % Mod + str[n-1-i];
        ksm[i] = (i == 0) ? 1 : ksm[i-1] * p;

        poshsh[i] %= Mod;
        neghsh[i] %= Mod;
        ksm[i] %= Mod;
    }
}

int getposhsh( int l, int r ){
    if( l == 0 ) return poshsh[r];
    return ( poshsh[r] - ( poshsh[l-1] * ksm[r-l+1] ) % Mod + Mod ) % Mod;
}

int getneghsh( int l, int r ){
    if( r == n-1 ) return neghsh[l];
    return ( neghsh[l] - ( neghsh[r+1] * ksm[r-l+1] ) % Mod + Mod ) % Mod;
}

int query( int low, int high ){
    int len = n - high, step = n;

    if( getneghsh(low - len + 1, low) == getposhsh(high, n-1) ) return low - len;
    else return n - 2;
}

signed main(){
    opt;

    cin >> str;

    n = str.size();
    pre();

    res = n - 2;
    for( int i = n / 2 ; i < n ; ++i ){
        if( n % 2 == 0 ){
            if( i - 1 >= 0 ) res = min(res, query(i-1, i));
            if( i + 1 < n && i - 1 >= 0 ) res = min(res, query(i-1, i+1));
        }else{
            if( i + 1 < n ) res = min(res, query(i, i+1));
            if( i + 1 < n && i - 1 >= 0 ) res = min(res, query(i-1, i+1));
        }
    }

    cout << str;
    for( int i = res ; i >= 0 ; --i ) cout << str[i];
    cout << "\n";
}