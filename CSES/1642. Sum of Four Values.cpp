/* Question : CSES 1642. Sum of Four Values */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pirq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define F first
#define S second
#define X first
#define Y second
#define int long long
#define ll long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;

int n, x;
vector<pii> arr;

signed main(){
    opt;

    cin >> n >> x;

    arr.resize(n);
    for( int i = 0 ; i < n ; i++ ){
        cin >> arr[i].F;
        arr[i].S = i+1;
    }

    sort( arr.begin() , arr.end() );

    int last = n - 1;
    for( int i = 0 ; i <= last - 3 ; i++ ){
        for( int j = i + 1 ; j <= last - 2 ; j++ ){
            int k = j + 1, l = last;

            while( k < l ){
                int sum = arr[i].F + arr[j].F + arr[k].F + arr[l].F;
                if( sum > x ) l--;
                else if( sum < x ) k++;
                else{
                    cout << arr[i].S << " " << arr[j].S << " " << arr[k].S << " " << arr[l].S << "\n";
                    exit(0);
                }
            }
        }
    }

    cout << "IMPOSSIBLE\n";
}