/* Question : AtCoder Beginner Contest 320 - E - Somen Nagashi */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pirq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
int n, m, amt[MAXN], nd[MAXN][5];
priority_queue <vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
set<int> st;

signed main(){
    opt;
    cin >> n >> m;

    for( int i = 1 ; i <= n ; i++ ) st.insert(i);
    for( int i = 0 ; i < m ; i++ ){
        cin >> nd[i][0] >> nd[i][1] >> nd[i][2];
        pq.push({nd[i][0], 1000000000, nd[i][1], nd[i][2]});
    }

    while( !pq.empty() ){
        vector<int> cnt = pq.top();
        pq.pop();

        if( cnt.size() == 4 ){
            if( st.empty() == true ) continue;

            int ind = *st.begin();
            st.erase(ind);
            
            amt[ind] += cnt[2];
            pq.push({cnt[0] + cnt[3], -1, ind});
        }else{
            st.insert(cnt[2]);
        }
    }

    for( int i = 1 ; i <= n ; i++ ) cout << amt[i] << "\n";
}