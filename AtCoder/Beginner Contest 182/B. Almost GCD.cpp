/* Question : AtCoder Beginner Contest 182 - B - Almost GCD */

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
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 18 + 50;
const int Mod = 1e9 + 7;
int n, tmp, sum, res = 20;
vector<int> v;
bool used[MAXN];

void dfs( int cnt, int amt ){
    if( amt == (int)v.size() ) return;

    if( cnt % 3 == 0 ){
        res = min(res, amt);
        return;
    }

    for( int i = 0 ; i < (int)v.size() ; i++ ){
        if( used[i] == true ) continue;

        used[i] = true;
        dfs(cnt - v[i], amt+1);
        used[i] = false;
    }

    return;
}

signed main(){
    cin >> n;

    tmp = n;
    while( tmp > 0 ){
        v.pb(tmp % 10);
        sum += tmp % 10;
        tmp /= 10;
    }

    dfs(sum, 0);

    if( res == 20 ) cout << -1 << "\n";
    else cout << res << "\n";
}