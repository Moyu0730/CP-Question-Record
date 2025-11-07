/* Question : AtCoder Beginner Contest 119 - C - Synthetic Kadomatsu */

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

const int MAXN = 8 + 50;
const int Mod = 1e9 + 7;
int n, a, b, c, res, arr[MAXN];
vector<vector<int>> ans;

void Enu( int cnt ){
    if( cnt == n+1 ){
        int sum, tmp;
        tmp = 0;

        if( ans[0].size() == 0 ) return;
        if( ans[1].size() == 0 ) return;
        if( ans[2].size() == 0 ) return;

        sum = 0;
        for( auto i : ans[0] ) sum += i;
        tmp += 10 * (ans[0].size()-1) + abs(sum-a);

        sum = 0;
        for( auto i : ans[1] ) sum += i;
        tmp += 10 * (ans[1].size()-1) + abs(sum-b);

        sum = 0;
        for( auto i : ans[2] ) sum += i;
        tmp += 10 * (ans[2].size()-1) + abs(sum-c);

        res = min(res, tmp);
        return;
    }

    ans[0].pb(arr[cnt]);
    Enu(cnt+1);
    ans[0].pop_back();

    ans[1].pb(arr[cnt]);
    Enu(cnt+1);
    ans[1].pop_back();

    ans[2].pb(arr[cnt]);
    Enu(cnt+1);
    ans[2].pop_back();

    Enu(cnt+1);
}

signed main(){
    opt;
    cin >> n >> a >> b >> c;
    ans.resize(3);
    for( int i = 1; i <= n ; i++ ) cin >> arr[i];

    res = 1e9;
    Enu(1);

    cout << res << "\n";
}