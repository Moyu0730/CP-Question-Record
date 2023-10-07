/* Question : AtCoder Beginner Contest 182 - C - To 3 */

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
const int MAXN = 1e5 + 50;
const int Mod = 1e9 + 7;
int n, a, m;
vector<vector<int>> v;
int res[MAXN];

void fac( int val ){
    for( int i = 1 ; i * i <= val ; i++ ){
        if( val % i == 0 ){
            if( val / i == i ) res[i]++;
            else{
                res[i]++;
                res[val/i]++;
            }
        }
    }
}

signed main(){
    cin >> n;

    v.resize(n);
    m = -1;
    for( int i = 0 ; i < n ; i++ ){
        cin >> a;
        m = max(m, a);
        fac(a);
    }

    int amt = 0, value = 2;
    for( int i = 2 ; i <= m ; i++ ){
        if( res[i] > amt ){
            amt = res[i];
            value = i;
        }
    }

    cout << value << "\n";
}
