/* Question : AtCoder Beginner Contest 325 - E. Our Clients, Please Wait a Moment */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define f first
#define s second
#define pb push_back
#define pirq(type) priority_queue<type, vector<type>, greater<type>>
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e3 + 50;
const int Mod = 1e9 + 7;
bool used[MAXN];
int n, m, a, b, c, w, dis[MAXN], disa[MAXN], disb[MAXN], graph[MAXN][MAXN];

void dij( int root, bool tp ){
    mem(dis, 0x3F);
    mem(used, false);

    pirq(pii) pq;
    pq.push({0, root});
    dis[root] = 0;

    while( !pq.empty() ){
        int node = pq.top().s;
        pq.pop();
        
        if( used[node] ) continue;
        used[node] = true;

        for( int i = 1 ; i <= n ; i++ ){
			int val = (tp == 0 ? graph[node][i] * a : graph[node][i] * b + c);

			if(dis[i] > dis[node] + val){
				dis[i] = dis[node] + val;
				pq.push({dis[i], i});
			}
		}
    }

    if( tp == 0 ) for( int i = 1 ; i <= n ; i++ ) disa[i] = dis[i];
	else for( int i = 1 ; i <= n ; i++ ) disb[i] = dis[i];

    return;
}

signed main(){
    opt;
    cin >> n >> a >> b >> c;

    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= n ; j++ ) cin >> graph[i][j];
    }

    dij(1, 0);
    dij(n, 1);

    int res = disa[n];
	for(int i = 1; i <= n; i++){
		res = min(res, disa[i] + disb[i]);
	}
	cout << res << endl;
}