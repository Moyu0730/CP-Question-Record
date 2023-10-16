/* Question : CF APCS Practice Contest - A. ABC5 */

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
const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
int n, con, imp, tp, total;

signed main(){
    opt;
    cin >> n;
    for( int i = 0 ; i < n ; i++ ){
        cin >> tp;

        if( tp == -1 ) continue;

        total++;
        if( tp == 1 ) imp++;
        else con++;
    }

    total /= 3;
    if( imp < total || con < total ) cout << "both\n";
    else if( con < imp ) cout << "implement\n";
    else cout << "concept\n";
}