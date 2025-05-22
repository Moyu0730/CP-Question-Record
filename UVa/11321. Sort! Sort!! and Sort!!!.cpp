#include<bits/stdc++.h>
using namespace std;

#define vsort(x) sort(x.begin(), x.end())
#define int long long
#define F first
#define S second
#define pii pair<int, int>
#define pb(val) push_back(val)

const int MAXN = 1e9 + 7;
const int Mod = 1e7 + 9;

int n, m, x;
vector<int> arr;
vector<pii> res;

bool cmp( pii a, pii b ){
    if( a.F != b.F ) return a.F < b.F;

    if( a.S % 2 == 0 ){
        if( b.S % 2 == 0 ) return a.S < b.S;
        else return false;
    }else{
        if( b.S % 2 == 0 ) return true;
        else return a.S > b.S;
    }
}

signed main(){
    while( cin >> n >> m && n != 0 && m != 0 ){
        res.clear();

        for( int i = 0 ; i < n ; ++i ){
            cin >> x;

            pii tmp = {x % m, x};

            res.pb(tmp);
        }

        sort(res.begin(), res.end(), cmp);

        cout << n << " " << m << "\n";
        for( auto i : res ) cout << i.S << "\n";
    }

    cout << "0 0\n";
}
