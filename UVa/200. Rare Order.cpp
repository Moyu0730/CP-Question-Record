/* Question : UVa 200. Rare Order */

#include<bits/stdc++.h>
using namespace std;

/* Pragma */
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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

/* Self Define Template Function */
template <typename T> void print(vector<T> _vector ) {
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
const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1},  {-1, 0}, {0, -1}, 
                                            {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
const int         MAXN = 1e3 + 50;
const int          Mod = 1e9 + 7;
const int          INF = 0x7FFFFFFF;
const ll         LLINF = 0x7FFFFFFFFFFFFFFF;
const int       MEMINF = 0x3F;
const int   MEMINF_VAL = 0x3F3F3F3F;
const ll  MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int indegree[MAXN];
bool used[MAXN], inside[MAXN], edge[MAXN][MAXN];
string pre, cnt;

inline void solve(){
    cin >> pre;
    for( auto i : pre ) inside[i] = true;
    while( cin >> cnt && cnt[0] != '#' ){
        for( auto i : cnt ) inside[i] = true;

        for( int i = 0 ; i < pre.sz && i < cnt.sz ; ++i ){
            if( pre[i] != cnt[i] ){
                if( !edge[pre[i]][cnt[i]] ){
                    edge[pre[i]][cnt[i]] = true;
                    ++indegree[cnt[i]];
                }
                break;
            }

        }

        pre = cnt;
    }

    for( int counter = 0 ; counter < 26 ; ++counter ){
        for( int i = 'A' ; i <= 'Z' ; ++i ){
            if( indegree[i] == 0 && !used[i] && inside[i] ){
                cout << (char)i;
                
                used[i] = true;
                for( int j = 'A' ; j <= 'Z' ; ++j ){
                    if( edge[i][j] ){
                        --indegree[j];
                    }
                }
                
                break;
            }
        }
    }

    cout << "\n";
}

signed main(){
    IO;

    int T = 1;
    // cin >> T;
    while( T-- ){
        solve();
    }
}