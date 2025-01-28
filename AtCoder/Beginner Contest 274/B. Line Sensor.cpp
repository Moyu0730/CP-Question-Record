/* Questjon : AtCoder Beginner Contest 274 - B. Line Sensor */

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
const int MAXN = 1e3 + 50;
const int Mod = 1e9 + 7;
int h, w;
char graph[MAXN][MAXN];

signed main(){
    opt;
    cin >> h >> w;
    for( int i = 0 ; i < h ; i++ ){
        for( int j = 0 ; j < w ; j++ ) cin >> graph[i][j];
    }

    int cnt;
    for( int j = 0 ; j < w ; j++ ){
        cnt = 0;
        for( int i = 0 ; i < h ; i++ ){
            if( graph[i][j] == '#' ) cnt++;
        }

        cout << cnt << " ";
    }
}