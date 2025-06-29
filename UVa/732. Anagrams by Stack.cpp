#include<bits/stdc++.h>
using namespace std;

#define MEM(_array, _value) mem(_array, _value, sizeof(_array))
#define sz size()
#define pb push_back
#define pii pair<int, int>
#define F first
#define S second

auto dir = vector<pii> { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 2e4 + 50;

string a, b;
char op[MAXN];
stack<char> st;

void dfs( int s, int t ){
    if( s + t == 2 * b.sz ){
        for( int i = 0 ; i < 2 * b.sz - 1 ; ++i ) cout << op[i] << " ";
        cout << op[2 * b.sz - 1] << "\n";

        return;
    }

    if( s < a.sz ){
        op[s + t] = 'i';
        st.push(a[s]);
        dfs(s + 1, t);
        st.pop();
    }

    if( s > t && st.top() == b[t] ){
        op[s + t] = 'o';
        st.pop();
        dfs(s, t + 1);
        st.push(b[t]);
    }

    return;
}

int main(){
    while( cin >> a >> b ){
        cout << "[\n";

        if( a.sz == b.sz ) dfs(0, 0);

        cout << "]\n";
    }
}
