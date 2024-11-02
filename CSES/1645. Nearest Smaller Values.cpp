/* Question : CSES 1645. Nearest Smaller Values */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pirq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
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
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;

int n, arr[MAXN], cop[MAXN], disc[MAXN], SEG[MAXN * 4];;

#define nL v * 2
#define nR v * 2 + 1

int query( int L, int R, int qL, int qR, int v ){
    if( R < L || qL > R || qR < L ) return 0;
    if( qL <= L && R <= qR ) return SEG[v];

    int M = (L + R) / 2;
    return max( query(L, M, qL, qR, nL), query(M+1, R, qL, qR, nR) );
}

void modify( int L, int R, int mL, int mR, int val, int v ){
    if( R < L || mL > R || mR < L ) return;
    if( mL <= L && R <= mR ){
        SEG[v] = val;
        return;
    }

    int M = (L + R) / 2;
    modify(L, M, mL, mR, val, nL);
    modify(M+1, R, mL, mR, val, nR);
    SEG[v] = max( SEG[nL], SEG[nR] );
}

signed main(){
    opt;
    cin >> n;
    for( int i = 1 ; i <= n ; i++ ){
        cin >> arr[i];
        cop[i] = arr[i];
    }
    
    sort(cop + 1, cop + n + 1);
    
    disc[1] = cop[1];
    int len = 2;
    for( int i = 2 ; i <= n ; i++ ){
        if( cop[i] != cop[i-1] ) disc[len++] = cop[i];
    }

    for( int i = 1 ; i <= n ; i++ ) arr[i] = lower_bound( disc + 1, disc + len, arr[i] ) - disc;

    for( int i = 1 ; i <= n ; i++ ){
        cout << query(1, n, 1, arr[i]-1, 1) << " ";
        modify(1, n, arr[i], arr[i], i, 1);
    }
    cout << "\n";
}