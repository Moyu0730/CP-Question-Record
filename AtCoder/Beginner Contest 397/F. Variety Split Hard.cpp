/* Question : AtCoder Beginner Contest 397 - F. Variety Split Hard */

#include<bits/stdc++.h>
using namespace std;

/* Pragma */
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

/* Self Define */
#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pirq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define vsort(x) sort(x.begin(), x.end());
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define F first
#define S second
#define X first
#define Y second
#define int long long
#define ll long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 3e5 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;
const int MEMINF = 0x3F;
const int MEMINF_VAL = 0x3F3F3F3F;
const int MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

#define nL x << 1
#define nR x << 1 | 1

int n, res, nxt[MAXN], arr[MAXN], suf[MAXN], pre[MAXN];
bool used[MAXN];

struct Node {
    int val = 0, tag = 0;
} seg[MAXN * 4];

void push( int x ){
    seg[nL].val += seg[x].tag;
    seg[nL].tag += seg[x].tag;
    seg[nR].val += seg[x].tag;
    seg[nR].tag += seg[x].tag;
    seg[x].tag = 0;
    return;
}

void modify( int L, int R, int mL, int mR, int x, int val ){
    if( L > R || mL > R || mR < L ) return;
    if( mL <= L && R <= mR ){
        seg[x].val += val;
        seg[x].tag += val;
        return;
    }

    push(x);
    int M = L + R >> 1;

    modify(L, M, mL, mR, nL, val);
    modify(M+1, R, mL, mR, nR, val);

    seg[x].val = max(seg[nL].val, seg[nR].val);
    return;
}

int query( int L, int R, int qL, int qR, int x ){
    if( L > R || qL > R || qR < L ) return 0;
    if( qL <= L && R <= qR ) return seg[x].val;

    push(x);
    int M = L + R >> 1;

    return max(query(L, M, qL, qR, nL), query(M+1, R, qL, qR, nR));
}

signed main(){
    opt;

    cin >> n;
    
    for( int i = 1 ; i <= n ; ++i ){
        cin >> arr[i];
        pre[i] = pre[i-1] + !used[arr[i]];
        used[arr[i]] = true;
    }

    mem(used, false);
    map<int, int> mp;
    for( int i = n ; i >= 1 ; --i ){
        suf[i] = suf[i+1] + !used[arr[i]];
        
        if( used[arr[i]] ) nxt[i] = mp[arr[i]];
        else nxt[i] = -1;
        
        mp[arr[i]] = i;
        used[arr[i]] = true;
    }

    for( int i = 1 ; i <= n ; ++i ){
        if( nxt[i] != -1 ) modify(1, n, i, nxt[i]-1, 1, 1);
    }

    for( int i = 1 ; i <= n ; ++i ){
        if( nxt[i] != -1 ) modify(1, n, i, nxt[i]-1, 1, -1);

        int q = query(1, n, i+1, n, 1);
        res = max(res, pre[i] + suf[i+1] + q);
    }

    cout << res << "\n";
}