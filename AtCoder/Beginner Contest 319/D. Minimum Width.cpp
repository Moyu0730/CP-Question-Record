/* Question : AtCoder Beginner Contest 319 - D - Minimum Width */

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
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
int n, m, tmp;
vector<int> arr;

bool valid( int len ){
    int cnt = len, line = 1;
    for( int i = 0 ; i < arr.size() ; i++ ){
        if( len < arr[i] ) return false;

        if( cnt >= arr[i] ) cnt -= arr[i];
        else{
            line++;
            cnt = len - arr[i];
        }

        if( cnt > 0 ) cnt -= 1;
        else{
            cnt = len;
            line++;
        }
    }

    if( cnt == len ) line--;

    return line <= m;
}


signed main(){
    opt;
    cin >> n >> m;
    for( int i = 0 ; i < n ; i++ ){
        cin >> tmp;
        arr.pb(tmp);
    }

    int step = 1e18, res = 0;
    while( step > 0 ){
        if( !valid(res + step) ) res += step;
        else step /= 2;
    }

    cout << res+1 << "\n";
}