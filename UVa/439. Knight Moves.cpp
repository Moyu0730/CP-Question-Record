/* Question : UVa 439. Knight Moves */

#include<bits/stdc++.h>
using namespace std;

/* Pragma */
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

/* Self Define */
#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MEM(_array, _value) memset(_array, _value, sizeof(_array));
#define ALL(_array) _array.begin(), _array.end()
#define LB(_array, v) lower_bound(ALL(_array), v)
#define UB(_array, v) upper_bound(ALL(_array), v)
#define vc(_data) vector<_data>
#define pii pair<int, int>
#define pdd pair<double, double>
#define mkp make_pair
#define sz size()
#define pb push_back
#define F first
#define S second
#define int long long
#define ll long long
#define ld long double
#define tpn typename

/* Self Define Template Function */
template <typename T> void pV(vector<T> _vector ) {
    for( auto _it : _vector ) cout << _it << " ";
    cout << "\n";
}

template <typename A, typename B> bool boundry( pair<A, B> &_pair, int _n, int _m ){
    return 1 <= _pair.F && _pair.F <= _n && 1 <= _pair.S && _pair.S <= _m;
}

template <typename A, typename B> istream& operator>>( istream& _is, pair<A, B> &_pair ){ 
    return _is >> _pair.F >> _pair.S;
}

template <typename A, typename B> ostream& operator<<( ostream& _os, pair<A, B> _pair ){ 
    return _os << '(' << _pair.F << " " << _pair.S << ')';
}

/* Self Define Const */
const auto dir = vector< pii > { {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
					    {1, 2}, {1, -2}, {-1, 2}, {-1, -2} };
const int         MAXN = 1e2 + 50;
const int          Mod = 1e9 + 7;
const int          INF = 0x7FFFFFFF;
const ll         LLINF = 0x7FFFFFFFFFFFFFFF;
const int       MEMINF = 0x3F;
const int   MEMINF_VAL = 0x3F3F3F3F;
const ll  MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

string a, b;
pii s, t;
int used[MAXN][MAXN];
queue<pii> q;

inline void solve(){
    while( cin >> a >> b ){
    	s = { a[0] - 'a', a[1] - '1' };
    	t = { b[0] - 'a', b[1] - '1' };
    	
    	// cout << s.F << " " << s.S << " TO " << t.F << " " << t.S << "\n";
    	
    	queue<pii> emptyQ;
    	q.swap(emptyQ);
    	MEM(used, MEMINF);
    	
    	q.push(s);
    	used[s.F][s.S] = 0;
     	while( !q.empty() ){
     		pii cnt = q.front();
     		q.pop();
     		
     		if( cnt == t ){
     			cout << "To get from " << a << " to " << b << " takes " << used[t.F][t.S] << " knight moves.\n";
     		}
     		
     		for( int it = 0 ; it < 8 ; ++it ){
     			pii nxt = { cnt.F + dir[it].F, cnt.S + dir[it].S };
     			
     			if( nxt.F < 0 || cnt.F >= 8 || cnt.S < 0 || cnt.S >= 8 ) continue;
     			if( used[nxt.F][nxt.S] != MEMLLINF_VAL ) continue;
     			
     			used[nxt.F][nxt.S] = used[cnt.F][cnt.S] + 1;
     			q.push(nxt);
     		}
    	}
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