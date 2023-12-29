/* Question : TCIRC d014. AP325 Q-2-5. Exponentiation by Squaring with Fibonacci Numbers */

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
int n;

vector<vector<int>> mt( vector<vector<int>> &A, vector<vector<int>> &B ){
    vector<vector<int>> res = {  {0, 0, 0},
                                 {0, 0, 0}, 
                                 {0, 0, 0} };

    res[1][1] = ( ( A[1][1] * B[1][1] ) % Mod + ( A[1][2] * B[2][1] ) % Mod ) % Mod;
    res[2][1] = ( ( A[2][1] * B[1][1] ) % Mod + ( A[2][2] * B[2][1] ) % Mod ) % Mod;
    res[1][2] = ( ( A[1][1] * B[1][2] ) % Mod + ( A[1][2] * B[2][2] ) % Mod ) % Mod;
    res[2][2] = ( ( A[2][1] * B[1][2] ) % Mod + ( A[2][2] * B[2][2] ) % Mod ) % Mod;

    return res;
}

int ksm( int power ){
    int f[2] = {0, 1};
    vector<vector<int>> matrix = {  {0, 0, 0},
                                    {0, 1, 1}, 
                                    {0, 1, 0} };

    vector<vector<int>> res = {  {0, 0, 0},
                                 {0, 1, 1}, 
                                 {0, 1, 0} };             

    power -= 2;
    while( power > 0 ){
        if( power & 1 ){
            res = mt(res, matrix);
        }

        matrix = mt(matrix, matrix);
        power >>= 1;
    }

    return ( ( res[1][1] * f[1] ) % Mod + ( res[1][2] * f[0] ) % Mod ) % Mod;
}

signed main(){
    opt;
    while( cin >> n ){
        if( n == -1 ) break;
        cout << ksm(n) << "\n";
    }
}