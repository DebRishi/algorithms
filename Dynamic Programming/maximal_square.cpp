#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> dp(row+1,vector<int>(col+1,0));
        for(int i = 0 ; i < row ; i++)
            for(int j = 0 ; j < col ; j++) 
                if(matrix[i][j] == '1') {
                    dp[i+1][j+1] = 1 + min({dp[i][j],dp[i][j+1],dp[i+1][j]});
                    ans = max(ans,dp[i+1][j+1]);
                }
        return ans*ans;
    }
};

int main() {
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    Solution s;
    cout<<s.maximalSquare(matrix);
}