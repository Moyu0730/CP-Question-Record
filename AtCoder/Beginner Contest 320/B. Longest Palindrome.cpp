/* Question : AtCoder Beginner Contest 320 - B - Longest Palindrome */

#include<bits/stdc++.h>
using namespace std;

#define T(x) ((x) % 2 ? s[(x) / 2] : '.')

string s;
int n;

int ex(int l, int r){
    int i = 0;
    while(l - i >= 0 && r + i < n && T(l - i) == T(r + i)) i++;
    return i;
}

int main(){
    cin >> s;
    n = 2 * s.size() + 1;

    int mx = 0;
    int center = 0;
    vector<int> r(n);
    int ans = 1;
    r[0] = 1;
    for(int i = 1; i < n; i++){
        int ii = center - (i - center);
        int len = mx - i + 1;
        if(i > mx){
            r[i] = ex(i, i);
            center = i;
            mx = i + r[i] - 1;
        }
        else if(r[ii] == len){
            r[i] = len + ex(i - len, i + len);
            center = i;
            mx = i + r[i] - 1;
        }
        else{
            r[i] = min(r[ii], len);
        }
        ans = max(ans, r[i]);
    }

    cout << ans - 1 << "\n";
    return 0;
}