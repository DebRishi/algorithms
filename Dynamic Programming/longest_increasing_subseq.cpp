#include<iostream>
#include<vector>
using namespace std;

// DP + BIRNARY SEARCH [ NlogN ]
int longestIncreasingSubsequence(vector<int> & nums) {
    vector<int> temp;
    for(int i : nums) {
        if(temp.size() == 0 || temp.back() < i)
            temp.push_back(i);
        else
            *lower_bound(temp.begin(),temp.end(),i) = i;
    }
    return temp.size();
}

// DYNAMIC PROGRAMMING [ N^2 ]
// int longestIncreasingSubsequence(vector<int> & num) {
//     int n = num.size();
//     vector<int> dp(n,1);
//     for(int i = 0 ; i < n ; i++) {
//         for(int j = i+1 ; j < n ; j++) {
//             if(num[j] > num[i] && dp[j] <= dp[i]) {
//                 dp[j] = 1+dp[i];
//             }
//         }
//     }
//     int ans = 1;
//     for(int i : dp) {
//         ans = max(ans,i);
//     }
//     return ans;
// }

int main() {
    vector<int> num = {10,9,2,5,3,7,101,18};
    cout<<longestIncreasingSubsequence(num)<<endl;
    return 0;
}