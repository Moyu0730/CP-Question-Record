/* Question : CSES 2163. Josephus Problem II */

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
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;
const int MEMINF = 0x3F;
const int MEMINF_VAL = 0x3F3F3F3F;
const int MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int n, k, BIT[MAXN];

int lowbit( int x ){
    return x & -x;
}

int query( int pos ){
    if( pos <= 0 ) return 0;

    int ans = 0;
    while( pos ){
        ans += BIT[pos];
        pos -= lowbit(pos);
    }

    return ans;
}

void update( int x, int val ){
    while( x <= n ){
        BIT[x] += val;
        x += lowbit(x);
    }
}

int sum( int l, int r ){
    if( l > r ) return 0;
    return query(r) - query(l - 1);
}

bool valid( int prev, int jump, int target ){
    if( jump > n ) return false;
    if( sum(prev, jump) < target ) return true;
    else return false;
}

signed main(){
    opt;
    cin >> n >> k;

    for( int i = 1 ; i <= n ; ++i ) update(i, 1);

    int start = 0;
    int cut = k % n + 1, q;
    for( int t = n ; t > 1 ; --t ){
        
        int res = start, step = n;
        while( step > 0 ){
            if( valid(start, res + step, cut) ) res += step;
            else step /= 2;
        }
        res++;

        cout << res << " ";
        update(res, -1);
        
        start = res;
        cut = k % (t-1);
        cut += 1;
        
        if( ( q = sum(start, n) ) < cut ){
            start = 0;
            cut = cut - q;
        }
    }

    for( int i = 1 ; i <= n ; ++i ){
        if( query(i) == 1 ) {
            cout << i << "\n";
            break;
        }
    }
}