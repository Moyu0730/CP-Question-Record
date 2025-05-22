#include<bits/stdc++.h>
using namespace std;

#define pii apir<int, int>
#define pb(x) push_back(x)
#define F first
#define S second
#define mem(x, val) memset(x, val, sizeof(x))

const int MAXN = 1e6 + 50;

int n;
queue<int> q;

int main(){
    while( cin >> n && n != 0 ){
        for( int i = 1 ; i <= n ; ++i ) q.push(i);

        if( n > 1 ){
            cout << "Discarded cards: ";
        }else{
            cout << "Discarded cards:";
        }

        while( q.size() > 1 ){
            if( q.size() != 2 ) cout << q.front() << ", ";
            else cout << q.front();
            q.pop();

            q.push(q.front());
            q.pop();
        }

        cout << "\nRemaining card: " << q.front() << "\n";
        q.pop();
    }
}
