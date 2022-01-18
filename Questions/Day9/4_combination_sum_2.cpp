#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    
    void helper(int k,vector<int>& nums,vector<int> set = {},int i = 0) {
        if(k == 0) {
            ans.push_back(set);
            return;
        }
        
        if(i == nums.size() || k < 0)
            return;
        
        if(nums[i] <= k) {
            set.push_back(nums[i]);
            helper(k-nums[i],nums,set,i+1);
            set.pop_back();
        }
        
        int j = i;
        while(j < nums.size() && nums[j] == nums[i])
            j++;
        helper(k,nums,set,j);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        helper(k,nums);
        return ans;
    }
};

int main() {
    return 0;
}