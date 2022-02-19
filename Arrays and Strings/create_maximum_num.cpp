#include<iostream>
#include<vector>
using namespace std;

// LEETCODE 321 - Create Maximum Number
class Solution {
public:
    vector<int> maxSubarr(vector<int>& nums,int k) {
        int n = nums.size();
        vector<int> stack;
        for(int i = 0 ; i < n ; i++) {
            while(stack.size() && stack.back() < nums[i] && k-stack.size() < n-i)
                stack.pop_back();
            if(stack.size() < k)
                stack.push_back(nums[i]);
        }
        return stack;
    }
    
    string mergeSubarr(vector<int>& nums1,vector<int>& nums2) {
        string num1 = getString(nums1);
        string num2 = getString(nums2);
        string nums = "";
        while(num1 != "" && num2 != "") {
            if(num1 > num2) {
                nums += num1[0];
                num1 = num1.substr(1);
            }
            else {
                nums += num2[0];
                num2 = num2.substr(1);
            }
        }
        while(num1 != "") {
            nums += num1[0];
            num1 = num1.substr(1);
        }
        while(num2 != "") {
            nums += num2[0];
            num2 = num2.substr(1);
        }
        return nums;
    }
    
    string getString(vector<int>& nums) {
        string ans = "";
        for(int i : nums)
            ans += i + '0';
        return ans;
    }
    
    vector<int> getNumber(string num) {
        vector<int> ans;
        for(int i = 0 ; i < num.size() ; i++)
            ans.push_back(num[i] - '0');
        return ans;
    }
    
    vector<int> maxNumber(vector<int>& nums1,vector<int>& nums2,int k) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        string maxNum = "";
        vector<int> ans;
        for(int i = 0 ; i <= k ; i++) {
            if(i <= n1 && k-i <= n2) {
                auto n1 = maxSubarr(nums1,i);
                auto n2 = maxSubarr(nums2,k-i);
                auto num = mergeSubarr(n1,n2);
                if(num > maxNum) {
                    maxNum = num;
                    ans = getNumber(num);
                }
            }
        }
        return ans;
    }
};

/*

NOTES -> 

To create max number of length k from two arrays, you need to create max number of length i from array one and max number of length k-i from array two, then combine them together. After trying all possible i, you will get the max number created from two arrays.

Optimization:

1. Suppose nums1 = [3, 4, 6, 5], nums2 = [9, 1, 2, 5, 8, 3], the maximum number you can create from nums1 is [6, 5] with length 2. For nums2, it's [9, 8, 3] with length 3. Merging the two sequence, we have [9, 8, 6, 5, 3], which is the max number we can create from two arrays without length constraint. If the required length k<=5, we can simply trim the result to required length from front. For instance, if k=3, then [9, 8, 6] is the result.

2. Suppose we need to create max number with length 2 from num = [4, 5, 3, 2, 1, 6, 0, 8]. The simple way is to use a stack, first we push 4 and have stack [4], then comes 5 > 4, we pop 4 and push 5, stack becomes [5], 3 < 5, we push 3, stack becomes [5, 3]. Now we have the required length 2, but we need to keep going through the array in case a larger number comes, 2 < 3, we discard it instead of pushing it because the stack already grows to required size 2. 1 < 3, we discard it. 6 > 3, we pop 3, since 6 > 5 and there are still elements left, we can continue to pop 5 and push 6, the stack becomes [6], since 0 < 6, we push 0, the stack becomes [6, 0], the stack grows to required length again. Since 8 > 0, we pop 0, although 8 > 6, we can't continue to pop 6 since there is only one number, which is 8, left, if we pop 6 and push 8, we can't get to length 2, so we push 8 directly, the stack becomes [6, 8].

3. In the basic idea, we mentioned trying all possible length i. If we create max number for different i from scratch each time, that would be a waste of time. Suppose num = [4, 9, 3, 2, 1, 8, 7, 6], we need to create max number with length from 1 to 8. For i==8, result is the original array. For i==7, we need to drop 1 number from array, since 9 > 4, we drop 4, the result is [9, 3, 2, 1, 8, 7, 6]. For i==6, we need to drop 1 more number, 3 < 9, skip, 2 < 3, skip, 1 < 2, skip, 8 > 1, we drop 1, the result is [9, 3, 2, 8, 7, 6]. For i==5, we need to drop 1 more, but this time, we needn't check from beginning, during last scan, we already know [9, 3, 2] is monotonically non-increasing, so we check 8 directly, since 8 > 2, we drop 2, the result is [9, 3, 8, 7, 6]. For i==4, we start with 8, 8 > 3, we drop 3, the result is [9, 8, 7, 6]. For i==3, we start with 8, 8 < 9, skip, 7 < 8, skip, 6 < 7, skip, by now, we've got maximum number we can create from num without length constraint. So from now on, we can drop a number from the end each time. The result is [9, 8, 7], For i==2, we drop last number 7 and have [9, 8]. For i==1, we drop last number 8 and have [9].

*/

int main() {
    vector<int> nums1 = {3,4,6,5};
    vector<int> nums2 = {9,1,2,5,8,3};
    int k = 5;
    Solution s;
    for(int i : s.maxNumber(nums1,nums2,k))
        cout<<i<<" ";
    return 0;
}