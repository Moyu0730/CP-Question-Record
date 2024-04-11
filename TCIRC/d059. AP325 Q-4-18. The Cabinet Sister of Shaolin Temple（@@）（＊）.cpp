/* Question : TCIRC d059. AP325 Q-4-18. The Cabinet Sister of Shaolin Temple（@@）（＊） */

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
const int MAXN = 1e6 + 50;
const int Mod = 1e9 + 7;
const int INF = 1e6 + 50;
int n, d, t[MAXN];

bool valid( int val ){
    priority_queue<int, vector<int>, greater<int>> pq;

    for( int i = 0 ; i < n ; i++ ){
        if( pq.size() < val ){
            pq.push(t[i]);
        }else if( t[i] + pq.top() <= d ){
            int cnt = t[i] + pq.top();
            pq.pop();
            pq.push(cnt);
        }else{
            return false;
        }
    }

    return true;
}

signed main(){
    // opt;
    cin >> n >> d;
    for( int i = 0 ; i < n ; i++ ) cin >> t[i];

    int step = INF, res = 0;

    while( step > 0 ){
        if( valid(res + step) ) step /= 2;
        else res += step;
    }

    cout << res + 1 << "\n";
}