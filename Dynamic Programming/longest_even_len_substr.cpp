#include <iostream>
using namespace std;

int solve(string str) {
    int n = str.size();
    int dp[n][n];
    for(int i = 0 ; i < n ; i++)
        dp[i][i] = str[i] - '0';
    
    int ans = 0;
    for(int len = 2 ; len <= n ; len++) {
        for(int i = 0 ; i + len - 1 < n ; i++) {
            int j = i + len - 1;
            int k = len / 2;
            
            dp[i][j] = dp[i][j-k] + dp[j-k+1][j];
            
            if(len % 2 == 0 && dp[i][j-k] == dp[j-k+1][j] && len > ans)
                ans = len;
        }
    }
    return ans;
}

int main() {
    string str = "153803";
    cout<<solve(str);
	return 0;
}