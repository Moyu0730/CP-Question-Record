/* Question : CF ( 2023 MD Subject Ability Intramural Competition ) E. Stock Analyst */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
#define f first 
#define s second

const int MAXN = 1e5 + 50;
const int Mod = 1e9 + 7;
int arr[MAXN];
int n, k;

bool valid( int t ){
    pair<int, int> p;   // { Max, Min }
    int tmp = 0;
    for( int i = 0 ; i < n ; i++ ){
        if( i == 0 ) p = {0, 1e9};

        p.f = max(p.f, arr[i]);
        p.s = min(p.s, arr[i]);
        // cout << i << " " << p.f << " " << p.s << "\n";

        if( abs( p.f - p.s ) > t ){
            tmp++;
            p = {0, 1e9};
            i--;
        }
    }
    
    return tmp+1 <= k;
}

signed main(){
    opt;
    cin >> n >> k;
    for( int i = 0 ; i < n ; i ++ ) cin >> arr[i];

    int step = 1e9, res = 0;
    while( step > 0 ){
        // cout << step + res << " " << valid(step + res)<< "\n";

        if( !valid(step + res) ) res += step;
        else step /= 2;
    }
    res++;
    cout << res << "\n";

    pair<int, int> p; int last = 1;
    for( int i = 0 ; i < n ; i++ ){
        if( i == 0 ) p = {0, 1e9};

        p.f = max(p.f, arr[i]);
        p.s = min(p.s, arr[i]);
        // cout << i << " " << p.f << " " << p.s << "\n";

        if( abs( p.f - p.s ) > res ){
            cout << last << " " << i << "\n";
            last = i+1;
            p = {0, 1e9};
            i--;
        }
    }
    cout << last << " " << n << "\n";
}