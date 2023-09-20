/* Question : OJ Number */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pirq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define f first
#define s second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 5e5 + 50;
const int Mod = 1e9 + 7;
int n, q, a, b;
char c;
vector<tuple<int, int, char>> vtp;
string str;

void toUpper(){
    for( int i = 0 ; i < n ; i++ ){
        if( str[i] <= 'z' && str[i] >= 'a' ) str[i] &= ~32;
    }
}

void toLower(){
    for( int i = 0 ; i < n ; i++ ){
        if( str[i] <= 'Z' && str[i] >= 'A' ) str[i] |= 32;
    }
}

signed main(){
    opt;
    cin >> n >> str >> q;
    for( int i = 0 ; i < q ; i++ ){
        cin >> a >> b >> c;
        vtp.pb({a, b, c});
    }

    for( auto i : vtp ){
        if( get<0>(i) == 1 ) str[get<1>(i)-1] = get<2>(i);
        else if( get<0>(i) == 2 ) toLower();
        else toUpper();
    }

    cout << str << "\n";
}