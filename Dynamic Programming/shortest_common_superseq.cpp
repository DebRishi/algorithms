#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    string longestCommonSubseq(string str1,string str2) {
        int n1 = str1.size();
        int n2 = str2.size();
        vector<vector<string>> dp(n1+1,vector<string>(n2+1,""));
        for(int i = 0 ; i < n1 ; i++) {
            for(int j = 0 ; j < n2 ; j++) {
                if(str1[i] == str2[j])
                    dp[i+1][j+1] = dp[i][j] + str1[i];
                else {
                    if(dp[i+1][j].size() > dp[i][j+1].size())
                        dp[i+1][j+1] = dp[i+1][j];
                    else
                        dp[i+1][j+1] = dp[i][j+1];
                }
            }
        }
        return dp[n1][n2];
    }
    
    string shortestCommonSupersequence(string str1, string str2) {
        string ans = "";
        int i = 0;
        int j = 0;
        for(char c : longestCommonSubseq(str1,str2)) {
            while(str1[i] != c)
                ans += str1[i++];
            while(str2[j] != c)
                ans += str2[j++];
            ans += c;
            i++;
            j++;
        }
        return ans + str1.substr(i) + str2.substr(j);
    }
};

// RETURN ONLY LENGTH -> GFG
// class Solution {
//   public:
//     vector<vector<int>> memo;
    
//     int solve(string str1,string str2,int i = 0,int j = 0) {
//         if(i == str1.size() || j == str2.size())
//             return 0;
//         if(memo[i][j] != -1)
//             return memo[i][j];
//         if(str1[i] == str2[j])
//             return memo[i][j] = 1 + solve(str1,str2,i+1,j+1);
//         else
//             return memo[i][j] = max(solve(str1,str2,i+1,j),solve(str1,str2,i,j+1));
//     }
    
//     int longestCommonSubsequence(string str1,string str2) {
//         memo = vector<vector<int>>(str1.size(),vector<int>(str2.size(),-1));
//         return solve(str1,str2);
//     }
    
//     int shortestCommonSupersequence(string str1,string str2,int m,int n) {
//         int lcs = longestCommonSubsequence(str1,str2);
//         return m + n - lcs;
//     }
// };

int main() {
    Solution s;
    cout<<s.shortestCommonSupersequence("abac","cab");
    return 0;
}