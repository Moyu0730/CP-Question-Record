/* Question : AtCoder Beginner Contest 323 - C. World Tour Finals */

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
const int MAXN = 1e2 + 50;
const int Mod = 1e9 + 7;
int n, m, ma, point[MAXN], grade[MAXN];
string str, sol[MAXN];
set<pii, greater<pii> > st;

signed main(){
    opt;
    cin >> n >> m;
    for( int i = 0 ; i < m ; i++ ){
        cin >> point[i];
        st.insert({point[i], i});
    }

    ma = -1;
    for( int i = 0 ; i < n ; i++ ){
        cin >> sol[i];
        for( int j = 0 ; j < (int)sol[i].size() ; j++ ){
            if( sol[i][j] == 'o' ) grade[i] += point[j];
        }

        grade[i] += i + 1;
        ma = max(ma, grade[i]);
    }
    
    for( int i = 0 ; i < n ; i++ ){
        int dif = ma - grade[i];
        int num = 0;
        for( auto j : st ){
            if( dif <= 0 ) break;
            if( sol[i][j.s] == 'x' ){
                dif -= j.f;
                num++;
            }
        }
        cout << num << "\n";
    }
}