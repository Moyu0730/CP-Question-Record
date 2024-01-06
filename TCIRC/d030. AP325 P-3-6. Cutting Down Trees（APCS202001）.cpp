/* Question : TCIRC d030. AP325 P-3-6. Cutting Down Trees（APCS202001） */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define priq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define F first
#define S second
#define X first
#define Y second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e5 + 50;
const int Mod = 1e9 + 7;
const int INF = 1e9 + 1;
int n, l, c[MAXN], h[MAXN];
queue<int> todo;
pii res; // amt, height

struct {
    int height, center;
    int pre, nxt;
    bool alive;
} tree[MAXN];

bool removeable( int idx ){
    if( idx == 0 || idx == n+1 ) return false;
    if( !tree[idx].alive ) return false;
    if( tree[idx].center - tree[idx].height >= tree[tree[idx].pre].center || 
        tree[idx].center + tree[idx].height <= tree[tree[idx].nxt].center ) return true;

    return false;
}

signed main(){
    opt;
    cin >> n >> l;
    for( int i = 1 ; i <= n ; i++ ) cin >> tree[i].center;
    for( int i = 1 ; i <= n ; i++ ) cin >> tree[i].height;
    for( int i = 1 ; i <= n ; i++ ){
        tree[i].pre = i-1;
        tree[i].nxt = i+1;
        tree[i].alive = true;
    }
    
    tree[0].center = 0, tree[0].height = INF;
    tree[n+1].center = l, tree[n+1].height = INF;

    for( int i = 1 ; i <= n ; i++ ){
        if( removeable(i) ){
            todo.push(i);
        }
    }

    while( !todo.empty() ){
        int cnt = todo.front();
        todo.pop();

        if( removeable(cnt) ){
            tree[cnt].alive = false;
            tree[tree[cnt].pre].nxt = tree[cnt].nxt;
            tree[tree[cnt].nxt].pre = tree[cnt].pre;
            res.F++;
            res.S = max(res.S, tree[cnt].height);
            todo.push(tree[cnt].pre);
            todo.push(tree[cnt].nxt);
        }
    }

    cout << res.F << "\n" << res.S << "\n";
}