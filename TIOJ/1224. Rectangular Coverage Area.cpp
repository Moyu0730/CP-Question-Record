/* Question : TIOJ 1224. Rectangular Coverage Area */

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

#define nL cnt * 2
#define nR cnt * 2 + 1

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e6 + 50;
const int Mod = 1e9 + 7;
int n, l, r, d, u, res, seg[MAXN*4], lazy[MAXN*4];
vector<tuple<int, int, int, int>> side;

void dealt( int cnt, int L, int R ){
    if( lazy[cnt] ) seg[cnt] = R - L + 1;
    else if( L != R ) seg[cnt] = seg[nL] + seg[nR];
    else seg[cnt] = 0;
}

void update( int L, int R, int ul, int ur, int dt, int cnt ){
    if( ul <= L && R <= ur ){
        lazy[cnt] += dt;
        dealt(cnt, L, R);
        return;
    }

    int M = ( L + R ) / 2;

    if (ul <= M) update(L, M, ul, ur, dt, nL);
    if (M < ur) update(M+1, R, ul, ur, dt, nR);

    dealt(cnt, L, R);
}

signed main(){
    opt;
    cin >> n;
    for( int i = 0 ; i < n ; i++ ){
        cin >> l >> r >> d >> u;
        side.pb({l, d+1, u, 1});
        side.pb({r, d+1, u, -1});
    }

    sort(side.begin(), side.end());
    
    int pre = 0;
    long long ans = 0;
    
    for( auto [pos, d, u, dif] : side ){
        if( pos != pre ){
            ans += 1LL * ( pos - pre ) * seg[1];
            pre = pos;
        }
        
        update(1, 1000000, d, u, dif, 1);
    }

    cout << ans << "\n";
}