/* Question : AtCoder Beginner Contest 329 - F. Colored Ball */

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
#define X first
#define Y second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
int n, q, a, b, color[MAXN];
set<int> s[MAXN];

signed main(){
    opt;
    cin >> n >> q;
    for( int i = 1 ; i <= n ; i++ ){
        cin >> color[i];
        s[i].insert(color[i]);
    }

    while( q-- ){
        cin >> a >> b;
        if( s[a].size() <= s[b].size() ){
            for( auto i : s[a] ){
                s[b].insert(i);
            }

            s[a].clear();
        }else{
            for( auto i : s[b] ){
                s[a].insert(i);
            }

            s[b].clear();

            swap(s[a], s[b]);
        }

        cout << s[b].size() << "\n";
    }
}