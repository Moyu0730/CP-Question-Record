/* Question : OJ Number */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define priq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define F first
#define S second
#define X first
#define Y second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
int n, m;
string s, t, res;
bool flag;

signed main(){
    opt;
    cin >> n >> m >> s >> t;

    for( int i = 0 ; i < s.size() - t.size() ; i++ ){
        flag = true;
        for( int j = 0 ; j < t.size() ; j++ ){
            if( s[i+j] != t[j] ){
                if( s[i+j] == '#' ) continue;
                flag = false;
                break;
            }
        }

        if( flag == true ){
            for( int j = 0 ; j < t.size() ; j++ ) s[i+j] = '#';
        }
    }

    for( int i = s.size() - 1 ; i > t.size() ; i-- ){
        flag = true;
        for( int j = 0 ; j < t.size() ; j++ ){
            if( s[i-j] != t[t.size()-j-1] ){
                if( s[i-j] == '#' ) continue;

                flag = false;
                break;
            }
        }

        if( flag == true ){
            for( int j = 0 ; j < t.size() ; j++ ) s[i-j] = '#';
        }
    }

    for( auto i : s ){
        if( i != '#' ){
            cout << "No\n";
            exit(0);
        }
    }

    cout << "Yes\n";
}