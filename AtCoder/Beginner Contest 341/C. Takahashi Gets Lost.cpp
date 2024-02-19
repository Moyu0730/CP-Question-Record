/* Question : AtCoder Beginner Contest 341 - C. Takahashi Gets Lost */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
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
const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
const int INF = 1e9;
int h, w, n, res;
string t;
pii mov, cnt;
vector<string> graph;
map<char, pii> mp;
queue<pii> q;

signed main(){
    opt;
    cin >> h >> w >> n >> t;

    graph.resize(h+5);
    for( int i = 0 ; i < h ; i++ ){
        cin >> graph[i];
        for( int j = 0 ; j < w ; j++ ){
            if( graph[i][j] == '.' ) q.push({i, j});
        }
    }

    mp['L'] = {0, -1};
    mp['R'] = {0, 1};
    mp['U'] = {-1, 0};
    mp['D'] = {1, 0};

    while( !q.empty() ){
        cnt = q.front();
        q.pop();

        for( int k = 0 ; k < n ; k++ ){
            mov = mp[t[k]];
            
            if( graph[cnt.F][cnt.S] == '#' ) break;
            
            cnt = {cnt.F + mov.F, cnt.S + mov.S};

            if( k == n - 1 && graph[cnt.F][cnt.S] != '#'  ) res++;
        }
    }

    cout << res << "\n";
}