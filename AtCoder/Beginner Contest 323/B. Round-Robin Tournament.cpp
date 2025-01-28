/* Question : AtCoder Beginner Contest 323 - B. Round-Robin Tournament */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define priq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define f first
#define s second
#define int long long

struct cmp{
    bool operator()( const pii &a, const pii &b ) const{
        if( a.f == b.f ) return a.s < b.s;
        else return a.f > b.f;
    }
};

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e2 + 50;
const int Mod = 1e9 + 7;
int n, grade;
string str;
set<pii, cmp> st;

signed main(){
    opt;
    cin >> n;
    for( int i = 1 ; i <= n ; i++ ){
        cin >> str;
        grade = 0;
        for( int j = 0 ; j < (int)str.size() ; j++ ){
            if( str[j] == 'o' ) grade++;
        }

        st.insert({grade, i});
    }

    for( auto i : st ){
        cout << i.s << " ";
    }
}