/* Question : AtCoder Beginner Contest 368 - G. Add and Multiply Queries */

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

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
const int LLINF = 1e18;
const int INF = 1e9;

int n, q, t, x, y, res, a[MAXN], b[MAXN], BIT[MAXN];
set<int> st;

int lowbit( int x ){
    return x & -x;
}

int query( int pos ){
    if( pos <= 0 ) return 0;

    int ans = 0;
    while( pos ){
        ans += BIT[pos];
        pos -= lowbit(pos);
    }

    return ans;
}

void update( int x, int val ){
    while( x <= n ){
        BIT[x] += val;
        x += lowbit(x);
    }
}

int sum( int l, int r ){
    if( l > r ) return 0;
    return query(r) - query(l - 1);
}

signed main(){
    #ifndef LOCAL
        opt;
    #endif

    cin >> n;
    for( int i = 1 ; i <= n ; i++ ){
        cin >> a[i];
        update(i, a[i]);
    }
    for( int i = 1 ; i <= n ; i++ ){
        cin >> b[i];
        if( b[i] > 1 ) st.insert(i);
    }

    cin >> q;
    while( q-- ){
		cin >> t >> x >> y;
		if( t == 1 ){
            update(x, y - a[x]);
			a[x] = y;
		}else if( t == 2 ){
			if( b[x] > 1 ) st.erase(x);
			b[x] = y;
			if( b[x] > 1 ) st.insert(x);
		}else{
            res = 0; 
            int cnt = x - 1;
			auto it = st.lower_bound(x);
			while( it != st.end() && *it <= y ){
				res += sum(cnt + 1, *it - 1);
				res = max(res + a[*it], res * b[*it]);
				cnt = *it; 
                it++;
			}
			res += sum(cnt + 1, y);
			cout << res << '\n';
		}
	}
}