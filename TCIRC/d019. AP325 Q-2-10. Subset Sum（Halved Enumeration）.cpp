/* Question : TCIRC d019. AP325 Q-2-10. Subset Sum（Halved Enumeration） */

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
const int MAXN = 38 + 50;
const int Mod = 1e9 + 7;
int n, p, arr[MAXN];
vector<int> a, b;

signed main(){
    opt;
    cin >> n >> p;
    for( int i = 0 ; i < n ; i++ ) cin >> arr[i];

    int len_A = n / 2;
    int len_B = n - len_A;
    int res = 0;

    for( int i = 1 ; i < (1<<len_A) ; i++ ){
        int sum = 0;
        for( int j = 0 ; j < len_A ; j++ ){
            if( i & (1<<j) ) sum += arr[j];
        }

        if( sum > res && sum <= p ) res = sum;

        a.pb(sum);
    }

    for( int i = 1 ; i < (1<<len_B) ; i++ ){
        int sum = 0;
        for( int j = 0 ; j < len_B ; j++ ){
            if( i & (1<<j) ) sum += arr[len_A + j];
        }

        if( sum > res && sum <= p ) res = sum;

        b.pb(sum);
    }

    sort(b.begin(), b.end());

    for( auto i : a ){
        if( i > p ) continue;

        int tar = p - i;
        int ind = lower_bound(b.begin(), b.end(), tar) - b.begin();

        if( i + b[ind] <= p && i + b[ind] > res ) res = i + b[ind];
        else if( i + b[ind-1] <= p && i + b[ind-1] > res ) res = i + b[ind-1];
    }

    cout << res << " ";
}