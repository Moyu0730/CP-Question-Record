/* Question : AtCoder Beginner Contest 370 - B. Binary Alchemy */

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
const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
const int INF = 1e9;

int n;
vector<vector<int>> v;

signed main(){
    opt;

    cin >> n;
    v.resize(n+5);
    for( int i = 1 ; i <= n ; i++ ){
        v[i].resize(i+5);
        for( int j = 1 ; j <= i ; j++ ) cin >> v[i][j];
    }

    int cnt = v[1][1];
    for( int j = 2 ; j <= n ; j++ ){
        if( cnt >= j ) cnt = v[cnt][j];
        else cnt = v[j][cnt];
    }

    cout << cnt << "\n";
}