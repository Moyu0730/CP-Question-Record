/* Question : AtCoder Beginner Contest 347 - B. Substring */

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
const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
const int INF = 1e9;
string str;
map<string, int> mp;

signed main(){
    opt;
    cin >> str;
    for( int l = 1 ; l <= str.size() ; l++ ){
        for( int i = 0 ; i < str.size() ; i++ ){
            if( i + l - 1 >= str.size() ) break;
            else mp[str.substr(i, l)]++;
        }
    }

    cout << mp.size() << " ";
}