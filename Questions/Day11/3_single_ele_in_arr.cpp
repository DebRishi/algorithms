#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int i = 0;
        int j = nums.size()-1;
        while(i < j) {
            int mid = i + (j-i)/2;
            if(mid % 2) {
                if(nums[mid+1] == nums[mid])
                    j = mid;
                else
                    i = mid+1;
            }
            else {
                if(nums[mid+1] == nums[mid])
                    i = mid+1;
                else
                    j = mid;
            }
        }
        return nums[i];
    }
};

int main() {
    vector<int> nums = {1,1,2,3,3,4,4,8,8};
    Solution s;
    cout<<s.singleNonDuplicate(nums);
}