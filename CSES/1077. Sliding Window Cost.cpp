/* Question : CSES 1077. Sliding Window Cost */

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
#define sortV(x) sort(x.begin(), x.end());
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

int n, k, smallsum, largesum, arr[MAXN];
multiset<int> small, large;

signed main(){
    opt;

    cin >> n >> k;

    for( int i = 0 ; i < n ; ++i ) cin >> arr[i];

    for( int i = 0 ; i < n ; ++i ){
        int len = small.size() + large.size(), mid;

        if( len == 0 ){
            large.insert(arr[i]);
            largesum += arr[i];
        }else{
            if( large.size() != 0 && arr[i] >= *large.begin() ){
                large.insert(arr[i]);
                largesum += arr[i];
            }else{
                small.insert(arr[i]);
                smallsum += arr[i];
            }

            if( large.size() > small.size() ){
                while( large.size() - small.size() > 1 ){
                    smallsum += *large.begin();
                    largesum -= *large.begin();

                    small.insert(*large.begin());
                    large.erase(large.find(*large.begin()));
                }
            }else{
                while( small.size() - large.size() > 1 ){
                    largesum += *small.rbegin();
                    smallsum -= *small.rbegin();
                    
                    large.insert(*small.rbegin());
                    small.erase(small.find(*small.rbegin()));
                }
            }
        }
         
        len = small.size() + large.size();
        
        if( len == k ){
            if( k % 2 == 0 ) mid = *small.rbegin();
            else{
                if( large.size() > small.size() ) mid = *large.begin();
                else mid = *small.rbegin();
            }

            if( k % 2 == 0 ){
                int s = ( largesum - (*small.rbegin() * large.size() ) ) + ( (*small.rbegin() * small.size()) - smallsum );
                int l = ( largesum - (*large.begin() * large.size() ) ) + ( (*large.begin() * small.size()) - smallsum );

                cout << min(s, l) << " ";
            }else{
                cout << ( largesum - (mid * large.size()) ) + ( (mid * small.size()) - smallsum ) << " ";
            }

            if( arr[i-k+1] < mid ){
                small.erase(small.find(arr[i-k+1]));
                smallsum -= arr[i-k+1];
            }else if( arr[i-k+1] > mid ){
                large.erase(large.find(arr[i-k+1]));
                largesum -= arr[i-k+1];
            }else{
                if( k % 2 == 0 ){
                    small.erase(small.find(arr[i-k+1]));
                    smallsum -= arr[i-k+1];
                }else{
                    if( large.size() > small.size() ){
                        large.erase(large.find(arr[i-k+1]));
                        largesum -= arr[i-k+1];
                    }else{
                        small.erase(small.find(arr[i-k+1]));
                        smallsum -= arr[i-k+1];
                    }
                }
            }
        }
    }
}