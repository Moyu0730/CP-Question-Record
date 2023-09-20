/* Question : OJ Number */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define priq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define f first
#define s second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
int n, m, k, arr[MAXN], pri[MAXN][55];
vector<vector<int>> sch;

signed main(){
    opt;
    cin >> n >> m >> k;

    sch.resize(m+5);
    for( int i = 0 ; i < n ; i++ ) cin >> arr[i];
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 0 ; j < 5 ; j++ ) cin >> pri[i][j];
    }

    for( int i = 0 ; i < n ; i++ ){
        int cnt = arr[i];
        for( int j = 0 ; j < 5 ; j++ ){
            int tar = pri[cnt][j];

            if( sch[tar].size() >= k ) continue;
            else{
                sch[tar].pb(cnt);
                break;
            }
        }
    }

    for( int i = 1 ; i <= m ; i++ ){
        cout << sch[i].size() << " ";
        if( sch[i].size() == 0 ) continue;

        sort( sch[i].begin(), sch[i].end() );
        for( auto j : sch[i] ) cout << j << " ";
        cout << "\n";
    }
}