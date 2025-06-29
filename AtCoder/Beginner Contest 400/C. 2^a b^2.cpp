/* Question : AtCoder Beginner Contest 400 - C. 2^a b^2 */

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

int n, c;

bool valid(int a, int b){
    int m = a*b*b;
    if(m <= n && m>0) return true;
    else return false;
}

signed main(){
    opt;
    cin >> n;
    for(int a = 2; a <= n; a *= 2)
    {
        int res = 0, step = 1e9 / (sqrt(a)+1 )+ 1;
        while(step > 0){
            if(valid(a, res+step)) res += step;
            else step /= 2;
        }

        // cout << a << " " << res << "\n";
        c += (res + 1) / 2;
    }

    cout << c << "\n";
}