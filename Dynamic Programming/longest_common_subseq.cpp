#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// TABULATION
class Solution {
    public:
    int longestCommonSubsequence(string str1,string str2) {
        int n1 = str1.length();
        int n2 = str2.length();
        int r = n1+1;
        int c = n2+1;
        string subseq = "";
        vector<vector<int>> dp(r,vector<int> (c,0));
        for(int i = 0 ; i < n1 ; i++) {
            for(int j = 0 ; j < n2 ; j++) {
                if(str1[i] == str2[j])
                    dp[i+1][j+1] = 1 + dp[i][j];
                else
                    dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
            }
        }
        // string subsequence = "";
        // int i = n1;
        // int j = n2;
        // while(i > 0 && j > 0) {
        //     if(str1[i-1] == str2[j-1]) {
        //         subsequence += str1[i-1];
        //         i--;
        //         j--;
        //     }
        //     else if(dp[i][j-1] > dp[i-1][j] ) {
        //         j--;
        //     }
        //     else {
        //         i--;
        //     }
        // }
        // reverse(subsequence.begin(),subsequence.end());
        // cout<<subsequence<<endl;
        return dp[r-1][c-1];
    }
};

// MEMORIZATION
// class Solution {
//     public:
//     vector<vector<int>> memo;
    
//     int helper(string str1,string str2,int i = 0,int j = 0) {
//         int n1 = str1.length();
//         int n2 = str2.length();
//         if(i == n1 || j == n2)
//             return 0;
//         if(memo[i][j] != -1)
//             return memo[i][j];
//         if(str1[i] == str2[j])
//             return memo[i][j] = 1 + helper(str1,str2,i+1,j+1);
//         else
//             return memo[i][j] = max(helper(str1,str2,i+1,j),helper(str1,str2,i,j+1));
//     }
    
//     int longestCommonSubsequence(string str1,string str2) {
//         int n1 = str1.length();
//         int n2 = str2.length();
//         memo = vector<vector<int>> (n1,vector<int> (n2,-1));
//         return helper(str1,str2);
//     }
// };

int main() {
    string str1 = "ABCDGH";
    string str2 = "AEDFHR";
    Solution s;
    cout<<s.longestCommonSubsequence(str1,str2)<<endl;
    return 0;
}