#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> & nums) {
        int n = nums.size();
        int target = 0;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i = 0 ; i < n ;) {
            int j = i+1;
            int k = n-1;
            while(j < k) {
                int sum = nums[j]+nums[k];
                if(sum+nums[i] < target) 
                    j++;
                else if(sum+nums[i] > target)
                    k--;
                else {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    int x = nums[j];
                    int y = nums[k];
                    while(j < k && nums[j] == x) 
                        j++;
                    while(j < k && nums[k] == y)
                        k--;
                }
            }
            int temp = nums[i];
            while(i < n && temp == nums[i]) 
                i++;
        }
        return ans;
    }
};

int main() {
    return 0;
}