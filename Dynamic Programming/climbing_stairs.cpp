#include<iostream>
#include<vector>
using namespace std;

// MEMOIZATION
class Solution {
  public:
    vector<int> memo;

    int solve(int n) {
        if(n < 0)
            return 0;
        if(n == 0)
            return 1;
        if(memo[n] != -1)
            return memo[n];
        return memo[n] = solve(n-1) + solve(n-2);
    }
    
    int climbStairs(int n) {
        memo = vector<int>(n+1,-1);
        return solve(n);
    }
};

int main() {
    Solution s;
    cout<<s.climbStairs(10);
    return 0;
}