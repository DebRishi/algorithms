#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

// LEETCODE 1510 - Stone Game IV
class Solution {
public:
    vector<vector<int>> memo;
    
    bool solve(int n,int turn = true) {
        if(n == 0)
            return !turn;
        if(memo[n][turn] != -1)
            return memo[n][turn];
        bool flag = turn;
        for(int sq = sqrt(n) ; sq > 0 ; sq--)
            if(flag == solve(n-(sq*sq),!turn))
                return memo[n][turn] = turn;
        return memo[n][turn] = !turn;
    }
    
    bool winnerSquareGame(int n) {
        memo = vector<vector<int>>(n+1,vector<int>(2,-1));
        return solve(n);
    }
};

int main() {
    Solution s;
    cout<<s.winnerSquareGame(15);
    return 0;
}