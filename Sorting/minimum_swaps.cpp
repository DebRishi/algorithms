#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
    public:
    int minSwaps(vector<int>& nums) {
        vector<pair<int,int>> temp;
        for(int i = 0 ; i < nums.size() ; i++)
            temp.push_back({nums[i],i});
        
        sort(temp.begin(),temp.end());

        int swap_count = 0;
        for(int i = 0 ; i < nums.size() ; i++) {
            if(temp[i].second != i) {
                swap(temp[i],temp[temp[i].second]);
                swap_count++;
                i--;
            }
        }
        return swap_count;
    }
};

int main() {
    vector<int> nums = {1,5,4,3,2};
    Solution s;
    cout<<s.minSwaps(nums);
    return 0;
}