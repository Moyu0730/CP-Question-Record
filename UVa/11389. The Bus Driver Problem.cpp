#include<bits/stdc++.h>
using namespace std;

#define vsort(x) sort(x.begin(), x.end())
#define int long long
#define F first
#define S second
#define pii pair<int, int>
#define pb(val) push_back(val)

const int MAXN = 1e2 + 7;
const int Mod = 1e7 + 9;

int n, r, d, x, res;
vector<int> m, e;
bool usedm[MAXN], usede[MAXN];

signed main(){
    while( cin >> n >> d >> r && n != 0 && d != 0 && r != 0 ){
        m.clear();
        e.clear();
        res = 0;

        for( int i = 0 ; i < n ; ++i ){
            cin >> x;
            m.pb(x);
        }

        for( int i = 0 ; i < n ; ++i ){
            cin >> x;
            e.pb(x);
        }

        vsort(m);
        vsort(e);

        memset(usedm, false, sizeof(usedm));
        memset(usede, false, sizeof(usede));

        for( int i = 0 ; i < n ; ++i ){
            for( int j = 0 ; j < n ; ++j ){
                if( !usede[j] && m[i] + e[j] == d ){
                    usede[j] = true;
                    usedm[i] = true;
                    break;
                }
            }
        }

        for( int i = 0 ; i < n ; ++i ){
            if( usedm[i] ) continue;

            int last = -1, nxt = -1;
            for( int j = 0 ; j < n ; ++j ){
                if( usede[j] ) continue;

                if( e[j] + m[i] > d ){
                    nxt = j;
                    break;
                }

                last = j;
            }

            if( nxt != -1 ){
                res += e[nxt] + m[i] - d;
                usede[nxt] = true;
            }else{
                usede[last] = true;
            }
        }

        cout << res * r << "\n";
    }
}