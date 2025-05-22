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

int q, n, x;
vector<int> arr;

int bbs(){
    int res = 0;
    for( int i = arr.size() - 1 ; i >= 0 ; --i ){
        for( int j = 0 ; j < i ; ++j ){
            if( arr[j+1] < arr[j] ){
                ++res;

                swap(arr[j+1], arr[j]);
            }
        }
    }

    return res;
}

signed main(){
    cin >> q;

    while( q-- ){
        cin >> n;

        arr.clear();
        for( int i = 0 ; i < n ; ++i ){
            cin >> x; arr.pb(x);
        }

        cout << "Optimal train swapping takes " << bbs() << " swaps.\n";
    }
}
