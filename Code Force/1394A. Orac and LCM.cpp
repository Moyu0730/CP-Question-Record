/* Question : CF 1394A. Orac and LCM */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pirq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define f first
#define s second

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e5 + 50;
const int Mod = 1e9 + 7;
int n, ans, arr[MAXN];
set<int> ready;
vector<pii> vec;

int ksm( int base, int power ){
    int ans = 1;
    while( power > 0 ){
        if( power & 1 ){
            ans = ( ans * base );
        }
        power >>= 1;
        base = ( base * base );
    }

    return ans;
}

vector<pii> factor( int num ){
    vector<pii> tmp;
    int cnt, amount;
    int val = num; 
    for( int i = 2 ; i <= num / 2 ; i++ ){
        cnt = 0, amount = 0;
        while( val % i == 0 ){
            if( val <= 1 ) break;
            cnt = i;
            amount++;
            val /= i;
        }

        if( cnt != 0 ){
            tmp.pb({cnt, amount});
            // cnt = val / ksm(cnt, amount);
            // amount = 0;
            // while( val % cnt == 0 ){
            //     if( val == 0 ) break;
            //     amount++;
            //     val /= cnt;
            // }
            // tmp.pb({cnt, amount});
        }
    }

    if( tmp.size() == 0 ) tmp.push_back({val, 1});
    return tmp;
}

signed main(){
    // opt;
    cin >> n;
    vec.resize(2e5+10);
    for( int i = 0 ; i < n ; i++ ) cin >> arr[i];

    vector<pii> a = factor(arr[0]);

    for( auto i : a ){
        vec[i.f] = {i.s, 1};
        ready.insert(i.f);
        // cout << i.f << " " << i.s << "\n";
    }
    
    for( int i = 1 ; i < n ; i++ ){
        for( auto j = ready.begin() ; j != ready.end() ; ){
            if( arr[i] == 0 ) break;
            if( arr[i] % *j == 0 ){
                int amount = 0;
                vec[*j].s++;
                if( arr[i] == 1 && *j == 1 ) break;
                while( arr[i] % *j == 0 ){
                    if( arr[i] <= 1 ) break;
                    amount++;
                    arr[i] /= *j;
                }
                vec[*j].f = max( vec[*j].f, amount );
            }
            j++;
        }
        if( arr[i] > 1 ){
            vector<pii> t = factor(arr[i]);
            for( auto i : t ){
                ready.insert(i.f);
                vec[i.f] = {i.s, 1};
            }
        }
    }

    ans = 1;
    for( int i = 0 ; i < vec.size() ; i++ ){
        if( vec[i].s >= n-1 ){
            cout << i << " " << vec[i].f << "\n";
            ans *= ksm(i, vec[i].f);
        }
    }

    cout << ans << "\n";
}