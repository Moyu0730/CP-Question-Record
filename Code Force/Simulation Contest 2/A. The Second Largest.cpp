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
const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
multiset<int, greater<int>> st;
int q, tp, num, res;

signed main(){
    opt;
    cin >> q;
    while( q-- ){
        cin >> tp;
        if( tp == 1 ){
            cin >> num;
            st.insert(num);
        }else if( tp == 2 ){
            cin >> num;
            st.erase(num);
        }else{
            if( st.size() < 2 ) cout << "ruruORZ...\n";
            else{
                auto res = next(st.begin());
                cout << *res << "\n";
            }
        }
    }
}