/* Question : AtCoder Beginner Contest 340 - E. Mancala 2 */

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
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
int n, m, c, cnt, tmp, add, a[MAXN], b[MAXN];

#define nL x * 2
#define nR x * 2 + 1

struct STree{
    int val = 0, tag = 0, sz;
    int rv(){
        return val + (tag * sz);
    }
} seg[MAXN * 4];

void build( int L, int R, int x ){
    seg[x].sz = R - L + 1;

    if( L == R ){
        seg[x].val = a[L-1];
        return;
    }

    int M = (L + R) / 2;
    build(L, M, nL);
    build(M+1, R, nR);
    seg[x].val = seg[nL].val + seg[nR].val;
}

void push( int x ){
    seg[nL].tag += seg[x].tag;
    seg[nR].tag += seg[x].tag;
    seg[x].val = seg[x].rv();
    seg[x].tag = 0;
}

int query( int L, int R, int qL, int qR, int x ){
    if( R < L || qL > R || qR < L ) return 0;
    if( qL <= L && qR >= R ) return seg[x].rv();

    push(x);
    int M = (L + R) / 2;
    return query(L, M, qL, qR, nL) + query(M+1, R, qL, qR, nR);
}

void modify( int L, int R, int mL, int mR, int val, int x ){
    if( R < L || mL > R || mR < L ) return;
    if( mL <= L && mR >= R ){
        seg[x].tag += val;
        return;
    }

    int M = (L + R) / 2;
    modify(L, M, mL, mR, val, nL);
    modify(M+1, R, mL, mR, val, nR);
    seg[x].val = seg[nL].rv() + seg[nR].rv();
}

signed main(){
    opt;
    cin >> n >> m;

    for( int i = 0 ; i < n ; i++ ) cin >> a[i];
    for( int i = 0 ; i < m ; i++ ) cin >> b[i];

    build(1, n, 1);

    for( int i = 0 ; i < m ; i++ ){
        b[i]++; // From 0 to N

        cnt = query(1, n, b[i], b[i], 1);

        modify(1, n, b[i], b[i], -1 * cnt, 1);
        
        tmp = cnt % n;
        
        if( cnt >= n ){    
            add = (cnt - tmp) / n;

            modify(1, n, 1, n, add, 1);
        }

        if( b[i] + tmp <= n ){
            modify(1, n, b[i]+1, b[i]+tmp, 1, 1);
        }else{
            int now = b[i] + tmp - n;
            modify(1, n, b[i]+1, n, 1, 1);
            modify(1, n, 1, now, 1, 1);
        }
    }

    for( int i = 1 ; i <= n ; i++ ) cout << query(1, n, i, i, 1) << " ";
}