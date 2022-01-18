#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> dp(n,0);
        for(int i = 0 ; i < n ; i++)
            for(int j = i+1 ; j < n ; j++)
                if(nums[j]%nums[i] == 0 && dp[j] < 1+dp[i])
                    dp[j] = 1 + dp[i];
        
        int maxNum = 0;
        for(int i : dp)
            maxNum = max(maxNum,i);
        
        int prev = -1;
        vector<int> ans;
        for(int i = n-1 ; i >= 0 ; i--)
            if(dp[i] == maxNum && (prev == -1 || prev % nums[i] == 0)) {
                ans.push_back(nums[i]);
                prev = nums[i];
                maxNum--;
            }
        return ans;
    }
};

int main() {
    vector<int> nums = {1,2,4,8};
    Solution s;
    for(auto i : s.largestDivisibleSubset(nums))
        cout<<i<<" ";
    return 0;
}