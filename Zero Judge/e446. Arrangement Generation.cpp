/* Question : ZeroJudge e446. Arrangement Generation */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mem(x, value) memset(x, value, sizeof(x));
#define maxint 0x3F
#define pii pair<int, int>
#define pdd pair<double, double>
#define f first
#define s second

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 10 + 50;
const int Mod = 1e9 + 7;
int n, ans[MAXN];
bool visited[MAXN];

void nextPermutation( int level ){
    if( level == n+1 ){
        for( int i = 1 ; i <= n ; i++ ) printf("%d ", ans[i]);
        printf("\n");
        return;
    }

    for( int i = 1 ; i <= n ; i++ ){
        if( visited[i] == true ) continue;
        visited[i] = true;
        ans[level] = i;
        nextPermutation(level+1);
        visited[i] = false;
    }
}

signed main(){
    opt;
    mem(visited, false);
    scanf("%d", &n);
    nextPermutation(1);
}