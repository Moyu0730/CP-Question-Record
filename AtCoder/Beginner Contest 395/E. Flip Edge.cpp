/* Question : AtCoder Beginner Contest 395 - E. Flip Edge */

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

int n, m, x, u, v;
vector<vector<int>> A, B;
priority_queue< pair<int, pair<int, char> >, vector< pair<int, pair<int, char> > >, greater< pair<int, pair<int, char> > > > pq;

signed main(){
    opt;

    cin >> n >> m >> x;

    A.resize(n + 5);
    B.resize(n + 5);
    for( int i = 0 ; i < m ; ++i ){
        cin >> u >> v;

        A[u].pb(v);
        B[v].pb(u);
    }

    map<pair<int ,char>, int> mp;
    pq.push({0, {1, 'A'}});

    while( !pq.empty() ){
        auto [cost, data] = pq.top();
        auto [cnt, graph] = data;
        pq.pop();

        if( cnt == n ){
            cout << cost << "\n";
            break;
        }

        if( mp.find(data) != mp.end() && mp[{cnt, graph}] <= cost ) continue;

        if( graph == 'A' ){
            for( auto nxt : A[cnt] ){
                pq.push({cost+1, {nxt, 'A'}});
            }
            pq.push({cost + x, {cnt, 'B'}});
        }else{
            for( auto nxt : B[cnt] ){
                pq.push({cost+1, {nxt, 'B'}});
            }
            pq.push({cost + x, {cnt, 'A'}});
        }
        
        mp[data] = cost;
    }
}