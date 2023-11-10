/* Question : CSES 1640. Sum of Two Values */
 
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
int n, tar;
vector<pii> num;
 
signed main(){
    opt;
    cin >> n >> tar;
    num.resize(n);
    for( int i = 0 ; i < n ; i++ ){
        cin >> num[i].F;
        num[i].S = i + 1;
    }
 
    sort(num.begin(), num.end());

    int left = 0;
    int right = n-1;
    while( left < right ){
        int val = num[left].F + num[right].F;
        if( val > tar ) right--;
        else if( val < tar ) left++;
        else if( val == tar ){
            cout << num[left].S << " " << num[right].S << "\n";
            exit(0);
        }
    }
 
    cout << "IMPOSSIBLE\n";
}