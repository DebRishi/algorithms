#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> memo;
    
    bool solve(vector<int>& nums,int sum,int i = 0) {
        int n = nums.size();
        if(i == n || sum < 0)
            return false;
        if(sum == 0)
            return true;
        if(memo[i][sum] != -1)
            return memo[i][sum];
        return memo[i][sum] = solve(nums,sum,i+1) or solve(nums,sum-nums[i],i+1);
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int num : nums)
            sum += num;
        if(sum % 2)
            return false;
        sum = sum / 2;
        memo = vector<vector<int>>(n,vector<int>(sum+1,-1));
        return solve(nums,sum);
    }
};

int main() {
    vector<int> nums = {1,5,11,5};
    Solution s;
    cout<<s.canPartition(nums);
    return 0;
}