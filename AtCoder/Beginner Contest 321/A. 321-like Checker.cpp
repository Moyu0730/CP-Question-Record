/* Question : AtCoder Beginner Contest 321 - A. 321-like Checker */

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
int num, pre, cnt;
bool flag;

signed main(){
    opt;
    cin >> num;

    pre = -1; 
    flag = true;
    while( num > 0 ){
        cnt = num % 10;
        
        if( cnt <= pre ){
            flag = false;
            break;
        }

        pre = cnt;
        num /= 10;
    }

    if( flag ) cout << "Yes\n";
    else cout << "No\n";
}