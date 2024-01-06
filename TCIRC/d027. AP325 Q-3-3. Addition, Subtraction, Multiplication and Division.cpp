/* Question : TCIRC d027. AP325 Q-3-3. Addition, Subtraction, Multiplication and Division */

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
#define X first
#define Y second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
string str;
deque<int> num;
deque<char> symbols;

signed main(){
    opt;
    cin >> str;
    for( int i = 0 ; i < str.size() ; i++ ){
        if( str[i] >= '0' && str[i] <= '9' ) num.push_back( str[i] - '0' );
        else if( str[i] == '+' || str[i] == '-' ) symbols.push_back(str[i]);
        else if( str[i] == '*' ){
            int last = num.back();
            num.pop_back();
            num.push_back(last * (str[i+1] - '0') );
            i++;
        }else{
            int last = num.back();
            num.pop_back();
            num.push_back(last / (str[i+1] - '0') );
            i++;
        }
    }

    int res = num.front();
    num.pop_front();
    while( !symbols.empty() ){
        if( symbols.front() == '+' ) res += num.front();
        else res -= num.front();

        symbols.pop_front();
        num.pop_front();
    }

    cout << res << "\n";
}