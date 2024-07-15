/* Question : ZeroJudge d672. 10922 - 2 the 9s */

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
int sum;

int degree( int sum, int step ){
    if( sum == 9 ) return step + 1;
    
    int tmp = 0;
    while( sum > 0 ){
        tmp += sum % 10;
        sum /= 10;
    }

    return degree(tmp, step+1);
}

signed main(){
    opt;
    
    while( cin >> str ){
        if( str == "0" ) break;

        sum = 0;
        for( int i = 0 ; i < str.size() ; i++ ) sum += str[i] - '0';

        if( sum % 9 == 0 ) cout << str << " is a multiple of 9 and has 9-degree " << degree(sum, 0) << ".\n";
        else cout << str << " is not a multiple of 9.\n";
    }
    
}