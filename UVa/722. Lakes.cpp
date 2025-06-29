#include<bits/stdc++.h>
using namespace std;

#define MEM(_array, _value) memset(_array, _value, sizeof(_array))
#define sz size()
#define pii pair<int, int>
#define F first
#define S second

auto dir = vector<pii> { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e2 + 50;

int T, idx;
pii st;
string str;
string grid[MAXN];
bool used[MAXN][MAXN], check;

void tran( string str ){
    for( int i = 0 ; i < str.sz ; ++i ){
        if( str[i] == ' ' ){
            st.F = stoi(str.substr(0, i));
            st.S = stoi(str.substr(i+1, str.size()-i));
            break;
        }
    }
}

int dfs( pii cnt ){
    int tmp = 0;
    for( int t = 0 ; t < 4 ; ++t ){
        pii nxt = { cnt.F + dir[t].F, cnt.S + dir[t].S };

        if( nxt.F < 0 || nxt.F >= idx || nxt.S < 0 || nxt.S >= grid[0].sz ) continue;
        if( used[nxt.F][nxt.S] ) continue;
        if( grid[nxt.F][nxt.S] == '1' ) continue;

        ++tmp;
        used[nxt.F][nxt.S] = true;
        tmp += dfs(nxt);
    }

    return tmp;
}

int main(){
    cin >> T;
    cin.ignore();

    getline(cin, str);
    while( T-- ){
        MEM(used, false);

        getline(cin, str);
        tran(str);

        idx = 0;
        while( getline(cin, str) && str != "" ){
            grid[idx] = str;
            ++idx;
        }

        --st.F;
        --st.S;

        used[st.F][st.S] = true;
        int res = dfs(st) + 1;

        if( check == false ){
            cout << res<<"\n";
            check = true;
        }else{
            cout << "\n" << res<<"\n";
        }
    }
}
