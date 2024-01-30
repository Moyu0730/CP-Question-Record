/* Question : TCIRC d035. AP325 Q-3-11. The Longest Distinct Color Band */

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

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
int n, res, color[MAXN];
bool used[MAXN];
queue<int> q;

signed main(){
    opt;
    cin >> n;
    for( int i = 0 ; i < n ; i++ ) cin >> color[i];

    for( int i = 0 ; i < n ; i++ ){
        res = max(res, (int)q.size());
        
        if( !q.empty() && used[color[i]] ){
            while( q.front() != color[i] ){
                used[q.front()] = false;
                q.pop();
            }
            used[q.front()] = false;
            q.pop();
        }

        q.push(color[i]);
        used[color[i]] = true;
    }

    cout << res << "\n";
}