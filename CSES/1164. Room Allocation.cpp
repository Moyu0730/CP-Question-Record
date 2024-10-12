/* Question : CSES 1164. Room Allocation */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pirq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define F first
#define S second
#define X first
#define Y second
#define int long long
#define ll long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;

vector<pair<pii, int>> arr;
int n, a, b, res, num[MAXN];

bool cmp( pair<pii, int> x, pair<pii, int> y ){
    if( x.F.F != y.F.F ) return x.F.F < y.F.F;
    else if( x.F.S != y.F.S ) return x.F.S < y.F.S;
    else return x.S > y.S;
}

bool pre( pair<pii, int> x, pair<pii, int> y ){
    if( x.F.F != y.F.F ) return x.F.F < y.F.F;
    else return x.S > y.S;
}

void solve(){
    int cnt, last = -1;

    cnt = 0;
    sort(arr.begin(), arr.end(), pre);

    // for( auto i : arr ) cout << i.F.F << " " << i.F.S << " " << i.S << "\n";

    for( int i = 0 ; i < arr.size() ; ){
        last = arr[i].F.F;
        while( i < arr.size() && arr[i].F.F == last ){
            cnt += arr[i].S;
            
            i++;

            res = max(res, cnt);
            // cout << cnt << " " << res << "\n";
        }
    }

    cout << res << "\n";

    sort(arr.begin(), arr.end(), cmp);

    queue<int> q;
    for( int i = 1 ; i <= res ; i++ ) q.push(i);
    for( int i = 0 ; i < arr.size() ; i++ ){
        if( arr[i].S == 1 ){
            num[arr[i].F.S] = q.front();
            q.pop();
        }else q.push(num[arr[i].F.S]);
    }

    for( int i = 0 ; i < n ; i++ ) cout << num[i] << " ";
    cout << "\n";
}

signed main(){
    opt;

    cin >> n;
    for( int i = 0 ; i < n ; i++ ){
        cin >> a >> b;
        arr.pb({{a, i}, 1});
        arr.pb({{b, i}, -1});
    }

    // sort(arr.begin(), arr.end(), cmp);

    // for( auto i : arr ) cout << i.F.F << " " << i.F.S << " " << i.S << "\n";

    solve();
}