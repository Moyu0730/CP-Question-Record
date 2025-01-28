/* Question : AtCoder Beginner Contest 347 - C. Ideal Holidays */

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
int n, a, b, tsk[MAXN];

signed main(){
    opt;

    cin >> n >> a >> b;

    for( int i = 0 ; i < n ; i++ ){
        cin >> tsk[i];
        
        tsk[i] %= a + b;
    }

    int Min = a + b + 1, Max = -1, SecMid = a + b + 1;
    for( int i = 0 ; i < n ; ++i ){
        Min = min(Min, tsk[i]);
        Max = max(Max, tsk[i]);
        
        if( tsk[i] > Min ){
            secMid = min(SecMid, tsk[i]);
        }
    }

    if( abs(Max - Min) < a || ( a + b ) - SecMin + Min < a ) cout << "Yes\n";
    else cout << "No\n";
}