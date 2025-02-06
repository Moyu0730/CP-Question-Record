/* Question : CSES 2428. Subarray Distinct Values */

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

int n, k, arr[MAXN], pre[MAXN], counter[MAXN], tmp[MAXN], before[MAXN]; 
vector<int> distinct;
vector<pii> amt;

signed main(){
    opt;

    cin >> n >> k;

    for( int i = 0 ; i < n ; i++ ){
        cin >> before[i];
        tmp[i] = before[i];
    }

    sort(tmp, tmp + n);

    distinct.pb(tmp[0]);
    for( int i = 1 ; i < n ; i++ ){
        if( tmp[i] != tmp[i-1] ) distinct.pb(tmp[i]);
    }

    for( int i = 0 ; i < n ; i++ ) arr[i] = lower_bound(distinct.begin(), distinct.end(), before[i]) - distinct.begin();

    for( int i = 0 ; i < n ; ++i ){
        if( amt.empty() || amt.back().F != arr[i] ) amt.pb({arr[i], 1});
        else ++amt.back().S;
    }

    for( int i = 0 ; i < amt.size() ; ++i ) pre[i] = (i == 0 ? 0 : pre[i-1]) + amt[i].S;

    int res = 0, different = 0, left = 0;
    for( int right = 0 ; right < amt.size() ; ++right ){
        if( counter[amt[right].F] == 0 && different == k - 1 ){
            ++counter[amt[right].F];
            ++different;

            while( right + 1 < amt.size() && counter[amt[right+1].F] != 0 ){
                ++counter[amt[right+1].F];
                ++right;
            }

            res += amt[left].S + (amt[left].S * (amt[left].S - 1) / 2);
            if( k != 1 ) res += amt[left].S * (pre[right] - pre[left]);

            while( different == k ){
                counter[amt[left].F]--;
                if( counter[amt[left].F] == 0 ) --different;

                ++left;

                if( different == k ){
                    res += amt[left].S + (amt[left].S * (amt[left].S - 1) / 2);
                    if( k != 1 ) res += amt[left].S * (pre[right] - pre[left]);  
                }
            }
        }else{
            if( counter[amt[right].F] == 0 ) ++different;

            ++counter[amt[right].F];
        }

        if( right == amt.size() - 1 ){
            for( int i = left ; i < amt.size() ; ++i ){
                res += amt[i].S + (amt[i].S * (amt[i].S - 1) / 2);
                if( k != 1 ) res += amt[i].S * (pre[right] - pre[i]);
            }

            break;
        }
    }

    cout << res << "\n";
}