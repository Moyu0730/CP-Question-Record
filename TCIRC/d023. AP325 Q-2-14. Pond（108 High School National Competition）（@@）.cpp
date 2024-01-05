/* Question : TCIRC d023. AP325 Q-2-14. Pond（108 High School National Competition）（@@） */

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
const int MAXN = 1e5 + 50;
const int Mod = 1e9 + 7;
int n, input, w, h[MAXN], res[MAXN];
vector<pii> v;

void rec( int left, int right, int water, int in ){
    if( right - left == 1 ){
        res[left] = water;
        return;
    }

    while( v[v.size()-1].S >= right || v[v.size()-1].S <= left ) v.pop_back();
    pii top = { v[v.size()-1].F, v[v.size()-1].S };
    v.pop_back();

    if( water >= ( right - left ) * top.F ){
        for( int i = left ; i < right ; i++ ) res[i] = water / ( right - left );
        return;
    }

    if( top.S > in ){
        if( water >= ( top.S - left ) * top.F ){
            for( int i = left ; i < top.S ; i++ ) res[i] = top.F;
            rec(top.S, right, water - ( (top.S - left) * top.F ), top.S);
        }else rec(left, top.S, water, in);
    }else{
        if( water >= ( right - top.S ) * top.F ){
            for( int i = top.S ; i < right ; i++ ) res[i] = top.F;
            rec(left, top.S, water - ( right - top.S ) * top.F, top.S-1);
        }else rec(top.S, right, water, in);
    }

    return;
}

signed main(){
    opt;
    cin >> n >> input >> w;
    for( int i = 0 ; i < n ; i++ ){
        cin >> h[i];
        if( i == 0 || i == n-1 ) continue;
        
        v.pb({h[i], i});
    }

    sort(v.begin(), v.end());

    rec(0, n-1, w, input);

    for( int i = 0 ; i < n-1 ; i++ ) cout << res[i] << " \n"[i==n-1];
}