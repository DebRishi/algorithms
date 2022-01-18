#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// TABULATION
class Solution {
public:
    int minDistance(string str1,string str2) {
        int n1 = str1.length();
        int n2 = str2.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for(int i = 0 ; i <= n1 ; i++)
            dp[i][0] = i;
        for(int j = 0 ; j <= n2 ; j++)
            dp[0][j] = j;
        for(int i = 0 ; i < n1 ; i++) {
            for(int j = 0 ; j < n2 ; j++) {
                if(str1[i] == str2[j]) 
                    dp[i+1][j+1] = dp[i][j];
                else
                    dp[i+1][j+1] = 1 + min({dp[i][j+1],dp[i+1][j],dp[i][j]});
            }
        }
        return dp[n1][n2];
    }
};

// MEMORIZATION
// class Solution {
// public:
//     vector<vector<int>> memo;
    
//     int solve(string str1,string str2,int i = 0,int j = 0) {
//         int n1 = str1.length();
//         int n2 = str2.length();
//         if(i == n1)
//             return n2-j;
//         if(j == n2)
//             return n1-i;
//         if(str1[i] == str2[j])
//             return solve(str1,str2,i+1,j+1);
//         if(memo[i][j] != -1)
//             return memo[i][j];
//         int insert = solve(str1,str2,i,j+1);
//         int remove = solve(str1,str2,i+1,j);
//         int replace = solve(str1,str2,i+1,j+1);
//         return memo[i][j] = 1 + min({insert,remove,replace});
//     }
    
//     int minDistance(string str1,string str2) {
//         int n1 = str1.length();
//         int n2 = str2.length();
//         memo = vector<vector<int>>(n1,vector<int>(n2,-1));
//         return solve(str1,str2);
//     }
// };

// RECURSION
// class Solution {
// public:
//     int solve(string str1,string str2,int i = 0,int j = 0) {
//         int n1 = str1.length();
//         int n2 = str2.length();
//         if(i == n1)
//             return n2-j;
//         if(j == n2)
//             return n1-i;
//         if(str1[i] == str2[j])
//             return solve(str1,str2,i+1,j+1);
//         int insert = solve(str1,str2,i,j+1);
//         int remove = solve(str1,str2,i+1,j);
//         int replace = solve(str1,str2,i+1,j+1);
//         return 1 + min({insert,remove,replace});
//     }
    
//     int minDistance(string str1,string str2) {
//         return solve(str1,str2);
//     }
// };

int main() {
    string str1 = "sunday";
    string str2 = "saturday";
    Solution s;
    cout<<s.minDistance(str1,str2)<<endl;
    return 0;
}