/* Question : CSES 1670. Swap Game */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mem(x) memset(x, 0x3F, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define f first
#define s second

string goal = "123456789";
const int x[] = {0, 1, 2, 3, 4, 5, 1, 2, 4, 5, 7, 8};
const int y[] = {3, 4, 5, 6, 7, 8, 0, 1, 3, 4, 6, 7};
const int MAXN = 9e8 + 5;
const int Mod = 1e9 + 7;
int ans;
char ch;
unordered_map<string, bool> used;
string init;
queue<pair<string, int>> q;

signed main(){
    opt;
    for( int i = 0 ; i < 9 ; i++ ){
        cin >> ch;
        init.push_back(ch);
    }

    q.push({init, 0});
    used[init] = true;

    while( !q.empty() ){
        string str = q.front().f;
        int level = q.front().s;
        q.pop();

        if( goal == str ){
            ans = level;
            break;
        }

        for( int i = 0 ; i < 12 ; i++ ){
            swap(str[x[i]], str[y[i]]);

            if( used.find(str) == used.end() ){
                used[str] = true;
                q.push({str, level+1});
            }

            swap(str[x[i]], str[y[i]]);
        }
    }

    cout << ans << "\n";
}