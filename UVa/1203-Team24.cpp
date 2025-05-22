#include<bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define F first
#define S second

priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
string str;
int n, p, k;

signed main(){
    while( cin >> str && str[0] != '#' ){
        cin >> n >> p;
        pq.push({p, {n, p}});
    }

    cin >> k;

    while( k-- ){
        int cnt = pq.top().F;
        int period = pq.top().S.S;
        int num = pq.top().S.F;
        pq.pop();

        cout << num << "\n";

        pq.push({cnt + period, {num, period}});
    }
}
