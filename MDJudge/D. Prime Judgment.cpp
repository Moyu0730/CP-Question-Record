/* Question : MDJudge D. Prime Judgment */

#include<bits/stdc++.h>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define priq(type) priority_queue<type, vector<type>, greater<type>>
#define mem(x, value) memset(x, value, sizeof(x));
#define pii pair<int, int>
#define pdd pair<double, double>
#define pb push_back
#define F first
#define S second
#define int long long

const auto dir = vector< pair<int, int> > { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int MAXN = 10 + 50;
const int Mod = 1e9 + 7;

bool a[30000010];

int conv(string s){
	int number = 0;
	for( int i = 0 ; i < s.size() ; i++ ){
		number *= 10;
		number += s[i] - '0';
	}
	return number;
}

signed main(){
    opt;
    vector<int> prime;
    for( int i = 2 ; i <= 500000 ; i++ ){
    	if( a[i] == 0 ){
    		prime.pb(i);
    		for( int j = i * i ; j <= 500000 ; j += i ) a[j] = 1;
    	}
    }

    string input;
    getline(cin, input);
    stringstream str(input);
    vector<string> num;
    string tmp;
    while(str >> tmp) num.pb(tmp);
    sort(num.begin(), num.end());

    do{
    	int cnt = 0, ch = 1;
    	string tmp;
    	for( auto i : num ) tmp += i;
    	cnt = conv(tmp);

        for(int i : prime ){
            if( i * i > cnt ) break;
            if( cnt % i == 0 ) ch = 0;
        }
    	if( ch ){
    		cout << tmp;
            return 0;
    	}
    }while(next_permutation(num.begin(),num.end()));
    cout << "-1\n";
}