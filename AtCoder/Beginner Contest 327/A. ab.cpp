/* Question : AtCoder Beginner Contest 327 - A. ab */

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
#define x first
#define y second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
int n;
string str;

signed main(){
    opt;
    cin >> n >> str;

    for( int i = 0 ; i < str.size() ; i++ ){
        if( i == str.size() - 1 ){
            cout << "No\n";
            break;
        }

        if( str[i] == 'a' ){
            if( str[i+1] == 'b' ){
                cout << "Yes\n";
                break;
            }
        }

        if( str[i] == 'b' ){
            if( str[i+1] == 'a' ){
                cout << "Yes\n";
                break;
            }
        }
    }
}