/* Question : AtCoder Beginner Contest 322 - A. First ABC 2 */

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
int n, res;
bool flag;
char ch[3] = {'A', 'B', 'C'};
string str;

signed main(){
    opt;
    cin >> n >> str;

    res = -2;
    for( int i = 0 ; i < str.size() ; i++ ){
        if( str[i] == 'A' ){
            flag = true;
            for( int j = 0 ; j < 3 ; j++ ){
                if( str[i+j] != ch[j] ){
                    flag = false;
                    break;
                }
            }

            if( flag == true ){
                res = i; 
                break;
            }
        }
    }

    cout << res+1 << "\n";
}