/* Question : TCIRC d018. AP325 P-2-9. Subset Product（Halved Enumeration）（@@） */

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
const int MAXN = 37 + 50;
const int Mod = 1e9 + 7;
int n, p, res, amt[1<<19], arr[MAXN];
vector<int> a, b;

int ksm( int base, int power ){
    int res = 1;
    while( power > 0 ){
        if( power & 1 ){
            res = ( res * base ) % p;
        }

        base = ( base * base ) % p;
        power >>= 1;
    }

    return res % p;
}

signed main(){
    opt;
    cin >> n >> p;
    for( int i = 0 ; i < n ; i++ ) cin >> arr[i];

    for( int i = 1 ; i < (1<<(n/2)) ; i++ ){
        int tmp = 1;
        for( int j = 0 ; j < n/2 ; j++ ){
            if( i & (1<<j) ) tmp = ( tmp * arr[j] ) % p;
        }

        if( tmp % p == 1 ) res = ( res + 1 ) % p;

        a.pb(tmp);
    }

    for( int i = 1 ; i < (1<<(n-(n/2))) ; i++ ){
        int tmp = 1;
        for( int j = 0 ; j < n-(n/2) ; j++ ){
            if( i & (1<<j) ) tmp = ( tmp * arr[n/2+j] ) % p;
        }

        if( tmp % p == 1 ) res = ( res + 1 ) % p;

        b.pb(tmp);
    }

    sort(b.begin(), b.end());
    amt[0] = 1;
    int len = 1;
    for( int i = 1 ; i < b.size() ; i++ ){
        if( b[i] != b[i-1] ){
            b[len] = b[i];
            amt[len] = 1;
            len++;
        }else amt[len-1]++;
    }

    res = ( b[0] == 1 ) ? amt[0] % p : 0; 

    for( auto i : a ){
        if( i == 1 ) res = ( res + 1 ) % p;

        int inverse = ksm(i, p-2);
        int it = lower_bound(b.begin(), b.begin() + len, inverse) - b.begin();

        if( it < len && b[it] == inverse ) res = ( res + amt[it] ) % p;
    }

    cout << res << " ";
}