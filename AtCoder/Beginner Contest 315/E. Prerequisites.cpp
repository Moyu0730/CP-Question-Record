/* Question : AtCoder Beginner Contest 315 - E - Prerequisites */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pirq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define f first
#define s second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
int n, m, b;
vector<vector<int>> v;
vector<int> res;
bool used[MAXN];

void dfs( int t ){
    if( used[t] == true ) return;

    for( auto i : v[t] ){
        if( used[i] == true ) continue;
        
        dfs(i);
        res.pb(i);
        used[i] = true;
    }
    return;
}

signed main(){
    opt;
    cin >> n;
    v.resize(n+1);
    for( int i = 0 ; i < n ; i++ ){
        cin >> m;
        for( int j = 0 ; j < m ; j++ ) cin >> b, v[i+1].pb(b);
    }

    dfs(1);

    for ( auto i : res ) cout << i << " ";
    cout << "\n";
}