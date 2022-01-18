#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    
    void helper(vector<int>& nums,int k,int i = 0,vector<int> set = {}) {
        if(k == 0){
            ans.push_back(set);
            return;
        }
        
        if(i == nums.size() || k < 0)
            return;
        
        helper(nums,k,i+1,set);
        if(nums[i] <= k) {
            set.push_back(nums[i]);
            helper(nums,k-nums[i],i,set);
        }      
    }
    
    vector<vector<int>> combinationSum(vector<int>& nums, int k) {
        helper(nums,k);
        return ans;
    }
};

int main() {
    return 0;
}