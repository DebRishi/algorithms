#include<iostream>
#include<vector>
using namespace std;

// TABULATION
class Solution {
    public:
    int matrixMultiplication(vector<int> matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int> (n,0));
        for(int len = 1 ; len < n-1 ; len++) {
            for(int low = 1 ; low+len < n ; low++) {
                int high = low+len;
                dp[low][high] = INT_MAX;
                for(int i = low ; i < high ; i++) {
                    int cost = dp[low][i] + dp[i+1][high] + 
                        matrix[low-1]*matrix[i]*matrix[high];
                    dp[low][high] = min(dp[low][high],cost);
                }
            }
        }
        return dp[1][n-1];
    }
};

// MEMORIZATION
// class Solution {
//     public:
//     vector<vector<int>> memo;
    
//     int mcm(vector<int>& matrix,int low,int high) {
//         if(low == high)
//             return 0;
//         if(memo[low][high] != -1)
//             return memo[low][high];
//         int minCost = INT_MAX;
//         for(int i = low ; i < high ; i++) {
//             int cost = mcm(matrix,low,i) + mcm(matrix,i+1,high) +
//                 matrix[low-1]*matrix[i]*matrix[high];
//             minCost = min(minCost,cost);
//         }
//         return memo[low][high] = minCost;
//     }
    
//     int matrixMultiplication(vector<int> matrix) {
//         int n = matrix.size();
//         memo = vector<vector<int>> (n,vector<int> (n,-1));
//         return mcm(matrix,1,n-1);
//     }
// };

// RECURSIVE
// class Solution {
//     public:

//     int mcm(vector<int>& matrix,int low,int high) {
//         if(low == high)
//             return 0;
//         int minCost = INT_MAX;
//         for(int i = low ; i < high ; i++) {
//             int cost = mcm(matrix,low,i) + mcm(matrix,i+1,high) +
//                 matrix[low-1]*matrix[i]*matrix[high];
//             minCost = min(minCost,cost);
//         }
//         return minCost;
//     }

//     int matrixMultiplication(vector<int> matrix) {
//         int n = matrix.size();
//         return mcm(matrix,1,n-1);
//     }
// };

int main() {
    Solution s;
    vector<int> matrix = {40,20,30,10,30};
    cout<<s.matrixMultiplication(matrix);
}