#include <iostream>
using namespace std;

string longestPalindrome(string str) {
    int n = str.length();
    int dp[n][n] = {0};
    
    int start = 0;
    int maxLen = 1;

    for(int i = 0 ; i < n ; i++) {
        dp[i][i] = 1;
    }

    for(int i = 0 ; i < n-1 ; i++) {
        if(str[i] == str[i+1]) {
            dp[i][i+1] = 1;
            start = i;
            maxLen = 2;
        }
    }

    for(int len = 3 ; len <= n ; len++) {
        for(int i = 0 ; i <= n-len ; i++) {
            int j = i+len-1;
            if(str[i] == str[j] && dp[i+1][j-1]) {
                dp[i][j] = 1;
                if(maxLen < len) {
                    maxLen = len;
                    start = i;
                }
            }
        }
    }
    
    return str.substr(start,maxLen);
}

int main() {
    cout<<longestPalindrome("babad")<<endl;
    return 0;
}