#include<bits/stdc++.h>
using namespace std;

#define pb(x) push_back(x)
#define all(v) v.begin(), v.end()

int n, m, x, counter;
char op;
list<int> lst;

signed main(){
    while( cin >> n >> m && ( n != 0 && m != 0 ) ){
        cout << "Case " << ++counter << ":\n";
        lst.clear();

        for( int i = 1 ; i <= min(n,m) ; ++i ) lst.pb(i);

        while( m-- ){
            cin >> op;

            if( op == 'N' ){
                cout << *lst.begin() << "\n";

                lst.push_back( *lst.begin() );
                lst.pop_front();
            }else{
                cin >> x;

                lst.remove(x);
                lst.push_front(x);
            }
        }
    }
}
