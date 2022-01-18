#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        
        int totalOnes = 0;
        for(int i = 0 ; i < n ; i++)
            if(nums[i] == 1)
                totalOnes++;
        
        int ones = 0;
        for(int i = 0 ; i < totalOnes ; i++)
            if(nums[i] == 1)
                ones++;
        
        int ans = totalOnes - ones;
        for(int i = 0 ; i < n ; i++) {
            if(nums[i] == 1)
                ones--;
            if(nums[(i+totalOnes)%n] == 1)
                ones++;
            ans = min(ans,totalOnes - ones);
        }
        
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {0,1,0,1,1,0,0};
    cout<<s.minSwaps(nums);
    return 0;
}