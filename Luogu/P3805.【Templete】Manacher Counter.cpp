/* Question : Luogu P3805.【Templete】Manacher Counter */

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

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e7 + 50;
const int Mod = 1e9 + 7;
const int p = 48763, q = 1e9 + 7;
string str;
int ans, posHash[MAXN], negHash[MAXN], ksm[MAXN];
int len;

void Pre(){

    posHash[0] = str[0]; negHash[len-1] = str[len-1];
    for( int i = 1, j = len-2 ; i < len ; i++, j-- ){
        ksm[i] = ( ksm[i-1] * p ) % q;
        posHash[i] = ( ( posHash[i-1] * p ) % q + str[i] ) % q;
        negHash[j] = ( ( negHash[j+1] * p ) % q + str[j+1] ) % q;
    }
}

int posQuery( int l, int r ){
    if( l == 0 ) return posQuery[r];

    int tmp = ( posHash[r] - ( posHash[l-1] * ksm[r-l+1] ) % q ) % q;
    if( tmp < 0 ) tmp += q;

    return tmp;
}

int negQuery( int l, int r ){
    if( r == len - 1 ) return negQuery[l];

    int tmp = ( negHash[l] - ( negHash[r+1] * ksm[l-r-1] ) % q ) % q;
    if( tmp < 0 ) tmp += q;

    return tmp;
}

bool valid( int ls, int rs, int q ){
    if( ls - q < 0 || rs + q > len ) return false;
    return ( negQuery(ls-q, ls) == posQuery(rs, rs+q) );
}

int bs( int ls, int rs ){
    int sz = 0, step = 1e7;
    
    while( step > 0 ){
        if( valid( ls, rs, sz + step ) ) sz += step;
        else step /= 2;
    }

    return sz;
}

signed main(){
    opt;
    cin >> str;
    len = str.size();
    
    Pre();

    ans = 1;
    for( int i = 1 ; i < len-2 ; i++ ) ans = max(ans, bs(i, i+1));
    for( int i = 1 ; i < len-1 ; i++ ) ans = max(ans, bs(i, i));

    cout << ans << "\n";
}