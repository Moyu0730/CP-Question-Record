/* Question : ZJ c082. 00118 - Mutant Flatworld Expolrers */

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
#define vsort(x) sort(x.begin(), x.end());
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

int h, w, ftoi[256], ftoidx[256];
bool flag, valid[55][55];
char face;
pii cnt, nxt;
string str;

signed main(){
    opt;

    cin >> w >> h;

    ftoi['N'] = 1;
    ftoi['E'] = 0;
    ftoi['S'] = 3;
    ftoi['W'] = 2;

    ftoidx['N'] = 0;
    ftoidx['E'] = 1;
    ftoidx['S'] = 2;
    ftoidx['W'] = 3;

    mem(valid, false);

    while( cin >> cnt.F >> cnt.S >> face ){
        cin >> str;

        nxt = cnt;
        flag = false;
        for( int i = 0 ; i < str.size() ; ++i ){

            if( str[i] == 'F' ){
                nxt = { cnt.F + dir[ftoi[face]].F, cnt.S + dir[ftoi[face]].S };

                if( nxt.F < 0 || nxt.F > w || nxt.S < 0 || nxt.S > h ){
                    if( valid[cnt.F][cnt.S] ) continue;
                    valid[cnt.F][cnt.S] = true;
                    flag = true;
                }else{
                    cnt = nxt;
                }
            }else if( str[i] == 'R' ){
                face = "NESW"[(ftoidx[face] + 1) % 4];
            }else if( str[i] == 'L' ){
                face = "NESW"[(ftoidx[face] + 3) % 4];
            }
        }

        if( flag ) cout << cnt.F << " " << cnt.S << " " << face << " LOST\n";
        else cout << cnt.F << " " << cnt.S << " " << face << "\n";
    }
}