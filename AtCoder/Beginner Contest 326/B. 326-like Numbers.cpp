/* Question : AtCoder Beginner Contest 326 - B. 326-like Numbers */

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
int n, product, cnt;

bool valid( int val ){
    cnt = val % 10;
    val /= 10;

    product = val % 10;
    val /= 10;
    product *= val;

    return cnt == product;
}

signed main(){
    opt;
    cin >> n;
    for( int i = n ; i < 1000 ; i++ ){
        if( valid(i) ){
            cout << i << "\n";
            break;
        }
    }
}