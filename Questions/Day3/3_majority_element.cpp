#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    
    // BOYER MOORE VOTING ALGORITHM
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int major;
        for(int num : nums) {
            if(count == 0) 
                major = num;
            if(num == major) 
                count++;
            else 
                count--;
        }
        return major;
    }
};

// class Solution {
// public:
//     int majorityElement(vector<int> & nums) {
//         int n = nums.size()/2;
//         map<int,int> freq;
//         for (int i : nums) {
//             freq[i]++;
//             if(freq[i] > n) return i;
//         }
//         return -1;
//     }
// };

int main() {
    vector<int> nums = {2,2,1,1,1,2,2};
    Solution s;
    cout<<s.majorityElement(nums)<<endl;
    return 0;
}