#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> hash;
        hash[0] = 1;
        int ans = 0;
        int sum = 0;
        for(int i : nums) {
            sum += i;
            if(hash.find(sum-k) != hash.end()) {
                ans += hash[sum-k];
            }
            hash[sum]++;
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {15,-2,2,-8,1,7,10,23};
    int k = 0;
    Solution s;
    cout<<s.subarraySum(nums,k)<<endl;
    return 0;
}