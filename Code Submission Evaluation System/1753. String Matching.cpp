/* Question : CSES 1753. String Matching */

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
const int p = 48763, q = 1e9 + 7;
vector<int> hstr, hc, ksm;
string str, cmp;
int amt, vs;

void hsh(){
    int len = str.size();
    hstr.resize(len);
    ksm.resize(len);
    hstr[0] = str[0]; 
    ksm[0] = 1;
    for( int i = 1 ; i < len ; i++ ){
        hstr[i] = ( ( hstr[i-1] * p ) % q + str[i] ) % q;
        ksm[i] = ( ksm[i-1] * p ) % q;
    }
    return;
}

int get( int l, int r ){
    if( l == 0 ) return hstr[r];

    int res = ( hstr[r] - ( hstr[l - 1] * ksm[r-l+1] ) % q ) % q;
    if( res < 0 ) res += q;
    return res;
}

signed main(){
    // opt;
    cin >> str >> cmp;

    // Get Hash Value
    /* str */
    hsh();

    /* cmp */
    vs = cmp[0];
    for( int i = 1 ; i < cmp.size() ; i++ ) vs = ( ( vs * p ) % q + cmp[i] ) % q;

    if( str.size() >= cmp.size() ){
        for( int i = 0 ; i < str.size() - ( cmp.size() - 1 ) ; i++ ){
            if( get( i, i + ( cmp.size() - 1 ) ) == vs ) amt++;
        }
    }
    
    cout << amt << "\n";
}