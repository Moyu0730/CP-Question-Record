/* Question : CF 【2023 MD Player Training】 Simulation Contest 1 - A. Fivesteps */

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
const int MAXN = 40 + 50;
const int Mod = 1e9 + 7;
int n, x, res, arr[MAXN];
map<int, int> mp;

void f1( int cnt, int amt, int sum ){
    if( cnt == amt + 1 ){
        mp[sum]++;
        return;
    }

    f1(cnt+1, amt, sum + arr[cnt]);
    f1(cnt+1, amt, sum - arr[cnt]);
}

void f2( int cnt, int amt, int sum, int tar ){
    if( cnt == amt + 1 ){
        res += mp[tar-sum];
        return;
    }

    f2(cnt+1, amt, sum+arr[cnt], tar);
    f2(cnt+1, amt, sum-arr[cnt], tar);
}

signed main(){
    opt;
    cin >> n >> x;
    for( int i = 1 ; i <= n ; i++ ) cin >> arr[i];

    f1(1, n/2, 0);
    f2(n/2+1, n, 0, x);

    cout << res << "\n";
}