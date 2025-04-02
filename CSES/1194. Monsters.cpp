/* Question : CSES 1194. Monsters */

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
const int MAXN = 1e3 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;
const int MEMINF = 0x3F;
const int MEMINF_VAL = 0x3F3F3F3F;
const int MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int n, m;
int dis[MAXN][MAXN], mdis[MAXN][MAXN];
char conv[10];
vector<string> graph;
queue<pii> q, monster;

bool valid( pii x ){
    return x.F >= 0 && x.F < n && x.S >= 0 && x.S < m;
}

string get( pii cnt ){
    string res;

    conv[0] = 'U';
    conv[1] = 'L';
    conv[2] = 'D';
    conv[3] = 'R';
    while( graph[cnt.F][cnt.S] != 'A' ){
        for( int t = 0 ; t < 4 ; ++t ){
            pii nxt = { cnt.F + dir[t].F, cnt.S + dir[t].S };
    
            if( !valid(nxt) ) continue;
            if( graph[nxt.F][nxt.S] == '#' ) continue;
            if( dis[nxt.F][nxt.S] != dis[cnt.F][cnt.S] - 1 ) continue;
    
            res += conv[t];
            cnt = nxt;
            break;
        }
    }
    
    reverse(res.begin(), res.end());
    return res;
}

signed main(){
    opt;

    cin >> n >> m;
    graph.resize(n+5);
    mem(dis, 0x3F);
    mem(mdis, 0x3F);
    for( int i = 0 ; i < n ; ++i ){
        cin >> graph[i];

        for( int j = 0 ; j < graph[i].size() ; ++j ){
            if( graph[i][j] == 'A' ){
                dis[i][j] = 0;
                q.push({i, j});
            }else if( graph[i][j] == 'M' ){
                mdis[i][j] = 0;
                monster.push({i, j});
            }
        }
    }

    while( !monster.empty() ){
        auto cnt = monster.front();
        monster.pop();

        for( int t = 0 ; t < 4 ; ++t ){
            pii nxt = { cnt.F + dir[t].F, cnt.S + dir[t].S };

            if( !valid(nxt) ) continue;
            if( graph[nxt.F][nxt.S] == '#' ) continue;
            if( mdis[nxt.F][nxt.S] <= mdis[cnt.F][cnt.S] + 1 ) continue;

            mdis[nxt.F][nxt.S] = mdis[cnt.F][cnt.S] + 1;
            monster.push(nxt);
        }
    }

    while( !q.empty() ){
        auto cnt = q.front();
        q.pop();

        if( cnt.F == 0 || cnt.F == n - 1 || cnt.S == 0 || cnt.S == m - 1 ){
            string path = get(cnt);

            cout << "YES\n";
            cout << path.size() << "\n";
            cout << path << "\n";
            exit(0);
        }

        for( int t = 0 ; t < 4 ; ++t ){
            pii nxt = { cnt.F + dir[t].F, cnt.S + dir[t].S };

            if( !valid(nxt) ) continue;
            if( graph[nxt.F][nxt.S] == '#' ) continue;
            if( dis[nxt.F][nxt.S] < MEMINF_VAL ) continue;
            if( dis[cnt.F][cnt.S] + 1 >= mdis[nxt.F][nxt.S] ) continue;

            dis[nxt.F][nxt.S] = dis[cnt.F][cnt.S] + 1;
            q.push(nxt);
        }
    }

    cout << "NO\n";
}