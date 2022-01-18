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
    
    int maximumSumRectangle(vector<vector<int>>& matrix) {
        int ans = matrix[0][0];
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i1 = 0 ; i1 < row ; i1++) {
            vector<int> nums(col,0);
            for(int i2 = i1 ; i2 < row ; i2++) {
                for(int j = 0 ; j < col ; j++) {
                    nums[j] += matrix[i2][j];
                }
                ans = max(ans,maximumSumSubarray(nums));
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> matrix  = {
        { 1, 2,-1,-4,-20},
        {-8,-3, 4, 2,  1},
        { 3, 8,10, 1,  3},
        {-4,-1, 1, 7, -6}
    };
    Solution s;
    cout<<s.maximumSumRectangle(matrix);
    return 0;
}