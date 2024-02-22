/* Question : TCIRC d053. AP325 Q-4-8. First Come First Served（＊） */

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
const int INF = 1e9;
int n, m, cnt, res, t[MAXN];
priority_queue<int, vector<int>, greater<int>> pq;

signed main(){
    opt;
    cin >> n >> m;
    for( int i = 0 ; i < n ; i++ ) cin >> t[i];

    for( int i = 0 ; i < n ; i++ ){
        if( pq.size() < m ){
            pq.push(t[i]);
            res = max( res, t[i] );
            continue;
        }else{
            cnt = pq.top();
            pq.pop();

            res = max(res, cnt + t[i]);
            pq.push(cnt + t[i]);
        }
    }

    cout << res << "\n";
}