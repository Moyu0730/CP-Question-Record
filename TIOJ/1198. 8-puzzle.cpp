/* Question : TIOJ 1198. 8-puzzle */

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
#define int long long

#define n 9

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 9 + 50;
const int Mod = 1e9 + 7;
map<vector<int>, int> used;
queue<vector<int>> q;
vector<int> st, ed;

signed main(){
	opt;
	int x;
    st.resize(10);
    ed.resize(10);
	for ( int i = 0 ; i < n ; i++ ) cin >> st[i];
	for ( int i = 0 ; i < n ; i++ ) cin >> ed[i];
	q.push(st);
	
	while ( !q.empty() ){
		vector<int> cnt = q.front(); 
        q.pop();
		int emp = 0, cntd = used[cnt];

		while ( cnt[emp] ) emp++; // Find the Empty Space

		if ( emp >= 3 ) { // If Available to Go Up
			swap( cnt[emp], cnt[emp-3] );
			if ( !used[cnt] ){
                used[cnt] = cntd+1;
                q.push(cnt);
            }
			if ( cnt == ed ) break;
			swap( cnt[emp], cnt[emp-3] );
		}

		if ( emp <= 5 ) { // If Available to Go Down
			swap(cnt[emp], cnt[emp+3]);
			if ( !used[cnt] ){
                used[cnt] = cntd+1;
                q.push(cnt);
            }
			if ( cnt == ed ) break;
			swap(cnt[emp], cnt[emp+3]);
		}

		if ( emp % 3 != 0 ) { // If Available to Go Right
			swap(cnt[emp], cnt[emp-1]);
			if ( !used[cnt] ){
                used[cnt] = cntd+1;
                q.push(cnt);
            }
			if ( cnt == ed ) break;
			swap(cnt[emp], cnt[emp-1]);
		}

		if ( emp % 3 != 2 ) { // If Available to Go Left
			swap(cnt[emp], cnt[emp+1]);
			if ( !used[cnt] ){
                used[cnt] = cntd+1;
                q.push(cnt);
            }
			if ( cnt == ed ) break;
			swap(cnt[emp], cnt[emp+1]);
		}
	}
	cout << used[ed] << "\n";
	return 0;
}

/*****BAD Version*****/
// const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
// const int MAXN = 9 + 50;
// const int Mod = 1e9 + 7;
// int st, nxt, res;
// bool flag;
// vector<vector<int>> visited;
// vector<int> arr, t;

// void Enu( int cnt, int step, vector<int> &state ){
//     if( cnt > n || cnt <= 0 ) return;
//     if( step >= 15 ) return;

//     // cout << cnt << " | " << visited.size() << " | ";
//     // for( auto i : state ){
//     //     cout << i << " ";
//     // }
//     // cout << "\n";

//     for( int i = 1 ; i <= n ; i++ ){
//         if( state[i] != t[i] ){
//             break;
//         }
//         if( state[i] == t[i] && i == n ){
//             cout << res << " ";
//             res = min(step, res);
//             return;
//         }
//     }

//     for( auto dif : visited ){
//         bool fg = true;
//         for( int i = 1 ; i <= n ; i++ ){
//             if( state[i] != dif[i] ){
//                 fg = false;
//                 break;
//             }
//         }
//         if( fg == true ) return;
//     }

//     visited.pb(state);

//     if( cnt % 3 != 0 ){
//         // cout << cnt << " 1\n";
//         swap( state[cnt], state[cnt+1] );
//         Enu( cnt+1, step+1, state );
//         swap( state[cnt], state[cnt+1] );
//     }

//     if( cnt % 3 != 1 ){
//         // cout << cnt << " 2\n";
//         swap( state[cnt], state[cnt-1] );
//         Enu( cnt-1, step+1, state );
//         swap( state[cnt], state[cnt-1] );
//     }
    
//     if( cnt > 3 ){
//         // cout << cnt << " 3\n";
//         swap( state[cnt], state[cnt-3] );
//         Enu( cnt-3, step+1, state );
//         swap( state[cnt], state[cnt-3] );
//     }
    
//     if( cnt < 7 ){
//         // cout << cnt << " 4\n";
//         swap( state[cnt], state[cnt+3] );
//         Enu( cnt+3, step+1, state );
//         swap( state[cnt], state[cnt+3] );
//     }
// }

// signed main(){
//     // opt;
//     arr.resize(10);
//     t.resize(10);
//     for( int i = 1 ; i <= n ; i++ ){
//         cin >> arr[i];
//         if( arr[i] == 0 ) st = i;
//     }
//     for( int i = 1 ; i <= n ; i++ ) cin >> t[i];

//     res = 1e9;
//     Enu(st, 0, arr);
//     cout << res << "\n";
// }