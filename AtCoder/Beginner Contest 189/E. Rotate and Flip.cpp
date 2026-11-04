/* Question : AtCoder Beginner Contest 189 - E. Rotate and Flip */

#include<bits/stdc++.h>
using namespace std;

/* Pragma */
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

/* Self Define */
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MEM(_A, _V) memset(_A, _V, sizeof(_A))
#define ALL(_A) _A.begin(), _A.end()
#define LB(_A, _V) lower_bound(ALL(_A), _V)
#define UB(_A, _V) upper_bound(ALL(_A), _V)
#define pii pair<int, int>
#define sz size()
#define cr clear()
#define as assign
#define rz resize
#define pb push_back
#define F first
#define S second
#define int long long
#define tpn typename

/* Self Define Template Function */
template<tpn T> void pV( vector<T> _A ){
    for( auto _I : _A ) cout << _I << " ";
    cout << "\n";
}

template<tpn A, tpn B> ostream& operator<<( ostream& _OS, pair<A, B> _P ){
    return _OS << "(" << _P.F << ", " << _P.S << ")";
}

/* Self Define Const */
const auto dir = vector<pii> { {1, 0}, {0, 1},  {-1, 0}, {0, -1},
                               {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
const int     MAXN = 1e7 + 50;
const int      Mod = 1e18 + 7;
const int      INF = 0x7FFFFFFF;
const int    LLINF = 0x7FFFFFFFFFFFFFFF;
const int MEMLLINF = 0x3F3F3F3F3F3F3F3F;

int n, m, q;
vector<pii> node, op;
vector<vector<int>> op1 = { {0,  1,  0},
							{-1, 0,  0},
							{0,  0,  1} };
vector<vector<int>> op2 = { {0, -1,  0},
							{1,  0,  0},
							{0,  0,  1} };
vector<vector<int>> op3 = { {-1, 0,  1},
							{0,  1,  0},
							{0,  0,  1} };
vector<vector<int>> op4 = { {1,  0,  0},
							{0, -1,  1},
							{0,  0,  1} };
vector<vector<int>> ori = { {1, 0, 0},
							{0, 1, 0},
							{0, 0, 1} };
vector<vector<vector<int>>> pre;

template<tpn T> vector<vector<T>> mat( const vector<vector<T>> &x, const vector<vector<T>> &y ){
    int p = x.sz, q = y.sz, r = y[0].sz;
    vector<vector<T>> res(p, vector<T>(r, 0));
    for( int i = 0 ; i < p ; i++ ){
        for( int k = 0 ; k < q ; k++ ){
            for( int j = 0 ; j < r ; j++ ){
                res[i][j] += x[i][k] * y[k][j] % Mod;
                res[i][j] %= Mod;
            }
        }
    }
    return res;
}

inline void solve(){
    cin >> n;
	
	node.rz(n);
	for( int i = 0 ; i < n ; ++i ){
		cin >> node[i].F >> node[i].S;
	}
	
	cin >> m;
	
	op.rz(m);
	for( int i = 0 ; i < m ; ++i ){
		cin >> op[i].F;
		
		if( op[i].F >= 3 ) cin >> op[i].S;
	}
	
	pre.rz(m + 1);
	pre[0] = ori;
	for( int i = 0 ; i < m ; ++i ){
		if( op[i].F == 1 ) ori = mat(op1, ori);
		if( op[i].F == 2 ) ori = mat(op2, ori);
		if( op[i].F == 3 ){
			op3[0][2] = 2 * op[i].S;
			ori = mat(op3, ori);
		}
		if( op[i].F == 4 ){
			op4[1][2] = 2 * op[i].S;
			ori = mat(op4, ori);
		}
		
		pre[i+1] = ori;
	}
	
	cin >> q;
	
	int a, b;
	vector<vector<int>> arr = { {1},
								{1},
								{1} };
	for( int i = 0 ; i < q ; ++i ){
		cin >> a >> b;
		
		--b;
		arr[0][0] = node[b].F;
		arr[1][0] = node[b].S;
		arr[2][0] = 1;
		
		arr = mat(pre[a], arr);
		
		cout << arr[0][0] << " " << arr[1][0] << "\n";
	}
}

signed main(){
    IO;

    int T = 1;
    // cin >> T;
    while( T-- ){
        solve();
    }
}