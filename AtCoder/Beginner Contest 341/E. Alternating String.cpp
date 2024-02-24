/* Question : AtCoder Beginner Contest 341 - E. Alternating String */

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

#define nL cnt * 2
#define nR cnt * 2 + 1

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 5e5 + 50;
const int Mod = 1e9 + 7;
const int INF = 1e9;
int n, q, tp, a, b, seg[MAXN * 4];
string s;

void build( int L, int R, int cnt ){
    if( R < L ) return;
    if( L == R ){
        seg[cnt] = s[L-1] == s[L] ? 0 : 1;
        return;
    }

    int M = (L + R) / 2;
    build(L, M, nL);
    build(M+1, R, nR);
    seg[cnt] = seg[nL] + seg[nR];
}

void modify( int L, int R, int mL, int mR, int cnt ){
    if( R < L || mL > R || mR < L ) return;
    if( mL <= L && mR >= R ){
        seg[cnt] = seg[cnt] == 1 ? 0 : 1;
        return;
    }

    int M = (L + R) / 2;
    modify(L, M, mL, mR, nL);
    modify(M+1, R, mL, mR, nR);
    seg[cnt] = seg[nL] + seg[nR];
}

int query( int L, int R, int qL, int qR, int cnt ){
    if( R < L || qL > R || qR < L ) return 0;
    if( qL <= L && qR >= R ){
        return seg[cnt];
    }

    int M = (L + R) / 2;
    return query(L, M, qL, qR, nL) + query(M+1, R, qL, qR, nR);
}

signed main(){
    opt;
    cin >> n >> q >> s;

    build(1, n-1, 1);

    while( q-- ){
        cin >> tp >> a >> b;

        if( tp == 1 ){
            if( a != 1 ) modify(1, n-1, a-1, a-1, 1);
            if( b != n ) modify(1, n-1, b, b, 1);
        }else{
            int res = query(1, n-1, a, b-1, 1);
            if( res == b - a ) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}