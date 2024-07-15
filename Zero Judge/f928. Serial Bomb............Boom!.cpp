/* Question : ZeroJudge f928. Serial Bomb............Boom! */

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
const int MAXN = 1e3 + 50;
const int Mod = 1e9 + 7;
const int INF = 1e9;

int n, cnt, state[MAXN];

void bomb( int pos ){
    int x = state[pos];
    state[pos] = 0;

    if( x == 2 ){
        if( pos + 1 < n && state[pos + 1] ) bomb(pos + 1);
        if( pos != 0 && state[pos - 1] ) bomb(pos - 1);
    }else if( x >= 3 ){
        if( pos + x < n && state[pos + x] ) bomb(pos + x);
        if( pos + 2 * x < n && state[pos + 2 * x] ) bomb(pos + 2 * x);
        if( pos >= x && state[pos - x] ) bomb(pos - x);
        if( pos >= 2 * x && state[pos - 2 * x] ) bomb(pos - 2 * x);
    }

    return;
}

signed main(){
    opt;

    cin >> n;
    for( int i = 0 ; i < n ; i++ ) cin >> state[i];

    cin >> cnt;
    bomb(cnt);

    for( int i = 0 ; i < n ; i++ ) cout << state[i] << " \n"[i==n-1];
}