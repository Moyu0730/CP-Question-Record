/* Question : UVa 195. Anagram */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mem(x) memset(x, 0x3F, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define f first
#define s second

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 10 + 50;
const int Mod = 1e9 + 7;
int n, len;
string str;

void reverseArray( int begin, int end ){
    int dif = end - begin;
    for( int i = 0 ; i < dif / 2 + 1 ; i++ ) swap( str[begin+i], str[end-i] );
}

bool nextPermutation(){
    int p = len - 1; // p stands for Partition Number
    while( p > 0 && str[p] <= str[p-1] ) p--;
    p--;

    if( p == -1 ) return false;

    int c = len - 1; // c stands for Change Number
    while( str[c] <= str[p] ) c--;

    swap(str[c], str[p]);
    reverseArray(p+1, len-1);
    return true;
}   

signed main(){
    opt;
    cin >> n;
    for( int i = 0 ; i < n ; i++ ){
        cin >> str;
        sort(str.begin(), str.end());
        // cout << str;
        len = str.size();
        do{
            cout << str << "\n";
        }while( nextPermutation() );
    }
}