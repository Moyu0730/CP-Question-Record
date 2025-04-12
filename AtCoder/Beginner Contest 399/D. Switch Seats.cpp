/* Question : AtCoder Beginner Contest 399 - D. Switch Seats */

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
#define all(v) v.begin(), v.end()
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
const int MAXN = 4e5 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;
const int MEMINF = 0x3F;
const int MEMINF_VAL = 0x3F3F3F3F;
const int MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int arr[MAXN];
int res, n, t;
vector<vector<int>> pos;
set<pii> st;

signed main(){
    opt;

    cin >> t;
    while( t-- ){
        res = 0;

        cin >> n;
        pos.clear();
        pos.resize(n + 5);
        st.clear();
        for( int i = 0 ; i < n * 2 ; ++i ){
            cin >> arr[i];
            pos[arr[i]].pb(i);
        }

        for( int i = 0 ; i + 1 < n * 2 ; ++i ){
            int x = arr[i];
            int y = arr[i+1];

            if( pos[x][0] + 1 == pos[x][1] ) continue;
            if( pos[y][0] + 1 == pos[y][1] ) continue;

            vector<int> tmp = { pos[x][0], pos[x][1], pos[y][0], pos[y][1] };
            sort(all(tmp));

            if( tmp[0] + 1 == tmp[1] && tmp[2] + 1 == tmp[3] ) st.insert({min(x, y), max(x, y)});
        }

        cout << st.size() << "\n";
    }
}