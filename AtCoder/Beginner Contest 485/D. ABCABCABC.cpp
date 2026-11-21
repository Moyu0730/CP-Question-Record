/* Question : AtCoder Beginner Contest 485 - D. ABC|ABC|ABC */

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
const int     MAXN = 3e5 + 50;
const int      Mod = 1e9 + 7;
const int      INF = 0x7FFFFFFF;
const int    LLINF = 0x7FFFFFFFFFFFFFFF;
const int MEMLLINF = 0x3F3F3F3F3F3F3F3F;

bool valid[3 + 50];
int n, vl, vr, res;
string str;
vector<int> pA, pB, pC;

inline void solve(){
    cin >> n >> str;

    vl = n; vr = -1;
    MEM(valid, false);
    int amt = 3;
    for( int i = 0 ; i < n ; ++i ){
        if( str[i] == 'A' && !valid[0] ){
            valid[0] = true;
            --amt;
        }else if( str[i] == 'B' && !valid[1] ){
            valid[1] = true;
            --amt;
        }else if( str[i] == 'C' && !valid[2] ){
            valid[2] = true;
            --amt;
        }

        if( amt == 0 ){
            vl = i;
            break;
        }
    }

    MEM(valid, false);
    amt = 3;
    for( int i = n-1 ; i >= 0 ; --i ){
        if( str[i] == 'A' && !valid[0] ){
            valid[0] = true;
            --amt;
        }else if( str[i] == 'B' && !valid[1] ){
            valid[1] = true;
            --amt;
        }else if( str[i] == 'C' && !valid[2] ){
            valid[2] = true;
            --amt;
        }

        if( amt == 0 ){
            vr = i;
            break;
        }
    }

    if( vr <= vl ){
        cout << "0\n";
        return;
    }

    pA.rz(vr + 1, 0);
    pB.rz(vr + 1, 0);
    pC.rz(vr + 1, 0);
    for( int i = vl ; i <= vr ; ++i ){
        pA[i] = pA[i-1];
        pB[i] = pB[i-1];
        pC[i] = pC[i-1];

        if( str[i] == 'A' ) ++pA[i];
        else if( str[i] == 'B' ) ++pB[i];
        else if( str[i] == 'C' ) ++pC[i];
    }

    int cA, cB, cC; cA = cB = cC = 0;
    for( int i = vl ; i < vr ; ++i ){
        int ptrA = lower_bound(ALL(pA), pA[i] + 1) - pA.begin();
        int ptrB = lower_bound(ALL(pB), pB[i] + 1) - pB.begin();
        int ptrC = lower_bound(ALL(pC), pC[i] + 1) - pC.begin();

        int m = max({ptrA, ptrB, ptrC});

        // cout << "Cut " << i << " : " << ptrA << " " << ptrB << " " << ptrC << "\n";

        if( m >= vr ) break;

        res += vr - m;
    }

    cout << res << "\n";
}

signed main(){
    IO;

    int T = 1;
    // cin >> T;
    while( T-- ){
        solve();
    }
}