/* Question : CSES 1644. Maximum Subarray Sum II */
 
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
 
int n, a, b, res;
int arr[MAXN], pre[MAXN];
multiset<pii> st;
 
signed main(){
    opt;
    cin >> n >> a >> b;
    
    for( int i = 1 ; i <= n ; i++ ){
    	cin >> arr[i];
    	pre[i] = pre[i-1] + arr[i];
	}
	
	res = -1 * LLINF;
	for( int i = 1 ; i <= n ; i++ ){
        if( i + a - 1 > n ) break;

		if( i == 1 ) for( int it = a ; it <= b ; it++ ) st.insert({pre[it], it});
		else{
			st.erase({pre[i+a-1-1], i+a-1-1});
			if( i + b - 1 <= n ) st.insert({pre[i+b-1], i+b-1});
		}
		
		res = max(res, (*st.rbegin()).F - pre[i-1]);
	}
	
	cout << res << "\n";
}