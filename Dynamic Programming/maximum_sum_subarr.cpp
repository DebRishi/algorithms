#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
  public:
    int maximumSumSubarray(vector<int>& nums) {
        int ans = nums[0];
        int sum = 0;
        for(int num : nums) {
            sum += num;
            ans = max(ans,sum);
            sum = max(sum,0);
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution s;
    cout<<s.maximumSumSubarray(nums);
    return 0;
}