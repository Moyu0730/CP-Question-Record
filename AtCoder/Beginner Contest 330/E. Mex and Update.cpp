/* Question : AtCoder Beginner Contest 330 - E. Mex and Update */

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
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
int n, q, ind, val, arr[MAXN], amt[MAXN];
set<int> st;

signed main(){
    opt;
    cin >> n >> q;
    for( int i = 0 ; i < n ; i++ ){
        cin >> arr[i];
        if( arr[i] <= n ) amt[arr[i]]++;
    }

    for( int i = 0 ; i <= n ; i++ ){
        if( !amt[i] ) st.insert(i);
    }

    while( q-- ){
        cin >> ind >> val;
        
        ind--;
        if( arr[ind] <= n ){
            amt[arr[ind]]--;
            if( !amt[arr[ind]] ) st.insert(arr[ind]);
        }
        if( val <= n ){
            if( !amt[val] ) st.erase(st.find(val));
            amt[val]++;
        }

        arr[ind] = val;
        
        cout << *st.begin() << "\n";
    }
}