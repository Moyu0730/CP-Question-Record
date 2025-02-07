/* Question : CSES 1632. Movie Festival II */

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
const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;
const int MEMINF = 0x3F;
const int MEMINF_VAL = 0x3F3F3F3F;
const int MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int n, k, a, b, res;
vector<pii> mv;
multiset<int> mst;

bool cmp( pii x, pii y ){
    if( x.S == y.S ) return x.F < y.F;
    else return x.S < y.S;
}

signed main(){
    opt;

    cin >> n >> k;
    for( int i = 0 ; i < n ; i++ ){
        cin >> a >> b;
        mv.pb({a, b});
    }
 
    sort(mv.begin(), mv.end(), cmp);

    for( int i = 0 ; i < n ; i++ ){
        if( mst.size() == 0 ){
            mst.insert(mv[i].S);

            res++;
        }else if( mv[i].F >= *mst.begin() ){
            auto it = mst.lower_bound(mv[i].F) != mst.begin() ? prev(mst.lower_bound(mv[i].F)) : mst.begin();
            mst.erase(it);
            mst.insert(mv[i].S);

            res++;
        }else if( mst.size() < k && mv[i].F < *mst.begin() ){
            mst.insert(mv[i].S);

            res++;
        }
    }

    cout << res << "\n";
}