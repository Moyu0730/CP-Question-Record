/* Question : OJ Number */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define priq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define f first
#define s second

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e6 + 50;
const int Mod = 1e9 + 7;
int n, e, a, b, r;
double tmp;
bool visited[MAXN];
vector<vector<pair<int, double>>> graph;
vector<priority_queue<pair<int, double>>> input;

void dfs( int cnt, double val ){
    if( cnt == 2 ){
        input[1].push({2, val});
        return;
    }

    for( auto i : graph[cnt] ){
        int nxt = i.f;
        double w = i.s;

        if( visited[nxt] == true ) continue;

        visited[nxt] = true;
        dfs(nxt, val + w);
        visited[nxt] = false;
    }
}

void predealt(){
    for( int i = 1 ; i <= n ; i++ ){
        if( i == 2 ) continue;
        while( !input[i].empty() ){
            int now = input[i].top().f;

            if( i == 1 && now == 2 ) break;

            tmp = 0;
            while( input[i].top().f == now ){
                if( input[i].empty() == true ) break;
                tmp += ((double)1 / input[i].top().s);
                input[i].pop();
            }

            graph[i].pb({now, ((double)1 / tmp)});
        }
    }
    return;
}

signed main(){
    // opt;
    cin >> n >> e;
    graph.resize(n+5);
    input.resize(n+5);
    for( int i = 0 ; i < e ; i++ ){
        cin >> a >> b >> r;

        if( a == b ) continue;
        input[a].push({b, r});
    }

    predealt();

    visited[1] = true;
    dfs(1, 0);

    double res = 0;
    while( !input[1].empty() ){
        res += ((double)1 / input[1].top().s);
        input[1].pop();
    }

    cout << setprecision(15) << (double)1 / res << "\n";
}