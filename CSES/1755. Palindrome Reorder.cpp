/* Question : CSES 1755. Palindrome Reorder */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pirq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define f first
#define s second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 100 + 50;
const int Mod = 1e9 + 7;
int ch[MAXN];
string str, ans;

signed main(){
    opt;
    cin >> str;
    for( int i = 0 ; i < str.size() ; i++ ) ch[str[i]-'A'+1]++;
    
    int single = -1;
    bool flag = false;
    for( int i = 1 ; i <= 26 ; i++ ){
        if( ch[i] % 2 != 0 ){
            if( single != -1 ){
                flag = true;
                break;
            }
            if( single == -1 ){
                single = i;
                continue;
            }
        }
        for( int j = 1 ; j <= ch[i]/2 ; j++ ) ans.pb(char(i+'A'-1));
    }

    if( flag == true ){
        cout << "NO SOLUTION\n";
    }else{
        if( single != -1 ){
            for( int i = ch[single] ; i > 0 ; i-- ) ans.pb(char(single+'A'-1));
        }

        for( int i = 26 ; i >= 1 ; i-- ){
            if( i == single ) continue;
            for( int j = 1 ; j <= ch[i]/2 ; j++ ) ans.pb(char(i+'A'-1));
        }
        cout << ans << "\n";
    }
}