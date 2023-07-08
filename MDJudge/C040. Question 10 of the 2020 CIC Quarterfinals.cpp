/* Question : MDJudge C040 Question 10 of the 2020 CIC Quarterfinals */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mem(x) memset(x, 0x3F, sizeof(x));
#define f first
#define s second
#define pii pair<int, int>
#define pdd pair<double, double>

const int MAXN = 4 + 50;
const int Mod = 1e9 + 7;
const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
vector< pair<double, double> > point;
double ans = 1e8;
string s;
int arr[] = {1, 2, 3, 4}, a[5];

double dis( pdd a, pdd b ){
    return sqrt( ( a.f - b.f ) * ( a.f - b.f ) + ( a.s - b.s ) * ( a.s - b.s ) );
}

signed main(){
    opt;
    point.resize(4+5);
    for(int i = 1; i <= 4; i++) cin >> point[i].first >> point[i].second;
    double res, ans = 1e18;
    do{
        res = dis( {0.0, 0.0}, point[arr[0]] );
        for(int i = 1; i < 4; i++)
            res += dis( point[arr[i]], point[arr[i-1]] );

        if( ans > res ){
            for(int i = 0; i < 4; i++) a[i] = arr[i];
            ans = res;
        }
    }while( next_permutation(arr, arr + 4) );

    cout << fixed << setprecision(2) << ans << '\n' << 0;
    for(int i = 0 ; i < 4 ; i++) cout << a[i];
}