#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;

class Solution {
public:
    
    // BOYER MOORE MAJORITY ALGORITHM
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = -1;
        int num2 = -1;
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i : nums) {
            if(cnt1 == 0) 
                num1 = i;
            else if(cnt2 == 0) 
                num2 = i;
            if(i == num1)
                cnt1++;
            else if(i == num2) 
                cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }
        int n = nums.size()/3;
        vector<int> ans;
        cnt1 = 0;
        cnt2 = 0;
        for(int i : nums) {
            if(i == num1) cnt1++;
            if(i == num2) cnt2++;
        }
        if(cnt1 > n) ans.push_back(num1);
        if(cnt2 > n) ans.push_back(num2);
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         int n = nums.size()/3;
//         map<int,int> freq;
//         set<int> ans;
//         for(auto i : nums) {
//             freq[i]++;
//             if(freq[i] > n) ans.insert(i);
//         }
//         return vector<int>(ans.begin(),ans.end());
//     }
// };

int main() {
    vector<int> nums = {10, 10, 20, 30, 10, 10};
    Solution s;
    for(int i : s.majorityElement(nums)) {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}