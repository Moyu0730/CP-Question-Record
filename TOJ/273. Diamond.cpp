/* Question : OJ Number */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define priq(type) priority_queue<type, vector<type>, greater<type>>
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
int n, cnt;

signed main(){
    opt;
    cin >> n;
    while( n-- ){
        cin >> cnt;
        int wide = ( cnt * 2 ) - 1;
        
        // Top
        for( int i = 1 ; i <= cnt ; i++ ){
            for( int j = 1 ; j <= (wide - (i * 2 - 1)) / 2 ; j++ ) cout << " ";
            for( int j = 0 ; j < (i * 2 - 1) ; j++ ){
                int dif = abs(j - (i * 2 - 1) / 2);
                cout << char('A'+dif+cnt-i);
            }
            cout << "\n";
        }

        // Bottom
        for( int i = 1 ; i <= cnt-1 ; i++ ){
            for( int j = 1 ; j <= i ; j++ ) cout << " ";
            for( int j = 0 ; j < (wide-(i*2)) ; j++ ){
                int dif = abs(j - ((wide-(i*2))/2));
                cout << char('A'+dif+i);
            }
            cout << "\n";
        }
    }
}