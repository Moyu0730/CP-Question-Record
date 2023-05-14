#include<iostream>
#include<iomanip>
#include<vector>
#include<queue>
#include<stack>
#include<math.h>
#include<algorithm>
using namespace std;

#define opt ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long

const int MAXN = 2e5 + 50;
const int Mod = 1e9 + 7;
int n, k, arr[MAXN], mid;

bool valid( int op ){ // Check if op <= k
    int ctn = 0;
    for( int i = mid ; i < n ; i++ ) ctn += max(arr[mid] + op - arr[i], 0LL);
    
    return ctn <= k;
}

signed main(){
    opt;
    cin >> n >> k;
    for( int i = 0 ; i < n ; i++ ) cin >> arr[i];
    sort(arr, arr+n);
    mid = n / 2;

    int s = 1e9, dif = 0;
    while( s > 0 ){
        if( !valid(dif + s) ) s /= 2;
        else dif += s;
    }

    cout << arr[mid] + dif;
}


/********** 3. TLE **********/
// void print(){
//     cout << k << " | ";
//     for( int i = 0 ; i < n ; i++ ){
//         cout << arr[i] << " ";
//     }
//     cout << "\n";
// }

// signed main(){
//     opt;
//     cin >> n >> k;
//     for( int i = 0 ; i < n ; i++ ) cin >> arr[i];
//     sort(arr, arr+n);
//     // print();
//     res = 0;
//     while( k > 0 ){
//         // print();

//         int mid = n/2, top, num, dif, ctn = 0;
//         for( int i = mid+1 ; i < n ; i++ ){
//             if( arr[i] != arr[mid] ){
//                 top = i;
//                 dif = arr[i] - arr[mid];
//                 num = top - mid;
//                 break;
//             }
//             if( i == n-1 ){
//                 dif = 0;
//                 num = n/2 + 1;
//                 break;
//             }
//         }

//         if( dif != 0 ){
//             ctn = num * dif;     
//             if( ctn == k ){
//                 k = 0;
//                 res = arr[mid] + dif;
//             }else if( ctn > k ){
//                 while( ctn > k ){
//                     dif -= 1;
//                     ctn = num * dif;
//                 }
//                 res = arr[mid] + dif;
//             }
//             if( res != 0 ) break;
//             k -= ctn;
            
//             for( int i = mid ; i < top ; i++ ) arr[i] += dif;

//         }else{
//             int t = 1;
//             ctn = MAXN;
//             while( ctn > k ){
//                 ctn = num * t;
//                 if( ctn < k ) t++;
//             }
//             res = ctn == k ? arr[mid] + t : arr[mid] + t - 1;
//             break;
//         }
//     }
//     cout << res;
    /**********/


/********** 2. TLE **********/
// int dif;
// while( k > 0 ){
//     dif = arr[n/2+1] - arr[n/2] + 1  > k ? k : arr[n/2+1] - arr[n/2] + 1;

//     if( dif == 0 ) dif++;
    
//     arr[n/2] += dif;
//     k -= dif;

//     // int ind, max = 0;
//     // for( int i = n/2+1 ; i < n ; i++ ){
//     //     if( arr[i] >= arr[n/2] ){
//     //         swap(arr[i-1], arr[n/2]);
//     //         break;
//     //     }
//     //     if( i == n-1 ) swap(arr[i], arr[n/2]);
//     // }

//     /********** 1. TLE **********/
//     // sort(arr, arr+n);
        /**********/
    
//     // print();
// }
// cout << arr[n/2];
/**********/