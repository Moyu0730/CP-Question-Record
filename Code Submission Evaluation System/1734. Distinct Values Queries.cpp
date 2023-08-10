/* CSES 1734. Distinct Values Queries */

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

#define nL cnt * 2
#define nR cnt * 2 + 1

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 5e5 + 50;
const int Mod = 1e9 + 7;
int n, x, y, k, m, arr[MAXN];
set<int> ans;

struct Node {
    set<int> dist;
} seg[MAXN * 4];

void build( int L, int R, int cnt ){
    if( R == L ){
        seg[cnt].dist.insert(arr[L]);
        return;
    }

    int M = (L + R) / 2;
    build(L, M, nL);
    build(M+1, R, nR);

    for( auto it = seg[nL].dist.begin() ; it != seg[nL].dist.end() ; it++ ) seg[cnt].dist.insert(*it);
    for( auto it = seg[nR].dist.begin() ; it != seg[nR].dist.end() ; it++ ) seg[cnt].dist.insert(*it);
}

void query( int L, int R, int ql, int qr, int cnt ){
    if( R < L || ql > R || qr < L ) return;
    if( ql <= L && qr >= R ){
        for( auto it = seg[cnt].dist.begin() ; it != seg[cnt].dist.end() ; it++ ) ans.insert(*it);
        return;
    }

    int M = (L + R) / 2;
    query(L, M, ql, qr, nL);
    query(M+1, R, ql, qr, nR);
    
}

signed main(){
    opt;
    cin >> n >> m;
    for( int i = 1 ; i <= n ; i++ ) cin >> arr[i];
    build(1, n, 1);

    // for( int i = 1 ; i <= n * 4 ; i++ ) cout << seg[i].dist.size() << " \n"[i==n*4];
    
    while( m-- ){
        int x, y;
        cin >> x >> y;
        ans.clear();
        query(1, n, x, y, 1);
        cout << ans.size() << "\n";
    }
}