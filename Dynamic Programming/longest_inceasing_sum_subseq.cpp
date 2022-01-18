#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    int longestIncreasingSumSubsequence(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp = nums;

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < i ; j++) {
                if(nums[j] < nums[i] && dp[i] <= dp[j] + nums[i])
                    dp[i] = dp[j] + nums[i];
            }
        }

        int ans = INT_MIN;
        for(int i : dp)
            ans = max(ans,i);
        return ans;
    }
};

int main() {
    vector<int> nums = {1,101,2,3,100,4,5};
    Solution s;
    cout<<s.longestIncreasingSumSubsequence(nums);
    return 0;
}