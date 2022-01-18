#include<iostream>
#include<vector>
using namespace std;

// SIMILAR TO MCM
class Solution {
  public:
    
    vector<vector<int>> memo;
    
    int solve(vector<int>& nums,int low,int hii) {
        if(low > hii)
            return 0;

        if(memo[low][hii] != -1)
            return memo[low][hii];

        int maxCoins = 0;
        for(int i = low ; i <= hii ; i++) {
            int coins = solve(nums,low,i-1) + nums[low-1]*nums[i]*nums[hii+1] + solve(nums,i+1,hii);
            maxCoins = max(maxCoins,coins);
        }
        return memo[low][hii] = maxCoins;
    }
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        memo = vector<vector<int>>(n+2,vector<int>(n+2,-1));
        return solve(nums,1,n);
    }
};

int main() {
    return 0;
}