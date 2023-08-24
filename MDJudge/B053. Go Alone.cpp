/* Question : MDJudge B053. Go Alone */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pirq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(array, value) memset(array, value, sizeof(array));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define f first
#define s second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 400 + 50;
const int Mod = 1e9 + 7;
int n, q, stq, tp, a, b, dis, tmp, cnt, graph[MAXN][MAXN];
vector<pii> ready;
queue< pair<pii, int> > que;

void bfs(){
    while( !ready.empty() ){
        pii temp = ready.back();
        graph[temp.f][temp.s] = 0;
        que.push( { temp, 0 } );
        ready.pop_back();
    }

    while( !que.empty() ){
        pii p = que.front().f;
        int d = que.front().s;
        que.pop();

        for( int t = 0 ; t < 4 ; t++ ){
            int x = p.f + dir[t].f;
            int y = p.s + dir[t].s;

            if( d+1 >= graph[x][y] ) continue;
            if( x > n || x <= 0 || y > n || y <= 0 ) continue;
            
            graph[x][y] = d+1;
            que.push({{x, y}, d+1});
        }
    }
}

signed main(){
    opt;
    cin >> n >> q;
    stq = sqrt(q);
    mem(graph, 0x3F);
    for( int i = 0 ; i < q ; i++ ){
        if( i == stq + 1 ){
            stq += sqrt(q);
            bfs();
        }
        cin >> tp >> a >> b;
        if( tp == 1 ){
            ready.pb({a, b});
        }else if( tp == 2 ){
            dis = graph[a][b];
            for( auto i : ready ){
                tmp = abs( a - i.f ) + abs( b - i.s );
                dis = min( dis, tmp );
            }

            if( graph[a][b] == 4557430888798830399 && ready.size() == 0 ) dis = -1;
            cout << dis << "\n";
        }
    }
}