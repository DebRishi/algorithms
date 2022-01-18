#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    
    void helper(vector<int>& nums,int i = 0,vector<int> set = {}) {
        if(i == nums.size()) {
            ans.push_back(set);
            return;
        }
        int j = i;
        while(j < nums.size() && nums[j] == nums[i])
            j++;
        helper(nums,j,set);
        set.push_back(nums[i]);
        helper(nums,i+1,set);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        helper(nums);
        return ans;
    }
};

int main() {
    return 0;
}