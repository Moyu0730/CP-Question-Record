/* Question : CSES 2431. Digit Queries */

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
const int MAXN = 1e3 + 50;
const int Mod = 1e9 + 7;
int q, cnt;

signed main(){
    opt;
    cin >> q;

    while( q-- ){
        cin >> cnt;

        int count = 1, tmp = cnt, amt = 9, acc = 0;
        while( tmp > amt * count ){
            tmp -= amt * count;
            count++;
            amt *= 10;
            acc += amt;
        }

        int value = ( acc / 10 ) + ( (tmp+count-1) / count );
        for(int i = 0 ; i < count - ( (tmp+count-1) % count ) - 1 ; i++ ) value /= 10;

        cout << value % 10 << "\n"; 
    }
}

/*
1 ~ 9      (9)        -> 1
10 ~ 99    (90 * 2)   -> 2
100 ~ 999  (900 * 3)  -> 3
*/