/* Question : AtCoder Beginner Contest 400 - E. Ringos Favorite Numbers 3 */

#include<bits/stdc++.h>
using namespace std;

/* Pragma */
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

/* Self Define */
#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pirq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define all(v) v.begin(), v.end()
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
const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;
const int MEMINF = 0x3F;
const int MEMINF_VAL = 0x3F3F3F3F;
const int MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int q, val;
bool used[MAXN];
vector<int> primeNum, res;

void completePrime() {
    used[0] = used[1] = true;
    for(int i = 2; i <= MAXN; i++) {
        if(!used[i]) {
            primeNum.push_back(i);
            for(int j = 2; i * j <= MAXN; j++) used[j * i] = true;
        }
    }
}

bool twoPrimeFactor(int num) {
    if(!used[num]) return false;
    int i = 0;
    for(; primeNum[i] * primeNum[i] <= num; i++) {
        if(num % primeNum[i] == 0) {
            while(num % primeNum[i] == 0) num /= primeNum[i];
            break;
        }
    }
    if(!used[num]) return true;
    if(num == 1) return false;
    for(; primeNum[i] * primeNum[i] <= num; i++) {
        if(num % primeNum[i] == 0) {
            while(num % primeNum[i] == 0) num /= primeNum[i];
            break;
        }
    }
    if(num > 1) return false;
    return true;
}

signed main(){
    opt;
    completePrime();

    for( int i = 6 ; i <= 1e6 ; ++i ){
        if( twoPrimeFactor(i) ) res.pb(i * i);
    }
    
    cin >> q;
    while( q-- ){
        cin >> val;
        cout << *prev(lower_bound(all(res), val+1)) << "\n";
    }
}