/* Question : AtCoder Beginner Contest 340 - C. Divide and Divide */

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
const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
int x;
map<int, int> mp;

int solve( int val ){
    if( val == 1 ) return 0;
    if( mp.find(val) != mp.end() ) return mp[val];
    return mp[val] = solve(val/2) + solve((val+1)/2) + val;
}

signed main(){
    opt;
    cin >> x;
    cout << solve(x) << " ";
}