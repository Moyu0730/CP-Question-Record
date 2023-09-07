/* Question : CSES 1628. Meet In The Middle */

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
const int MAXN = 40 + 50;
const int Mod = 1e9 + 7;
int n, x, res, arr[MAXN];
vector<int> l, r;

void sum( int st, int ed, vector<int>& v ){
    int len = ed - st + 1;
    for( int i = 0 ; i < ( 1 << len ) ; i++ ){
        int val = 0;
        for( int j = 0 ; j < len ; j++ ){
            if( i & ( 1 << j ) ) val += arr[st+j];
        }
        v.pb(val);
    }

    sort(v.begin(), v.end());
}

signed main(){
    opt;
    cin >> n >> x;
    for( int i = 1 ; i <= n ; i++ ) cin >> arr[i];

    sum(1, n/2, l);
    sum(n/2+1, n, r);

    for( auto i : l ){
        int dif = x - i;
        res += upper_bound(r.begin(), r.end(), dif) - lower_bound(r.begin(), r.end(), dif);
    }

    cout << res << "\n";
}