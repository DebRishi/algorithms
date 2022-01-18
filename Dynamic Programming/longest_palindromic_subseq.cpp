#include<iostream>
#include<vector>
using namespace std;

// TABULATION
class Solution {
  public:
    int longestPalindromeSubseq(string str) {
        int n = str.size();
        int dp[n][n];
        
        for(int i = 0 ; i < n ; i++)
            dp[i][i] = 1;
        
        for(int len = 1 ; len < n ; len++) {
            for(int i = 0 ; i + len < n ; i++) {
                int j = i + len;
                if(str[i] == str[j] && i+1 == j)
                    dp[i][j] = 2;
                else if(str[i] == str[j])
                    dp[i][j] = 2 + dp[i+1][j-1];
                else
                    dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
        }
        
        return dp[0][n-1];
    }
};

// MEMOIZATION
// class Solution {
//   public:
//     vector<vector<int>> memo;
    
//     int solve(string str,int i,int j) {
//         if(i == j)
//             return 1;
//         if(str[i] == str[j] && i+1 == j)
//             return 2;
//         if(memo[i][j] != -1)
//             return memo[i][j];
//         if(str[i] == str[j])
//             return memo[i][j] = 2 + solve(str,i+1,j-1);
//         else
//             return memo[i][j] = max(solve(str,i,j-1),solve(str,i+1,j));
//     }
    
//     int longestPalindromeSubseq(string str) {
//         int n = str.size();
//         memo = vector<vector<int>>(n,vector<int>(n,-1));
//         return solve(str,0,n-1);
//     }
// };

// RECURSIVE
// class Solution {
//   public:
//     int solve(string str,int i,int j) {
//         if(i == j)
//             return 1;
//         if(str[i] == str[j] && i+1 == j)
//             return 2;
//         if(str[i] == str[j])
//             return 2 + solve(str,i+1,j-1);
//         else
//             return max(solve(str,i,j-1),solve(str,i+1,j));
//     }
    
//     int longestPalindromeSubseq(string str) {
//         return solve(str,0,str.size()-1);
//     }
// };

int main() {
    string str = "geeksforgeeks";
    Solution s;
    cout<<s.longestPalindromeSubseq(str);
    return 0;
}