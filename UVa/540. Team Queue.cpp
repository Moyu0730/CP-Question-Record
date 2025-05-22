#include<bits/stdc++.h>
using namespace std;

#define pii apir<int, int>
#define pb(x) push_back(x)
#define F first
#define S second
#define mem(x, val) memset(x, val, sizeof(x))

const int MAXN = 1e6 + 50;

int n, amt, val, counter, arr[MAXN];
vector<queue<int>> v;
queue<int> q;
map<int, int> mp;
string op;

int main(){
    while( cin >> n && n != 0 ){
        ++counter;
        v.clear();
        v.resize(n + 5);
        while( !q.empty() ){
            q.pop();
        }

        for( int i = 0 ; i < n ; ++i ){
            cin >> amt;

            for( int j = 0 ; j < amt ; ++j ){
                cin >> val;
                arr[val] = i;
            }
        }

        cout << "Scenario #" << counter << "\n";
        while( cin >> op && op != "STOP" ){
            if( op == "ENQUEUE" ){
                cin >> val;

                if( v[arr[val]].empty() ) q.push(arr[val]);

                v[arr[val]].push(val);
            }else{
//                if( q.empty() ) continue;

                int cnt = q.front();

                while( v[cnt].empty() ){
                    q.pop();
                    cnt = q.front();
                }

                cout << v[cnt].front() << "\n";
                v[cnt].pop();

                if( v[cnt].empty() ) q.pop();
            }
        }

        cout << "\n";
    }
}
