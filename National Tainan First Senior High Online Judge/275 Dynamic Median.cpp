/* Question : OJ Number */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long

const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
int n, tmp, mx, mi, val;
multiset<int> l, r;

signed main(){
    opt;
    cin >> n;

    l.insert(-1e18);
    r.insert(1e18);
    while( n-- ){
        cin >> tmp;
        
        mx = *l.rbegin();
        mi = *r.begin();

        if( tmp >= mi ) r.insert(tmp);
        else l.insert(tmp);
        
        int len = r.size() + l.size();
        if( l.size() > len / 2 ){
            val = *l.rbegin();
            r.insert(val);
            l.erase(prev(l.end()));
        }else if( l.size() < len / 2 ){
            val = *r.begin();
            l.insert(val);
            r.erase(r.begin());
        }
        
        double ans = !(len % 2) ? ( *l.rbegin() + *r.begin() ) * 1.0 / 2 : *r.begin();
        cout << fixed << setprecision(6) << ans << "\n";
    }
}