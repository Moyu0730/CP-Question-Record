/* Question : AtCoder Beginner Contest 324 - E. Joint Two Strings */

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
const int MAXN = 5e5 + 50;
const int Mod = 1e9 + 7;
int n, res, amt;
string t, str;
vector<int> prefix, suffix;

void dealt( string s ){
    int fptr = 0, bptr = t.size() - 1;
    for( int i = 0, j = s.size() - 1; i < s.size() ; i++, j-- ){
        if( fptr < t.size() && s[i] == t[fptr] ) fptr++;
        if( bptr >= 0 && s[j] == t[bptr] ) bptr--;
    }

    prefix.pb(fptr);
    suffix.pb(t.size() - 1 - bptr);
    return;
}

signed main(){
    opt;
    cin >> n >> t;
    for( int i = 0 ; i < n ; i++ ){
        cin >> str;
        dealt(str);
    }

    sort( prefix.begin(), prefix.end() );
    sort( suffix.begin(), suffix.end() );

    int rptr = n - 1;
    for( int lptr = 0 ; lptr < n ; lptr++ ){
        while( rptr >= 0 && prefix[lptr] + suffix[rptr] >= t.size() ) rptr--;

        amt = n - 1 - rptr;
        res += amt;
    }

    cout << res << "\n";
}