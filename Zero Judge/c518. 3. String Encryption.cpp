/* Question : ZeroJudge c518. 3. String Encryption */

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
int p, m;
string str, before, after;
string origin = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
string code = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

void replace( char a, char b ){
    for( int i = 0 ; i < code.size() ; i++ ){
        if( code[i] == a ) code[i] = b;
    }

    return;
}

signed main(){
    opt;
    cin >> p >> m;
    cin >> str >> before >> after;
    for( int i = 0 ; i < m ; i++ ) replace(before[i], after[i]);
    
    for( int i = 0 ; i < str.size() ; i++ ){
        for( int j = 0 ; j < origin.size() ; j++ ){
            if( origin[j] == str[i] ){
                cout << code[j];
                break;
            }
        }
    }

    cout << "\n";
}