/* Question : AtCoder Beginner Contest 315 - C - Flavors */

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
const int MAXN = 3e5 + 50;
const int Mod = 1e9 + 7;
int n, ans;
vector<pii> arr;

signed main(){
    opt;
    cin >> n;
    arr.resize(n);
    for( int i = 0 ; i < n ; i++ ) cin >> arr[i].s >> arr[i].f; 
    
    sort( arr.begin(), arr.end(), greater<pii>() );

    // cout << "-----\n";
    // for( auto i : arr ) cout << i.f << " " << i.s <<  "\n";
    // cout << "-----\n";

    ans = 0;
    if( arr[0].s == arr[1].s ) ans = arr[0].f + ( arr[1].f / 2 );
    else ans = arr[0].f + arr[1].f;

    int tp = arr[0].s;
    for( auto i : arr ) if( i.s != tp ) ans = max(ans, arr[0].f + i.f );

    cout << ans << "\n";
}