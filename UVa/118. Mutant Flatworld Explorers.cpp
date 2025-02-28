/* Question : UVa 118. Mutant Flatworld Explorers */

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

// const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
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
// pii cnt, nxt;
int d, cntx, cnty, nxtx, nxty;
// int dir[][] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
string str;

signed main(){
    opt;

    cin >> w >> h;

    // ftoi['N'] = 1;
    // ftoi['E'] = 0;
    // ftoi['S'] = 3;
    // ftoi['W'] = 2;

    // ftoidx['N'] = 0;
    // ftoidx['E'] = 1;
    // ftoidx['S'] = 2;
    // ftoidx['W'] = 3;

    map <char, int> ftoi;
    map <int, char> itof;
    ftoi['N'] = 0; itof[0] = 'N';
    ftoi['E'] = 1; itof[1] = 'E';
    ftoi['S'] = 2; itof[2] = 'S';
    ftoi['W'] = 3; itof[3] = 'W';

    mem(valid, false);

    while( cin >> cntx >> cnty >> face ){
        cin >> str;

        d = ftoi[face];

        flag = false;
        for( int i = 0 ; i < str.size() ; ++i ){
            // cout << cnt[0] << " " << cnt[1] << "\n";
            
            if( str[i] == 'F' ){
                // nxt = { cnt[0] + dir[ftoi[face]][0], cnt[1] + dir[ftoi[face]][1] };
                // nxt[0] = cnt[0] + dx[d];
                // nxt[1] = cnt[1] + dy[d];
                nxtx = cntx + dx[d];
                nxty = cnty + dy[d];

                // if( nxt[0] < 0 || nxt[0] > w || nxt[1] < 0 || nxt[1] > h ){
                //     if( valid[cnt[0]][cnt[1]] ) continue;
                //     valid[cnt[0]][cnt[1]] = true;
                //     flag = true;
                // }else{
                //     cnt[0] = nxt[0];
                //     cnt[1] = nxt[1];
                // }
                if( nxtx < 0 || nxtx > w || nxty < 0 || nxty > h ){
                    if( valid[cntx][cnty] ) continue;

                    valid[cntx][cnty] = true;
                    flag = true;
                }else{
                    cntx = nxtx;
                    cnty = nxty;
                }
            }else if( str[i] == 'R' ){
                d = (d + 1) % 4;
            }else if( str[i] == 'L' ){
                d = (d + 3) % 4;
            }
        }

        // if( flag ) cout << cnt[0] << " " << cnt[1] << " " << itof[d] << " LOST\n";
        // else cout << cnt[0] << " " << cnt[1] << " " << itof[d] << "\n";
        if( flag ) cout << cntx << " " << cnty << " " << itof[d] << " LOST\n";
        else cout << cntx << " " << cnty << " " << itof[d] << "\n";
    }
}