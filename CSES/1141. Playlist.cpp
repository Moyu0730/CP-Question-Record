/* Question : CSES 1141. Playlist */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define priq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define F first
#define S second
#define X first
#define Y second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
int n, res, arr[MAXN];
queue<int> q;
map<long long, bool> mp;

signed main(){
    opt;
    cin >> n;
    for( int i = 0 ; i < n ; i++ ) cin >> arr[i];

    for( int i = 0 ; i < n ; i++ ){
        if( q.empty() ){
            q.push(arr[i]);
            mp[arr[i]] = true;
        }else{
            if( mp.find(arr[i]) != mp.end() && mp[arr[i]] == true ){
                while( q.front() != arr[i] ){
                    mp[q.front()] = false;
                    q.pop();
                }
                mp[q.front()] = false;
                q.pop();
                
                q.push(arr[i]);
                mp[arr[i]] = true;
            }else{
                q.push(arr[i]);
                mp[arr[i]] = true;
            }
        }

        res = max(res, (long long)q.size());
    }

    cout << res << "\n";
}