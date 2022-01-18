#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    vector<vector<int>> memo;
    
    int solve(vector<vector<int>>& dungeon,int i = 0,int j = 0) {
        int row = dungeon.size();
        int col = dungeon[0].size();

        if(i == row || j == col)
            return 1e9;
        if(i == row-1 && j == col-1) {
            if(dungeon[i][j] > 0)
                return 1;
            else
                return 1 - dungeon[i][j];
        }

        if(memo[i][j] != INT_MAX)
            return memo[i][j];

        int minHealth = min(solve(dungeon,i+1,j),solve(dungeon,i,j+1)) - dungeon[i][j];
        if(minHealth <= 0)
            return memo[i][j] = 1;
        else
            return memo[i][j] = minHealth;
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row = dungeon.size();
        int col = dungeon[0].size();
        memo = vector<vector<int>>(row,vector<int>(col,INT_MAX));
        return solve(dungeon);
    }
};

int main() {
    vector<vector<int>> dungeon = {
        {-2,-3,3},
        {-5,-10,1},
        {10,30,-5}
    };
    Solution s;
    cout<<s.calculateMinimumHP(dungeon);
    return 0;
}