#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> set;
        for(int i = 0 ; i < nums.size() ; i++) {
            if(set.find(target-nums[i]) != set.end()) {
                return {set[target-nums[i]],i};
            }
            set[nums[i]] = i;
        }
        return {-1,-1};
    }
};

int main() {
    vector<int> nums = {2,7,11,15};
    int target = 9;
    Solution s;
    vector<int> ans = s.twoSum(nums,target);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}