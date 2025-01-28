/* Question : AtCoder Beginner Contest 323 - A. Weak Beats */

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
string str;
bool res = true;

signed main(){
    opt;
    cin >> str;
    for( int i = 1 ; i < str.size() ; i += 2 ){
        if( str[i] == '1' ){
            res = false;
            break;
        }
    }

    if( res ) cout << "Yes\n";
    else cout << "No\n";
}