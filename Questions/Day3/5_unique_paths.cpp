#include<iostream>
#include<vector>
using namespace std;

// COMBINATIONS
class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m+n-2;
        int r = m-1;
        double ans = 1;
        for(int i = 1 ; i <= r ; i++) {
            ans = ans * (N-r+i)/i;
        }
        return (int)ans;
    }
};

// MEMORIZATION DP
// class Solution {
// public:
    
//     vector<vector<int>> memo;
    
//     int helper(int row, int col,int i = 0,int j = 0) {
//         if(i == row || j == col)
//             return 0;
//         if(i == row-1 && j == col-1)
//             return 1;
//         if(memo[i][j] != -1)
//             return memo[i][j];

//         int right = helper(row,col,i,j+1);
//         int down = helper(row,col,i+1,j);
//         return memo[i][j] = right + down;
//     }
    
//     int uniquePaths(int row, int col) {
//         memo = vector<vector<int>>(row,vector<int>(col,-1));
//         return helper(row,col);
//     }
// };

// RECURSIVE
// class Solution {
// public:
    
//     int uniquePaths(int row, int col,int i = 0,int j = 0) {
//         if(i == row || j == col) return 0;
//         if(i == row-1 && j == col-1) {
//             return 1;
//         }
//         int right = uniquePaths(row,col,i,j+1);
//         int down = uniquePaths(row,col,i+1,j);
//         return right + down;
//     }
// };

int main() {
    Solution s;
    cout<<s.uniquePaths(3,7)<<endl;
    return 0;
}