/* Question : UVa 101. The Blocks Problem */

#include<bits/stdc++.h>
using namespace std;

/* Self Define */
#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pirq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define all(v) v.begin(), v.end()
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
const int MAXN = 25 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;
const int MEMINF = 0x3F;
const int MEMINF_VAL = 0x3F3F3F3F;
const int MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

int n, a, b;
string action, type;
vector<list<int>> pile;

int find_block( int a, int& pile_index ){
    for( int i = 0 ; i < pile.size() ; ++i ){
        for( auto it = pile[i].begin() ; it != pile[i].end() ; ++it ){
            if( *it == a ){
                pile_index = i;
                return distance( pile[i].begin(), it );
            }
        }
    }

    return -1;
}

void return_block( int a, int a_pile ){
    auto it = pile[a_pile].begin();

    while (*it != a) ++it;
    ++it;
    
    while( it != pile[a_pile].end() ){
        int tmp = *it;
        pile[tmp].pb(tmp);
        it = pile[a_pile].erase(it);
    }
}

signed main() {
    opt;

    cin >> n;

    pile.resize(n);
    for( int i = 0 ; i < n ; ++i ) pile[i].pb(i);

    while( cin >> action && action != "quit" ){
        cin >> a >> type >> b;

        if (a == b) continue;

        int a_pile, b_pile;
        int a_index = find_block(a, a_pile);
        int b_index = find_block(b, b_pile);
        if( a_pile == b_pile ) continue;

        if( action == "move" ){
            if( type == "onto" ) return_block(b, b_pile);

            return_block(a, a_pile);

            pile[a_pile].remove(a);
            pile[b_pile].pb(a);
        }else{ // pile
            if( type == "onto" ) return_block(b, b_pile);

            auto it = pile[a_pile].begin();
            advance( it, a_index );

            list<int> moved( it, pile[a_pile].end() );
            
            pile[a_pile].erase( it, pile[a_pile].end());
            pile[b_pile].insert( pile[b_pile].end(), moved.begin(), moved.end() );
        }
    }

    for( int i = 0 ; i < n ; ++i ){
        cout << i << ":";
        for( int b : pile[i] ) cout << " " << b;
        cout << "\n";
    }
}