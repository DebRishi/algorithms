#include<bits/stdc++.h>
using namespace std;

// LEETCODE 34 - First and Last Position of Element in Sorted Array
class Solution {
public:

    // Lower bound is the first occurrence of target element. If element not found index of first element greater than target is returned.
    int lowerBound(vector<int>& nums,int key) {
        int low = 0;
        int mid = 0;
        int hii = nums.size();
        while(low < hii) {
            mid = low + ((hii-low) >> 1);
            if(nums[mid] < key)
                low = mid+1;
            else
                hii = mid;
        }
        return low;
    }
    
    // Upper bound is the first occurence of element greater than target element.
    int upperBound(vector<int>& nums,int key) {
        int low = 0;
        int mid = 0;
        int hii = nums.size();
        while(low < hii) {
            mid = low + ((hii-low) >> 1);
            if(nums[mid] <= key)
                low = mid+1;
            else
                hii = mid;
        }
        return low;
    }
    
    vector<int> searchRange(vector<int>& nums,int key) {
        int low = lowerBound(nums,key);
        int upp = upperBound(nums,key);
        if(low == upp)
            return {-1,-1};
        else
            return {low,upp-1};
    }
};

int main() {
    return 0;
}