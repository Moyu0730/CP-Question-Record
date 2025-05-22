#include<bits/stdc++.h>
using namespace std;

#define int long long

int n, k, x, res;
multiset<int> mst;

signed main(){
    while( cin >> n && n != 0 ){
        mst.clear();
        res = 0;
        for( int i = 0 ; i < n ; ++i ){
            cin >> k;

            for( int j = 0 ; j < k ; ++j ){
                cin >> x;
                mst.insert(x);
            }

            res += *mst.rbegin() - *mst.begin();

            mst.erase(mst.find(*mst.rbegin()));
            mst.erase(mst.find(*mst.begin()));
        }

        cout << res << "\n";
    }

}
