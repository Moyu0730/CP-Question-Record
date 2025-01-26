/* Question : CSES 2216. Collecting Numbers */

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
#define x first
#define y second
#define int long long

/*---------- Solution I ----------*/
const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
int n, res, arr[MAXN];
bool used[MAXN];

signed main(){
    opt;
    cin >> n;
    for( int i = 0 ; i < n ; i++ ) cin >> arr[i];

    for( int i = 0 ; i < n ; i++ ){
        if( !used[arr[i]-1] ) res++;
        used[arr[i]] = true;
    }

    cout << res << "\n";
}

/*---------- Solution II ( Better ) ----------*/
const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
int n, res, arr[MAXN], idx[MAXN];

signed main(){
    opt;
    cin >> n;
    for( int i = 0 ; i < n ; i++ ){
        cin >> arr[i];
        idx[arr[i]] = i;
    }

    for( int i = 2 ; i <= n ; ++i ){
        if( idx[i] < idx[i-1] ) res++;
    }

    cout << res+1 << "\n";
}