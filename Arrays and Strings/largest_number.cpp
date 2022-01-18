#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    static bool compare(string str1,string str2) {
        string num1 = str1 + str2;
        string num2 = str2 + str1;
        return num1 > num2;
    }
    
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for(auto num : nums)
            strs.push_back(to_string(num));

        sort(strs.begin(),strs.end(),compare);

        string ans = "";
        for(auto str : strs)
            ans += str;

        if(ans[0] == '0')
            return "0";
        return ans;
    }
};

int main() {
    vector<int> nums = {3,30,34,5,9};
    Solution s;
    cout<<s.largestNumber(nums);
    return 0;
}