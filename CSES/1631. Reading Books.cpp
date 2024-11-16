/* Question : CSES 1631. Reading Books */
 
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
#define top front
 
const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 1e8 + 50;
const int Mod = 1e9 + 7;
const long long LLINF = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;
 
int n, res;
vector<int> book;
queue<int> jus, kot;
 
signed main(){
    opt;
    cin >> n;
    book.resize(n);
    for( int i = 0 ; i < n ; i++ ){
      cin >> book[i];
    }
    
    sort( book.begin(), book.end() );
    
    for( int i = 0 ; i < n ; i++ ){
      kot.push(i);
      jus.push(n-i-1);
    }
    
    int tk = 0, tj = 0;
    while( !jus.empty() && !kot.empty() ){
      int jtop = jus.top();
      jus.pop();
      
      tj += book[jtop];
      while( !kot.empty() && tk < tj ){
        int ktop = kot.top();
        kot.pop();
        
        if( ktop == jtop ){
          if( kot.empty() ){
            tk += book[ktop];
            tk = tj;
            tk += book[ktop];
            
            while( !jus.empty() ){
              jtop = jus.top();
              jus.pop();
              tj += book[jtop];
            }
            
            break;
          }else{
            kot.push(jtop);
            continue;
          }
        }
      }
    }
    
    while( !kot.empty() ){
      int ktop = kot.top();
      kot.pop();
      tk += book[ktop];
    }
    
    while( !jus.empty() ){
      int jtop = jus.top();
      jus.pop();
      tj += book[jtop];
    }
    
    cout << max( tk, tj ) << "\n";
}