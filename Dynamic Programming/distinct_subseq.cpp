#include<iostream>
#include<vector>
using namespace std;

// TABULATION
class Solution {
public:
    int numDistinct(string str,string pat) {
        int strlen = str.length();
        int patlen = pat.length();
        vector<vector<int>> dp(strlen+1,vector<int>(patlen+1,0));
        for(int i = 0 ; i <= strlen ; i++)
            dp[i][0] = 1;
        for(int i = 0 ; i < strlen ; i++) {
            for(int j = 0 ; j < patlen ; j++) {
                if(str[i] == pat[j])
                    dp[i+1][j+1] = dp[i][j] + dp[i][j+1];
                else
                    dp[i+1][j+1] = dp[i][j+1];
            }
        }
        return dp[strlen][patlen];
    }
};

// MEMORIZATION
// class Solution {
// public:
//     vector<vector<int>> memo;
    
//     int solve(string str,string pat,int i = 0,int j = 0) {
//         int strlen = str.length();
//         int patlen = pat.length();
//         if(j == patlen)
//             return 1;
//         if(i == strlen)
//             return 0;
//         if(memo[i][j] != -1)
//             return memo[i][j];
//         if(str[i] == pat[j])
//             return memo[i][j] = solve(str,pat,i+1,j+1) + solve(str,pat,i+1,j);
//         else
//             return memo[i][j] = solve(str,pat,i+1,j);
//     }
    
//     int numDistinct(string str,string pat) {
//         int strlen = str.length();
//         int patlen = pat.length();
//         memo = vector<vector<int>>(strlen,vector<int>(patlen,-1));
//         return solve(str,pat);
//     }
// };

// RECURSIVE
// class Solution {
// public:
//     int solve(string str,string pat,int i = 0,int j = 0) {
//         int strlen = str.length();
//         int patlen = pat.length();
//         if(j == patlen)
//             return 1;
//         if(i == strlen)
//             return 0;
//         if(str[i] == pat[j])
//             return solve(str,pat,i+1,j+1) + solve(str,pat,i+1,j);
//         else
//             return solve(str,pat,i+1,j);
//     }
    
//     int numDistinct(string str,string pat) {
//         return solve(str,pat);
//     }
// };

int main() {
    string str = "rabbbit";
    string pat = "rabbit";
    Solution s;
    cout<<s.numDistinct(str,pat);
    return 0;
}