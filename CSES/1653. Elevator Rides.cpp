/* Question : CSES 1653. Elevator Rides */

#include<bits/stdc++.h>
using namespace std;

/* Pragma */
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

/* Self Define */
#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pirq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define vsort(x) sort(x.begin(), x.end());
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
const int MEMINF = 0x3F;
const int MEMINF_VAL = 0x3F3F3F3F;
const int MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

/* Solution 2 - Bitwise DP - N * 2^N */
int n, x;
vector<int> arr;

signed main(){
    opt;

    // Read input values
    cin >> n >> x;
    arr.resize(n);
    for(auto &i : arr) cin >> i;

    // Initialize dp and last arrays
    vector<int> dp(1 << n, 0);
    vector<int> last(1 << n);

    dp[0] = 1; // Base case: no items, one ride needed
    
    // Iterate over all subsets
    for(int bit = 1; bit < (1 << n); ++bit){
        
        // Initialize with a large enough number
        dp[bit] = 21; 
        
        // Iterate over all items
        for(int i = 0; i < n; ++i){

            // Check if the i-th item is included in the current subset
            if(bit & (1 << i)){

                // Previous state
                int ride = dp[bit ^ (1 << i)];
                int weight = last[bit ^ (1 << i)];

                // Check if adding the current item exceeds the weight limit
                if(arr[i] + weight > x){
                    // Need an additional ride
                    ++ride;
                    
                    // Start a new ride with the current item
                    weight = min(weight, arr[i]);
                } else {
                    // Add the current item to the current ride
                    weight += arr[i];
                }

                // Update dp and last arrays
                if(dp[bit] >= ride){
                    last[bit] = (ride == dp[bit]) ? min(last[bit], weight) : weight;
                    dp[bit] = ride;
                }
            }
        }
    }

    // Output the minimum number of rides needed
    cout << dp[(1 << n) - 1] << "\n";
}

/* Soliution 1 - Greedy - WA */
// int n, x, val, cnt, res;
// multiset<int> st;

// signed main(){
//     opt;

//     cin >> n >> x;
//     for( int i = 0 ; i < n ; ++i ){
//         cin >> val;
//         st.insert(val);
//     }

//     cout << "--------\n";
//     for( auto i = st.begin() ; i != st.end() ; ++i ){
//         cout << *i << " ";
//     }
//     cout << "\n--------\n";

//     while( !st.empty() ){
//         cnt = *st.rbegin();

//         cout << *st.rbegin() << " ";
//         st.erase(st.find(*st.rbegin()));

//         while( !st.empty() ){
//             int dif = x - cnt;

//             if( dif < *st.begin() ) break;

//             if( dif > *st.rbegin() ){
//                 cnt += *st.rbegin();

//                 cout << *st.rbegin() << " ";
//                 st.erase(st.find(*st.rbegin()));
//             }else{
//                 auto it = st.lower_bound(dif);

//                 cnt += *it;

//                 cout << *it << " ";
//                 st.erase(st.find(*it));
//             }
//         }
//         cout << "\n";

//         res++;
//     }

//     cout << res << "\n";
// }