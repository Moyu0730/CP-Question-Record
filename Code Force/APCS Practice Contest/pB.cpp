/* Question : APCS Practice Contest - B - Ladder String */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define priq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e3 + 50;
const int Mod = 1e9 + 7;
string str[MAXN], cnt, cmp;
int n, m, q, tp, x, y;
bool flag;

string valid( int a, int b ){
    string tmp = "";

    tmp.pb(str[a][b]);
    while( a < n && b < m ){
        a++;
        if( a >= n ) break;
        tmp.pb(str[a][b]);

        b++;
        if( b >= m ) break;
        tmp.pb(str[a][b]);
    }

    return tmp;
}

signed main(){
    opt;
    cin >> n >> m >> q;
    for( int i = 0 ; i < n ; i++ ) cin >> str[i];
    
    for( int t = 0 ; t < q ; t++ ){
        cin >> tp;

        if( tp == 1 ){
            cin >> x >> y;
            x--; y--;
            for( int ci = 0 ; ci < n ; ci++ ) str[ci][y] = ( str[ci][y] - 97 + 1 ) % 26 + 97;
            for( int cj = 0 ; cj < m ; cj++ ){
                if( cj == y ) continue;
                str[x][cj] = ( str[x][cj] - 97 + 1 ) % 26 + 97;
            }
        }else{
            cin >> cnt;

            flag = false;
            for( int i = 0 ; i < n ; i++ ){
                for( int j = 0 ; j < m ; j++ ){
                    if( str[i][j] != cnt[0] ) continue;

                    cmp = valid(i, j);
                    if( cmp == cnt ){
                        cout << i+1 << " " << j+1 << "\n";
                        cmp.clear();
                        flag = true;
                        break;
                    }
                }   
                if( flag ) break;
            }
        }
    }
}