/* Question : TCIRC d011. AP325 P-2-2. Discretization – Sort */

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

const int MAXN = 1e6 + 50;
const int Mod = 1e9 + 7;
int n, arr[MAXN], pre[MAXN], v[MAXN];

signed main(){
    opt;
    cin >> n;
    for( int i = 0 ; i < n ; i++ ){
        cin >> arr[i];
        pre[i] = arr[i];
    }

    sort(pre, pre + n);
    
    int num = 1;
    v[0] = pre[0];
    for( int i = 1 ; i < n ; i++ ){
        if( pre[i] != pre[i-1] ){
            v[num++] = pre[i];
        }
    }

    for( int i = 0 ; i < n ; i++ ){
        cout << lower_bound(v, v + num, arr[i]) - v << " \n"[i==n-1];
    }
}