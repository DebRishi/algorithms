#include<iostream>
#include<vector>
using namespace std;

int maxProductSubarray(vector<int> num) {
    int ans = num[0];
    int imax = num[0];
    int imin = num[0];
    for(int i = 1 ; i < num.size() ; i++) {
        if(num[i] < 0) {
            swap(imax,imin);
        }
        imax = max(num[i],imax*num[i]);
        imin = min(num[i],imin*num[i]);
        ans = max(ans,imax);
    }
    return ans;
}

// int maxProduct(vector<int> & num) {
//     int ans = num[0];
//     int imax = num[0];
//     int imin = num[0];
//     for(int i = 1 ; i < num.size() ; i++) {
//         if(num[i] == 0) {
//             imax = 1;
//             imin = 1;
//             ans = max(ans,0);
//             continue;
//         }
//         int prev = imax;
//         imax = max(num[i],max(imax*num[i],imin*num[i]));
//         imin = min(num[i],min(prev*num[i],imin*num[i]));
//         if(imax > ans) {
//             ans = imax;
//         }
//     }
//     return ans;
// }

int main() {
    vector<int> num = { 6, -3, -10, 0, 2 };
    cout<<maxProductSubarray(num)<<endl;
    return 0;
}