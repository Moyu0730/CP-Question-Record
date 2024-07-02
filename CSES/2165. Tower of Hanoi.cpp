/* Question : CSES 2165. Tower of Hanoi */

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
int n, cnt, start[MAXN], target[MAXN];

void solve( int n, int from, int to, int sup ){
    if( n == 1 ){
        start[cnt] = from;
        target[cnt] = to;
        cnt++;

        return;
    }

    solve(n-1, from, sup, to);
    solve(1, from, to, sup);
    solve(n-1, sup, to, from);
}

signed main(){
    opt;
    cin >> n;

    solve(n, 1, 3, 2);

    cout << cnt << "\n";
    for( int i = 0 ; i < cnt ; i++ ) cout << start[i] << " " << target[i] << "\n";
}