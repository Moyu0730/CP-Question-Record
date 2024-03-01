/* Question : AtCoder Beginner Contest 342 - C. Many Replacement */

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
// #define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e3 + 50;
const int Mod = 1e9 + 7;
const int INF = 1e9;
int n, q;
string s;
char a, b, arr[MAXN];

signed main(){
    opt;

    cin >> n >> s >> q;

    for( int i = 'a' ; i <= 'z' ; i++ ) arr[i] = (char)i;
    
    while( q-- ){
        cin >> a >> b;
        
        for( int i = 'a' ; i <= 'z' ; i++ ){
            if( arr[i] == a ) arr[i] = b;
        }
    }

    for( int i = 0 ; i < s.size() ; i++ ) cout << arr[s[i]];
    cout << "\n";
}