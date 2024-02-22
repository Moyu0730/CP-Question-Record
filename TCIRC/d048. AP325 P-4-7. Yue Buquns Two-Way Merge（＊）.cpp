/* Question : TCIRC d048. AP325 P-4-7. Yue Buquns Two-Way Merge（＊） */

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
const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
int n, val, cost, a, b;
priority_queue<int, vector<int>, greater<int>> pq;

signed main(){
    opt;
    cin >> n;
    while( n-- ){
        cin >> val;
        pq.push(val);
    }

    while( pq.size() != 1 ){
        a = pq.top();
        pq.pop();

        b = pq.top();
        pq.pop();

        cost += a + b;
        pq.push(a + b);
    }

    cout << pq.top() << "\n" << cost << "\n";
}