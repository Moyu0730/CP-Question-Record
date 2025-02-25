/* Question : UVa 12439. February 29 */

#include<bits/stdc++.h>
using namespace std;

/* Pragma */
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

/* Self Define */
#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pirq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define sortV(x) sort(x.begin(), x.end());
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
const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;
const int MEMINF = 0x3F;
const int MEMINF_VAL = 0x3F3F3F3F;
const int MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

string converter[13] = {    "",
                            "January", "February",  "March",    "April",
                            "May",     "June",      "July",     "August",
                            "September", "October", "November", "December" };
string input, month, day, year;
int m, y, d, n, arr[50][50];

int cvt( string str ){
    int res = 0;

    for( int i = 0 ; i < str.size() ; ++i ){
        res *= 10;
        res += str[i] - '0';
    }

    return res;
}

void tran( string ipt ){
    month.clear();
    year.clear();
    day.clear();
    d = 0;
    m = 0;
    y = 0;

    int counter = 0;
    for( int i = 0 ; i < ipt.size() ; ++i ){
        if( ipt[i] == ' ' || ipt[i] == ',' ){
            if( counter == 0 ){
                for( int i = 1 ; i <= 12 ; ++i ){
                    if( month == converter[i] ){
                        m = i;
                        break;
                    }
                }
            }
            
            counter++;
        }else if( counter == 0 ) month.pb(ipt[i]);
        else if( counter == 1 ){
            d *= 10;
            d += ipt[i] - '0';
        }else{
            y *= 10;
            y += ipt[i] - '0';
        }
    }

    return;
}

signed main(){
    opt;

    getline(cin, input);

    n = cvt(input);
    for( int it = 0 ; it < n ; ++it ){
        // For Input
        getline(cin, input);
        tran(input);

        int y1 = y;
        int m1 = m;
        int d1 = d;

        getline(cin, input);
        tran(input);

        int y2 = y;
        int m2 = m;
        int d2 = d;

        // For Res
        int res = 0;
        
        if( m1 <= 2 ) --y1;
        if( m2 <= 2 ) --y2;
        if( m2 == 2 && d2 == 29 ) ++y2;
        
        res = ( ( y2 / 4 ) - ( y2 / 100 ) + ( y2 / 400 ) )
                - ( ( y1 / 4 ) - ( y1 / 100 ) + ( y1 / 400 ) );

        cout << "Case " << it+1 << ": " << res << "\n";
    }
}