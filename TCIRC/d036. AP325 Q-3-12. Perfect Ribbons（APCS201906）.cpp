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
int n, m, res, color[MAXN], pre[MAXN];
bool used[MAXN];
queue<int> q;
vector<int> v;

signed main(){
    opt;
    cin >> m >> n;
    for( int i = 0 ; i < n ; i++ ){
        cin >> color[i];
        pre[i] = color[i];
    }

    sort(pre, pre + n);

    v.pb(pre[0]);
    for( int i = 1 ; i < n ; i++ ){
        if( pre[i] != pre[i-1] ) v.pb(pre[i]);
    }

    for( int i = 0 ; i < n ; i++ ){
        int ind = lower_bound(v.begin(), v.end(), color[i]) - v.begin();

        if( !q.empty() && used[ind] ){
            while( q.front() != ind ){
                used[q.front()] = false;
                q.pop();
            }
            used[q.front()] = false;
            q.pop();
        }

        q.push(ind);
        used[ind] = true;

        if( q.size() == m ) res++;
    }

    cout << res << "\n";
}