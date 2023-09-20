/* Question : OJ Number */

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
int n, m, c[MAXN], ft[MAXN];
char tmp, last[MAXN];
string str;

signed main(){
    opt;
    cin >> n >> m >> str;
    mem(ft, -1);
    for( int i = 0 ; i < n ; i++ ){
        cin >> c[i];
        if( ft[c[i]] == -1 ) ft[c[i]] = i;
    }

    for( int i = 0 ; i < n ; i++ ){
        if( i == ft[c[i]] ){
            last[c[i]] = str[i];
            str[i] = ' ';
        }else swap(last[c[i]], str[i]);
    }

    for( int i = 0 ; i < m ; i++ ){
        if( ft[c[i]] != -1 ) str[ft[c[i]]] = last[c[i]];
    }

    cout << str << "\n";
}