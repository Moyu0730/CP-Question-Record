/* Question : OJ Number */

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

const auto dir = vector< pair<int, int> > { {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0} };
const int MAXN = 1e4 + 50;
const int Mod = 1e9 + 7;
const int INF = 1e9;
int n, res, dp[MAXN][26];
pii tar, lft, rgt;
string s;
string key[3] = {"QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM"};
map<char, pii> mp;

int dis( pii a, pii b ){
    if( a.F < b.F ){
        if( b.S >= a.S ) return b.F - a.F + b.S - a.S;
        if( b.S <= a.S - b.F + a.F ) return b.F - a.F + a.S - b.S - b.F + a.F;
        return b.F - a.F;
    }else if( a.F > b.F ){
        if( b.S <= a.S ) return a.F - b.F + a.S - b.S;
        if( b.S >= a.S + a.F - b.F ) return a.F - b.F + b.S - a.S - a.F + b.F;
        return a.F - b.F;
    }else{
        return abs( a.S - b.S );
    }
}

signed main(){
    opt;
    cin >> n >> s;

    for( int i = 0 ; i < 3 ; i++ ){
        for( int j = 0 ; j < key[i].size() ; j++ ) mp[key[i][j]-'A'] = {i, j};
    }
    
    mem(dp,0x3f);

    lft = {1, 3}; rgt = {1, 6};
    for( int i = 0 ; i < 26 ; i++ ){
        dp[0][i] = min( ( dis(lft, mp[s[0]-'A']) + dis(rgt, mp[i]) ),
                        ( dis(lft, mp[i]) + dis(rgt, mp[s[0]-'A']) ) );
    }

    for( int i = 0 ; i < n-1 ; i++ ){
        for( int j = 0 ; j < 26 ; j++ ){
            dp[i+1][j] = min(dp[i+1][j], dp[i][j] + dis(mp[s[i]-'A'], mp[s[i+1]-'A']) );
            dp[i+1][s[i]-'A'] = min(dp[i+1][s[i]-'A'], dp[i][j] + dis(mp[j], mp[s[i+1]-'A']) );
        }
    }

    int ans = INF;
    for( int i = 0 ; i < 26 ; i++ ) ans = min( ans, dp[n-1][i] );
    
    cout << ans << "\n";
}

/*
  0
0 QWERTYUIOP
0 ASDFGHJKL
0 ZXCVBNM   
*/