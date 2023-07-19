/* Question : CSES 1090. Ferris Wheel */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define f first
#define s second

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
int n, w, used, res, tmp, ind, point, last, arr[MAXN];
int visited[MAXN];

signed main(){
    opt;
    cin >> n >> w;
    for( int i = 0 ; i < n ; i++ ) cin >> arr[i];

    sort(arr, arr + n);
    
    mem(visited, false);
    ind = n-1;
    while( used < n ){
        tmp = w;
        tmp -= arr[ind];
        visited[ind] = true;
        if( tmp >= arr[0] ){
            int point = upper_bound(arr, arr+n-(n-ind), tmp) - arr;
            for( int i = point ; i >= 0 ; i-- ){
                if( visited[i] == true || tmp < arr[i] ) continue;
                visited[i] = true;
                used++;
                break;
            }
        }
        used++;
        ind--;
        res++;
    }

    cout << res << "\n";
}