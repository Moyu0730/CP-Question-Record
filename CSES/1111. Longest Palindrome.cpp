/* Question : CSES 1111. Longest Palindrome */

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
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 2e6 + 50;
const int Mod = 1e9 + 7;
 
int n, l, r, st, ed, p = 13331, f1[MAXN], f2[MAXN], ksm[MAXN];
char charr[MAXN];
string str;

void pre(){
	ksm[0] = 1;
	for(int i = 1; i <= n; i++) {
		f1[i] = f1[i - 1] * p % Mod + ( charr[i] - 'a' );
		ksm[i] = ksm[i - 1] * p % Mod;
	}

	for(int i = n; i >= 1; i-- ) {
		f2[i] = f2[i + 1] * p % Mod + ( charr[i] - 'a' );
	}
}
 
bool check( int len ) {
	for(int i = len * 2 ; i <= n ; i++) {
		int m = i - len, l = i - len * 2;
		int pQ = ( ( f1[i] - f1[m] * ksm[len] % Mod ) % Mod + Mod ) % Mod;
		int nQ = ( ( f2[l + 1] - f2[m + 1] * ksm[len] % Mod ) % Mod + Mod ) % Mod;
		if( pQ == nQ ) {
			if( i - l < ed - st + 1 ) return 1;

			st = l + 1;
			ed = i;
			return 1;
		}
	}
	return 0;	
}
 
bool check2( int len ) {
	for(int i = len * 2 + 1 ; i <= n ; i++) {
		int m = i - len, l = i - len * 2;
		int pQ = ( ( f1[i] - f1[m] * ksm[len] % Mod ) % Mod + Mod ) % Mod;
		int nQ = ( ( f2[l] - f2[m] * ksm[len] % Mod ) % Mod + Mod ) % Mod;
		if( pQ == nQ ) {
			if( len * 2 + 1 > ( ed - st + 1 ) ) {
				ed = i;
				st = l;
			}
			return 1;
		}
	}
	return 0;
}
 
signed main() {
	cin >> str;
	for( int i = 1 ; i <= str.size() ; i++ ) charr[i] = str[i-1];
	n = str.size();
    st = ed = 1;
	pre();

	// Include Middle
	int l = 1, r = ( n + 1 ) / 2;
	while(l <= r) {
		int mid = l + r >> 1;
		if( check(mid) ) l = mid + 1;
		else r = mid - 1;
	}

	// Get The Final Pos
	for(int i = ( ed - st + 1 ) ; i <= n ; i++ ) if( !check(i) ) break;
	
	// Exclude Middle
	l = 1, r = ( n + 1 ) / 2;
	while(l < r) {
		int mid = l + r >> 1;
		if( check2(mid) ) l = mid + 1;
		else r = mid;
	}

	// Get the Final Pos
	for( int i = ( ed - st + 1 ) ; i <= n ; i++) if( !check2(i) ) break;

	for( int i = st ; i <= ed ; i++ ) cout << charr[i];
}