/* Question : CSES 1639. Edit distance */
 
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
#define sortV(x) sort(x.begin(), x.end());
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
const int MAXN = 5e3 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;
const int MEMINF = 0x3F;
const int MEMINF_VAL = 0x3F3F3F3F;
const int MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;
 
string a, b;
int dp[MAXN][MAXN];
 
signed main(){
	opt;
		
	cin >> a >> b;

	for( int i = 0 ; i <= a.size() ; ++i ){
		for( int j = 0 ; j <= b.size() ; ++j ){
			if( i == 0 || j == 0 ) dp[i][j] = max(i, j);
			else dp[i][j] = a[i-1] == b[j-1] ? dp[i-1][j-1] : min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
		}
	}
1
	cout << dp[a.size()][b.size()] << "\n";
}