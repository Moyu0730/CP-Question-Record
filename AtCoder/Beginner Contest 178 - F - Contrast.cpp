/* Question : AtCoder Beginner Contest 178 - F - Contrast */

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
int n, flag, l, r, len, cnt, a[MAXN], b[MAXN];

signed main(){
    opt;
    cin >> n;
    for( int i = 0 ; i < n ; i++ ) cin >> a[i];
    for( int i = 0 ; i < n ; i++ ) cin >> b[i];
    reverse( b, b + n );

    l = -1;
    for( int i = 0 ; i < n ; i++ ){
        if( a[i] == b[i] && l == -1 ){
            l = i;
            r = i;
            flag = a[i];
        }else if( a[i] == b[i] && l != 0 ){
            r = i;
        }
    }

    if( l != -1 ){
        len = r - l, cnt = 0;
        for( int i = 0 ; i < n ; i++ ){
            if( cnt > len ) break;
            if( a[i] != flag && b[i] != flag ){
                b[cnt+l] = b[i];
                b[i] = flag;
                cnt++;
            }
        }
    }

    if( l == -1 || cnt > len ){
        cout << "Yes\n";
        for( int i = 0 ; i < n ; i++ ) cout << b[i] << " \n"[i==n-1];
    }else cout << "No\n";
}