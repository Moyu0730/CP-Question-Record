/* Question : AtCoder Beginner Contest 319 - B - Measure */

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
const int MAXN = 1e3 + 50;
const int Mod = 1e9 + 7;
int n;
char res[MAXN];
vector<int> d;

signed main(){
    // opt;
    cin >> n;
    for( int i = 1 ; i <= 9 ; i++ ){
        if( n % i == 0 ) d.pb(i);
    }

    for( int i = 0 ; i <= n ; i++ ){
        int ans = -1;
        for( auto j : d ){
            int cnt = n / j;
            if( i == 0 ){
                ans = j;
                break;
            }
            if( i % cnt == 0 ){
                ans = j;
                break;
            }
        }

        if( ans != -1 ) res[i] = '0' + ans;
        else res[i] = '-';
    }

    for( int i = 0 ; i <= n ; i++ ) cout << res[i];
    cout << "\n";
}