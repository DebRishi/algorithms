#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    string longestPalindrome(string str) {
        int n = str.size();
        int dp[n][n];
        
        for(int len = 0 ; len < n ; len++) {
            for(int i = 0 ; i + len < n ; i++) {
                int j = i + len;
                if(i == j)
                    dp[i][j] = 1;
                else if(str[i] == str[j] && i+1 == j)
                    dp[i][j] = 1;
                else if(str[i] == str[j])
                    dp[i][j] = 1 & dp[i+1][j-1];
                else
                    dp[i][j] = 0;
            }
        }
        
        int ansLen = -1;
        string ansStr = "";
        
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(dp[i][j] && j-i > ansLen) {
                    ansLen = j-i;
                    ansStr = str.substr(i,j-i+1);
                }
            }
        }
        
        return ansStr;
    }
};

int main() {
    string str = "forgeeksskeegfor";
    Solution s;
    cout<<s.longestPalindrome(str);
    return 0;
}