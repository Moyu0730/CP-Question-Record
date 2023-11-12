/* Question : AtCoder Beginner Contest 328 - B. 11.11 */

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
int n, res, dif, arr[MAXN];

bool check( int val ){
    int t = val % 10;
    while( val > 0 ){
        val /= 10;
        if( val % 10 != t && val > 0 ) return false;
    }

    return true;
}

signed main(){
    opt;
    cin >> n;

    for( int i = 1 ; i <= n ; i++ ) cin >> arr[i];

    int cnt;
    for( int i = 1 ; i <= n ; i++ ){
        if( !check(i) ) continue;

        dif = i % 10;
        cnt = dif;
        while( cnt <= arr[i] ){
            res++;

            cnt *= 10;
            cnt += dif;
        }
    }

    cout << res << "\n";
}