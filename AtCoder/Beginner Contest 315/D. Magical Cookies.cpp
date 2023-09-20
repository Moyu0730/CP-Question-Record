// /* Question : AtCoder Beginner Contest 315 - D - Magical Cookies */

// #include<bits/stdc++.h>
// using namespace std;

// #define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
// #define pirq(type) priority_queue<type, vector<type>, greater<type>>
// #define mem(x, value) memset(x, value, sizeof(x));
// #define pii pair<int, int>
// #define pdd pair<double, double>
// #define pb push_back
// #define f first
// #define s second
// #define int long long

// const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
// const int MAXN = 2e3 + 50;
// const int Mod = 1e9 + 7;
// int h, w, res, cl, cr, row[MAXN][200], col[MAXN][200];
// char graph[MAXN][MAXN];

// signed main(){
//     // opt;
//     cin >> h >> w;
//     for( int i = 0 ; i < h ; i++ ){
//         for( int j = 0 ; j < w ; j++ ){
//             cin >> graph[i][j];
//             row[i][graph[i][j] - 'a']++;
//             col[j][graph[i][j] - 'a']++;
//         }
//     }
    
//     int amt = 1;
//     while( amt != 0 ){
//         cout << amt << "\t";
//         int l;
//         amt = 0;

//         // Row
//         for( int i = 0 ; i < h ; i++ ){

//             l = -1;
//             for( int t = 0 ; t < 26 ; t++ ){
//                 if( row[i][t] >= 2 ){
//                     if( l == -1 ) l = t;
//                     else l = -1; break;
//                 }else if( row[i][t] == 1 ){
//                     l = -1; break;
//                 }
//             }

//             if( l != -1 ){
//                 amt++;
//                 for( int j = 0 ; j < w ; j++ ) graph[i][j] = '.';
//             }
//         }

//         // Col
//         for( int j = 0 ; j < w ; j++ ){

//             l = -1;
//             for( int t = 0 ; t < 26 ; t++ ){
//                 if( col[j][t] >= 2 ){
//                     if( l == -1 ) l = t;
//                     else l = -1; break;
//                 }else if( col[j][t] == 1 ){
//                     l = -1; break;
//                 }
//             }

//             if( l != -1 ){
//                 amt++;
//                 for( int i = 0 ; i < h ; i++ ) graph[i][j] = '.';
//             }
//         }
//     }

//     res = 0;
//     for( int i = 0 ; i < h ; i++ ){
//         for( int t = 0 ; t < 26 ; t++ ) res += max( (long long)0, row[i][t] );
//     }

//     cout << "\n";
//     for( int i = 0 ; i < h ; i++ ){
//         for( int t = 0 ; t < 26 ; t++ ) cout << row[i][t] << " ";
//         cout << "\n";
//     }
//     cout << "\n";

//     for( int j = 0 ; j < w ; j++ ){
//         for( int t = 0 ; t < 26 ; t++ ) cout << col[j][t] << " ";
//         cout << "\n";
//     }

//     for( int i = 0 ; i < h ; i++ ){
//         for( int j = 0 ; j < w ; j++ ){
//             cout << graph[i][j];
//         }
//         cout << "\n";
//     }

//     cout << res << "\n";
// }


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define V vector
#define sz(a) ((int)a.size())
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define rsz resize
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second

#define FOR(i,j,k) for (int i=(j); i<=(k); i++)
#define F0R(i,j,k) for (int i=(j); i<(k); i++)
#define REP(i) FOR(_,1,i)
#define foreach(a,x) for (auto& a: x)


template<class T> bool cmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; } // set a = min(a,b)
template<class T> bool cmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; } // set a = max(a,b)

ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); }
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); }

#define roadroller ios::sync_with_stdio(0), cin.tie(0);
#define de(x) cerr << #x << '=' << x << ", "
#define dd cerr << '\n';

signed main() {
	int n, m; cin >> n >> m;
	V<string> a(n);
	F0R(i,0,n) cin >> a[i];

	V<vi> rcnt(n, vi(128)), ccnt(m, vi(128));
	V<V<vi>> rpos(n, V<vi>(128, vi())), cpos(m, V<vi>(128, vi()));

	F0R(i,0,n){
		F0R(j,0,m){
			auto c = a[i][j];
			rcnt[i][c]++, ccnt[j][c]++;
			rpos[i][c].pb(j);
			cpos[j][c].pb(i);
		}
	}	
    
	auto ckrow = [&](int i){
		int ans = 0;
		FOR(j,'a','z'){
			if (rcnt[i][j] > 0){
				if (!ans) ans = j;
				else return 0;
			}
		}
		if (rcnt[i][ans] <= 1) return 0;
		return ans;
	};
	auto ckcol = [&](int i) {
		int ans = 0;
		FOR(j,'a','z'){
			if (ccnt[i][j] > 0){
				if (!ans) ans = j;
				else return 0;
			}
		}
		if (ccnt[i][ans] <= 1) return 0;
		return ans;
	};

	while(1){
		int flag = 0;
		V<pair<int, char>> drow;
		F0R(i,0,n){
			char x = ckrow(i);
			if (x){
				drow.pb(mp(i, x));
				flag = 1;
			}
		}
		F0R(j,0,m){
			char x = ckcol(j);
			if (x){
				flag = 1;
				foreach(p, cpos[j][x]){
					rcnt[p][x]--;
				}
				ccnt[j][x] = 0;
			}
		}
		foreach(r,drow){
			auto [i, x] = r;
			foreach(p, rpos[i][x]) ccnt[p][x]--;
			rcnt[i][x] = 0;
		}
		if (!flag) break;
	}
	int ans = 0;
	F0R(i,0,n){
		FOR(c,'a','z'){
			ans += rcnt[i][c] * (rcnt[i][c]>0);
		}
	}
	cout << ans << '\n';
}