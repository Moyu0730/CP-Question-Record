/* Question : AtCoder Beginner Contest 322 - B. Prefix and Suffix */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define priq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define F first
#define S second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
int n, m;
bool flag1, flag2;
string s, t;

signed main(){
    opt;
    cin >> n >> m >> s >> t;

    flag1 = true; // For Prefix
    for( int i = 0 ; i < s.size() ; i++ ){
        if( s[i] != t[i] ){
            flag1 = false;
            break;
        }
    }

    flag2 = true; // For Suffix
    for( int i = 0 ; i < s.size() ; i++ ){
        if( s[i] != t[t.size()-s.size()+i] ){
            flag2 = false;
            break;
        }
    }

    if( flag1 ){
        if( flag2 ) cout << 0 << "\n";
        else cout << 1 << "\n";
    }else{
        if( flag2 ) cout << 2 << "\n";
        else cout << 3 << "\n";
    }
}