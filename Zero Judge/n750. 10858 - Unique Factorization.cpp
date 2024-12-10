/* Question : ZeroJudge n750. 10858 - Unique Factorization */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pirq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define F first
#define S second
#define X first
#define Y second
#define int long long
#define ll long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 2e7 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;

vector<int> prime, sep, path;
set<vector<int>> res;
bool used[MAXN];
int n;

void getPrime(){
    mem(used, true);
    
    used[0] = false;
    used[1] = false;

    for( int i = 2 ; i < MAXN ; ++i ){
        if( used[i] ){
            prime.pb(i);
            int cnt = i + i;

            while( cnt < MAXN ){
                used[cnt] = false;
                cnt += i;
            }
        }
    }
}

void dfs( int val ){
    if( val == 1 && path.size() != 0 ){
        if( path.size() != 1 ) res.insert(path);
        return;
    }

    int st = path.size() == 0 ? 2 : path.back();

    for( int i = st ; i <= val ; ++i ){
        if( val % i == 0 ){
            path.pb(i);
            dfs(val / i);
            path.pop_back();
        }
    }
}

signed main(){
    opt;

    getPrime();

    while( cin >> n && n != 0 ){
        if( used[n] == true || n == 1 ){
            cout << "0\n";
            continue;
        }

        path.clear();
        res.clear();
        
        dfs(n);

        cout << res.size() << "\n";
        for( auto st : res ){
            for( auto it : st ) cout << it << " ";
            cout << "\n";
        }
        // cout << res.size() << "\n";
    }
}