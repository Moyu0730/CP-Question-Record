/* Question : AtCoder Beginner Contest 400 - D. Takahashi the Wall Breaker */

#include<bits/stdc++.h>
using namespace std;

/* Pragma */
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

/* Self Define */
#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pirq(type) priority_queue<type, vector<type>, greater<type>>
#define tmp pair< int, pii >
#define mem(x, value) memset(x, value, sizeof(x));
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push
#define F first
#define S second
#define X first
#define Y second
#define int long long
#define ll long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e3 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;
const int MEMINF = 0x3F;
const int MEMINF_VAL = 0x3F3F3F3F;
const int MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int n, m;
pii start, finish;
char graph[MAXN][MAXN];
int dis[MAXN][MAXN];
priority_queue<tmp, vector<tmp>, greater<tmp>> q;

signed main(){
    opt;

    cin >> n >> m;
    for( int i = 1 ; i <= n ; ++i ){
        for( int j = 1 ; j <= m ; ++j ) cin >> graph[i][j];
    }

    cin >> start.F >> start.S >> finish.F >> finish.S;

    mem(dis, MEMINF);
    dis[start.F][start.S] = 0;
    q.push({0, start});

    while( !q.empty() ){
        auto [d, cnt] = q.top();
        q.pop();

        for( int t = 0 ; t < 4 ; ++t ){
            pii nxt = { cnt.F + dir[t].F, cnt.S + dir[t].S };

            if( nxt.F <= 0 || nxt.F > n || nxt.S <= 0 || nxt.S > m ) continue;
            
            if( graph[nxt.F][nxt.S] == '#' ){
                if( dis[cnt.F][cnt.S] + 1 < dis[nxt.F][nxt.S] ){
                    dis[nxt.F][nxt.S] = dis[cnt.F][cnt.S] + 1;
                    q.push({dis[nxt.F][nxt.S], nxt});
                }

                nxt = { nxt.F + dir[t].F, nxt.S + dir[t].S };

                if( nxt.F <= 0 || nxt.F > n || nxt.S <= 0 || nxt.S > m ) continue;

                if( dis[cnt.F][cnt.S] + 1 < dis[nxt.F][nxt.S] ){
                    dis[nxt.F][nxt.S] = dis[cnt.F][cnt.S] + 1;
                    q.push({dis[nxt.F][nxt.S], nxt});
                }
            }else{
                if( dis[cnt.F][cnt.S] < dis[nxt.F][nxt.S] ){
                    dis[nxt.F][nxt.S] = dis[cnt.F][cnt.S];
                    q.push({dis[nxt.F][nxt.S], nxt});
                }
            }
        }
    }

    cout << dis[finish.F][finish.S] << "\n";
}