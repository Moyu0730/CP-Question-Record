/* Question : AtCoder Beginner Contest 319 - C - False Hope */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pirq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define f first
#define s second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 3 + 50;
const int Mod = 1e9 + 7;
int graph[MAXN][MAXN];
int a, b;

signed main(){
    opt;
    for( int i = 1 ; i <= 3 ; i++ ){
        for( int j = 1 ; j <= 3 ; j++ ) cin >> graph[i][j];
    }

    vector<pii> p = {{1, 1}, {1, 2}, {1, 3}, 
                     {2, 1}, {2, 2}, {2, 3},
                     {3, 1}, {3, 2}, {3, 3} };
    do{
        for( int i = 0 ; i < p.size() ; i++ ){
            if( i == 0 ) a = graph[p[i].f][p[i].s]; continue;
            if( i == 1 ) b = graph[p[i].f][p[i].s]; continue;

            if( a == b )

        }
    }while( next_permutation(p.begin(), p.end()) );
}