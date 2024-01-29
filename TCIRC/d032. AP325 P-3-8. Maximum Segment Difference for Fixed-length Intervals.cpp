/* Set Solution */
/* Question : TCIRC d032. AP325 P-3-8. Maximum Segment Difference for Fixed-length Intervals */

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
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
int n, l, dif, arr[MAXN];
multiset<int> st;

signed main(){
    opt;
    cin >> n >> l;
    for( int i = 1 ; i <= n ; i++ ){
        cin >> arr[i];

        if( i <= l ) st.insert(arr[i]);
    }
    
    dif = *st.rbegin() - *st.begin();

    for( int i = l+1 ; i <= n ; i++ ){
        st.erase(arr[i-l]);
        st.insert(arr[i]);
        
        dif = max(dif, *st.rbegin() - *st.begin());
    }

    cout << dif << "\n";
}

/* Monotonic Queue Soluion */
/* Question : TCIRC d032. AP325 P-3-8. Maximum Segment Difference for Fixed-length Intervals */

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
const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
int n, l, dif, res, arr[MAXN];
deque<int> asc, desc;

signed main(){
    opt;
    cin >> n >> l;
    for( int i = 1 ; i <= n ; i++ ){
        cin >> arr[i];
    }

    for( int i = 1 ; i <= n ; i++ ){
        if( i > l && asc.front() == arr[i-l] ) asc.pop_front();
        if( i > l && desc.front() == arr[i-l] ) desc.pop_front();

        if( !asc.empty() ){
            while( !asc.empty() && asc.back() < arr[i] ) asc.pop_back();
        }
        asc.push_back(arr[i]);

        if( !desc.empty() ){
            while( !desc.empty() && desc.back() > arr[i] ) desc.pop_back();
        }
        desc.push_back(arr[i]);

        if( i >= l ) res = max(res, asc.front() - desc.front() );
    }
    cout << res << "\n";
}