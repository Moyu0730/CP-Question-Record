/* Question : AtCoder Beginner Contest 341 - B. Foreign Exchange */

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
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
const int INF = 1e9;
int n, a[MAXN];
vector<pii> city;
queue<int> q;

signed main(){
    opt;
    cin >> n;

    city.resize(n);
    for( int i = 1 ; i <= n ; i++ ) cin >> a[i];
    for( int i = 1 ; i <= n-1 ; i++ ){
        cin >> city[i].F >> city[i].S;

        if( a[i] >= city[i].F ) q.push(i);
    }

    while( !q.empty() ){
        int top = q.front();
        q.pop();

        if( a[top] <= city[top].S ) continue;

        int times = a[top] / city[top].F;
        a[top] -= city[top].F * times;
        
        if( top == n-1 ){
            a[n] += city[top].S * times;
        }else{
            a[top+1] += city[top].S * times;

            if( a[top+1] >= city[top+1].S ) q.push(top+1);
        }
    }

    cout << a[n] << "\n";
}