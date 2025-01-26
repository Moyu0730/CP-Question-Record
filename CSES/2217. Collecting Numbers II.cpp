/* Question : CSES 2216. Collecting Numbers */

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
#define x first
#define y second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
int n, q, a, b, res, arr[MAXN], idx[MAXN];

int check( int qa, int qb ){
    int preA = idx[qa];
    int preB = idx[qb];
    int dif = 0;
    
    swap( idx[arr[a]], idx[arr[b]] );

    int newA = idx[qa];
    int newB = idx[qb];
    int flag = qa > qb ? -1 : 1;

    if( preA < preB && newA > newB ) dif += 1 * flag;
    if( preA > preB && newA < newB ) dif -= 1 * flag;

    swap( idx[arr[a]], idx[arr[b]] );

    return dif;
}

signed main(){
    opt;
    cin >> n >> q;
    for( int i = 0 ; i < n ; i++ ){
        cin >> arr[i+1];
        idx[arr[i+1]] = i+1;
    }

    for( int i = 2 ; i <= n ; ++i ){
        if( idx[i] < idx[i-1] ) ++res;
    }
    ++res;

    for( int i = 0 ; i < q ; ++i ){
        cin >> a >> b;

        res += arr[a] == 1 ? 0 : check(arr[a], arr[a]-1);
        res += arr[a] == n ? 0 : check(arr[a], arr[a]+1);
        res += arr[b] == 1 ? 0 : check(arr[b], arr[b]-1);
        res += arr[b] == n ? 0 : check(arr[b], arr[b]+1);

        if( abs( arr[a] - arr[b] ) == 1 ) res += check(arr[a], arr[b]) * -1;

        swap( idx[arr[a]], idx[arr[b]] );
        swap( arr[a], arr[b] );
        
        cout << res << "\n";
    }
}