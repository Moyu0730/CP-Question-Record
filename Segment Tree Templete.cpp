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

#define nL v*2
#define nR v*2+1

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 5e5 + 50;
const int Mod = 1e9 + 7;
int n, x, y, k, m, arr[MAXN];

struct Node {
    int val = 0, tag = 0, sz;
    int rv(){
        return val + (tag * sz);
    }
} segment_tree[MAXN * 4];

void build( int L, int R, int v ){
    segment_tree[v].sz = R - L + 1;
    if( R == L ){
        segment_tree[v].val = arr[L];
        return;
    }

    int M = (L + R) / 2;
    build(L, M, nL);
    build(M+1, R, nR);
    segment_tree[v].val = segment_tree[nL].val + segment_tree[nR].val;
}

void push( int v ){
    segment_tree[nL].tag += segment_tree[v].tag;
    segment_tree[nR].tag += segment_tree[v].tag;
    segment_tree[v].val = segment_tree[v].rv();
    segment_tree[v].tag = 0;
}

int query( int L, int R, int ql, int qr, int v ){
    if( R < L || ql > R || qr < L ) return 0;
    if( ql <= L && qr >= R ) return segment_tree[v].rv();

    push(v);
    int M = (L + R) / 2;
    return query(L, M, ql, qr, nL) + query(M+1, R, ql, qr, nR);
}

void modify( int L, int R, int ml, int mr, int val, int v ){
    if( R < L || ml > R || mr < L ) return;
    if( ml <= L && mr >= R ){
        segment_tree[v].tag += val;
        return;
    }

    int M = (L + R) / 2;
    modify(L, M, ml, mr, val, nL);
    modify(M+1, R, ml, mr, val, nR);
    segment_tree[v].val = segment_tree[nL].rv() + segment_tree[nR].rv();
}