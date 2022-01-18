#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    vector<int> memo;
    
    int solve(vector<int>& nums,int k,int idx = 0) {
        if(memo[idx] != -1)
            return memo[idx];
        int i = idx;
        int n = nums.size();
        int len = nums[idx];
        int ans = INT_MAX;
        while(i < n && len <= k) {
            if(i == n-1)
                return memo[idx] = 0;
            ans = min(ans,solve(nums,k,i+1)+(int)pow(k-len,2));
            len += nums[++i]+1;
        }
        return memo[idx] = ans;
    }
    
    int solveWordWrap(vector<int>& nums,int k) {
        memo = vector<int>(nums.size(),-1);
        return solve(nums,k);
    } 
};

int main() {
    vector<int> nums = {3,2,2,5};
    int k = 6;
    Solution s;
    cout<<s.solveWordWrap(nums,k)<<endl;
    return 0;
}