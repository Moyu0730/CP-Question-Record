/* Question : CSES 1091. Concert Tickets */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define f first
#define s second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e7 + 50;
const int Mod = 1e9 + 7;
int n, m, h, t;
multiset<int> tickets;

signed main() {
	opt;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> h;
		tickets.insert(h);
	}
	for (int i = 0; i < m; ++i) {
		cin >> t;
		auto it = tickets.upper_bound(t);
		if (it == tickets.begin()) {
			cout << -1 << "\n";
		} else {
			cout << *(--it) << "\n";
			tickets.erase(it);
		}
	}
}