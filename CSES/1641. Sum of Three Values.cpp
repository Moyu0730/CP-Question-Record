/* Question : CSES 1641. Sum of Three Values */

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
const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;

int n, x;
vector<pii> num;

bool valid( int ind, int val ){
    if( ind >= num.size() ) return false;
    if( num[ind].F <= val ) return true;
    else return false;
}

int bs( int val, int x, int y ){
    int res = 0, step = 60000;

    while( step > 0 ){
        if( valid(res+step, val) ) res += step;
        else step /= 2;
    }
    
    if( num[res].F != val ) return -1;

    int tmp = res;
    while( num[tmp].F == num[res].F ){
        if( tmp != x && tmp != y ) return tmp;
        else tmp--;
    }

    return -1;
}

signed main(){
    opt;

    cin >> n >> x;
    
    num.resize(n);
    for( int i = 0 ; i < n ; i++ ){
        cin >> num[i].F;
        num[i].S = i+1;
    }

    sort(num.begin(), num.end());

    // for( int i = 0 ; i < num.size() ; i++ ) cout << i << " ";
    // cout << "\n";
    // for( auto i : num ) cout << i.F << " ";
    // cout << "\n";

    for( int i = 0 ; i < n ; i++ ){
        for( int j = i+1 ; j < n ; j++ ){
            if( num[i].F + num[j].F >= x ) continue;
            
            int ind = bs(x - num[i].F - num[j].F, i, j);
            // cout << ind << " ";
            
            if( ind == -1 ) continue;
            
            cout << num[ind].S << " " << num[i].S << " " << num[j].S << "\n";
            exit(0);
        }
    }

    cout << "IMPOSSIBLE\n";
}