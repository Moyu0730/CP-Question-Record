 /* Question : AtCoder Beginner Contest 342 - D. Square Pair */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
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
const int INF = 1e9;
int n, a, res;
vector<int> v;

void prime( int val ){
    vector<pii> tmp;
    tmp.clear();
    int cnt = val;
    
    if( val == 0 ){
        v.pb(0);
        return;
    }

    for( int i = 2 ; i * i <= val ; i++ ){
        if( cnt == 1 ) break;

        while( cnt % i == 0 ){
            if( tmp.empty() || tmp.back().F != i ) tmp.pb({i, 1});
            else tmp.back().S++;

            cnt /= i;
        }
    }

    int ans = 1;
    if( val == cnt ) ans = val;
    else{
        for( auto i : tmp ){
            if( i.S % 2 == 1 ) ans *= i.F;
        }

        ans *= cnt;
    }
    
    v.pb(ans);
    return;
}

signed main(){
    opt;
    cin >> n;

    for( int i = 0 ; i < n ; i++ ){
        cin >> a;
        prime(a);
    }

    sort(v.begin(), v.end());

    int amt_one = 0, amt_zero = 0;
    for( int i = 0 ; i < v.size() ; i++ ){
        if( v[i] == 0 ) amt_zero = i+1;
        else if( v[i] == 1 ) amt_one = i - amt_zero + 1;
        else break;
    }

    int last;
    for( int i = 0 ; i < v.size() ; i++ ){
        last = res;
        if( v[i] == 0 ) res += v.size() - 1;
        else if( v[i] == 1 ) res += amt_one + amt_zero - 1;
        else{
            res += upper_bound(v.begin(), v.end(), v[i] ) - lower_bound(v.begin(), v.end(), v[i]) - 1;
            res += amt_zero;
        }
    }

    cout << res / 2 << "\n";
}