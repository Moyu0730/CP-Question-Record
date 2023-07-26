/* Question : AtCoder Beginner Contest 100 - D - Patisserie ABC */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define f first
#define s second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e3 + 50;
const int Mod = 1e9 + 7;
int n, m, b, t, p, res, cake[MAXN][3+5];
vector<vector<int>> ans;

void Enumerate( int k, int cnt ){
    if( k == 0 ){
        res = max(res, abs(b) + abs(t) + abs(p));
        return;
    }
    if( cnt >= n ) return;

    Enumerate(k, cnt+1);

    ans.push_back({cake[cnt][0], cake[cnt][1], cake[cnt][2]});
    b += cake[cnt][0];
    t += cake[cnt][1];
    p += cake[cnt][2];

    Enumerate(k-1, cnt+1);
    
    ans.pop_back();
    b -= cake[cnt][0];
    t -= cake[cnt][1];
    p -= cake[cnt][2];

    return;
}

signed main(){
    opt;
    cin >> n >> m;
    for( int i = 0 ; i < n ; i++ ) cin >> cake[i][0] >> cake[i][1] >> cake[i][2];

    res = -1;
    Enumerate(m, 0);

    cout << res;
}