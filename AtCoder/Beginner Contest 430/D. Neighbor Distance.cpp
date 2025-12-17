/* Question : AtCoder Beginner Contest 430 - D. Neighbor Distance */

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
#define REV(_vector) reverse(ALL(_vector))
#define vc(_data) vector<_data>
#define pii pair<int, int>
#define pdd pair<double, double>
#define mkp make_pair
#define sz size()
#define rz resize
#define cr clear()
#define pb push_back
#define F first
#define S second
#define X first
#define Y second
#define int long long
#define ll long long
#define ld long double
#define tpn typename

/* Self Define Template Function */
template <typename T> void pV(vector<T> _vector ){
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
    return _os << '(' << _pair.F << ", " << _pair.S << ')';
}

/* Self Define Const */
const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1},  {-1, 0}, {0, -1}, 
                                            {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
const int         MAXN = 1e7 + 50;
const int          Mod = 1e9 + 7;
const int          INF = 0x7FFFFFFF;
const ll         LLINF = 0x7FFFFFFFFFFFFFFF;
const int       MEMINF = 0x3F;
const int   MEMINF_VAL = 0x3F3F3F3F;
const ll  MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int n, res, tmp;
set<pii> st;

inline void solve(){
    cin >> n;

    for( int i = 0 ; i <= n ; ++i ){
        if( i != 0 ) cin >> tmp;
        
        if( i == 0 ) st.insert({tmp, LLONG_MAX});
        else if( i == 1 ){
            auto bg = st.begin();
            int dif = abs((*bg).F - tmp);

            res += dif * 2;
            st.insert({(*bg).F, dif});
            st.insert({tmp, dif});
            st.erase(bg);
        }else{
            auto lb = st.lower_bound({tmp, -1});

            if( tmp > (*st.rbegin()).F ){
                auto ed = st.rbegin();
                int dif = abs((*ed).F - tmp);

                if( dif < (*ed).S ){
                    res -= (*ed).S;
                    res += dif * 2;

                    st.insert({(*ed).F, dif});
                    st.erase({(*ed).F, (*ed).S});
                }else res += dif; 
                
                st.insert({tmp, dif});
            }else if( (*lb).F == tmp ){
                res -= (*lb).S;
                st.insert({(*lb).F, 0});
                st.erase(lb);
            }else{
                if( tmp < (*st.begin()).F ){
                    auto bg = st.begin();
                    int dif = abs((*bg).F - tmp);

                    if( dif < (*bg).S ){
                        res -= (*bg).S;
                        res += dif * 2;

                        st.insert({(*bg).F, dif});
                        st.insert({tmp, dif});
                        st.erase(bg);
                    }else{
                        res += dif;

                        st.insert({tmp, dif});
                    }
                }else{
                    auto pre = prev(lb);
                    int vlb = (*lb).F, vpre = (*pre).F;

                    if( abs((*lb).F - tmp) < (*lb).S ){
                        res -= (*lb).S;
                        res += abs((*lb).F - tmp);

                        st.insert({(*lb).F, abs((*lb).F - tmp)});
                        st.erase(lb);
                    }

                    if( abs((*pre).F - tmp) < (*pre).S ){
                        res -= (*pre).S;
                        res += abs((*pre).F - tmp);

                        st.insert({(*pre).F, abs((*pre).F - tmp)});
                        st.erase(pre);
                    }

                    res += min( abs(vlb - tmp), abs(vpre - tmp) );
                    st.insert({tmp, min( abs(vlb - tmp), abs(vpre - tmp) )});
                }
            }
        }

        if( i != 0 ) cout << res << "\n";
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