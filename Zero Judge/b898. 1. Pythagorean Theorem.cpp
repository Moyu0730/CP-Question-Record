/* Question : ZeroJudge b898. 1. Pythagorean Theorem */

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
const int MAXN = 10 + 50;
const int Mod = 1e9 + 7;
int n, cnt;
string tmp, num[MAXN];

string big( string a, string b ){
    if( a.size() > b.size() ) return a;
    if( b.size() > a.size() ) return b;

    for( int i = 0 ; i < a.size() ; i++ ){
        if( a[i] > b[i] ) return a;
        else if( b[i] > a[i] ) return b;
    }

    return a;
}

signed main(){
    opt;
    cin >> n;
    n += 1;
    while( n-- ){
        getline(cin, tmp);

        cnt = 0;
        for( int i = 0 ; i < 3 ; i++ ) num[i].clear();

        for( int i = 0 ; i < tmp.size() ; i++ ){
            if( tmp[i] == ' ' ){
                cnt++;
                continue;
            }

            num[cnt].pb(tmp[i]);
        }
        
        cout << big(num[0], big(num[1], num[2]) ) << "\n";
    }
}