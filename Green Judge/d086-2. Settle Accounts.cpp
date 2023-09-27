/* Question : Green Judge d086-2. Settle Accounts */

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
map<string, pii> mp;

signed main(){
    opt;
    while( getline(cin, str) && str != "0000000000" ){
        string no = str.substr(0, 10);

        int price = 0, last = 0;
        for( int i = 11 ; str[i] != ' ' ; i++ ){
            price *= 10;
            price += str[i] - '0';
            last = i;
        }

        int amt = 0;
        for( int i = last+2 ; i < str.size() ; i++ ){
            amt *= 10;
            amt += str[i] - '0';
        }
        
        if( mp.count(no) == false ) mp[no] = {price, amt};
        else mp[no].s += amt;
    }

    double res = 0;
    for( auto it : mp ){
        string str = it.f;
        double price = it.s.f;
        double amt = it.s.s;
        
        if( str[0] == 'X' ){
            res += price * 1.0 * ( (int)amt % 2 + amt / 2 );
        }else if( str[0] == 'Y' ){
            if( (int)amt % 2 == 1 ){
                res += price;
                amt--;
                res += price * 0.5 * ( amt / 2 );
                res += price * 1.0 * ( amt / 2 );
            }else{
                res += price * 0.5 * ( amt / 2 );
                res += price * 1.0 * ( amt / 2 );
            }
        }else{
            res += price * 1.0 * amt;
        }
    }

    cout << res << "\n";
} 