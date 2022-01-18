#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int i = 0;
        int j = 0;
        while(j < nums.size()) {
            if(nums[i] != nums[j])
                nums[++i] = nums[j];
            j++;
        }
        return i+1;
    }
};

int main() {
    return 0;
}