#include<iostream>
#include<vector>
using namespace std;

class Solution {
	public:
	int LongestBitonicSequence(vector<int>& nums) {
	    int n = nums.size();
	    vector<int> increasing(n,1);
	    for(int i = 0 ; i < n ; i++) {
	        for(int j = i+1 ; j < n ; j++) {
	            if(nums[j] > nums[i] && increasing[j] < increasing[i]+1) {
	                increasing[j] = increasing[i]+1;
	            }
	        }
	    }
	    
	    vector<int> decreasing(n,1);
	    for(int i = 0 ; i < n ; i++) {
	        for(int j = i+1 ; j < n ; j++) {
	            if(nums[j] < nums[i] && increasing[j] < increasing[i]+1) {
	                increasing[j] = increasing[i]+1;
	            }
	        }
	    }
	    
	    int ans = 1;
	    for(int i = 0 ; i < n ; i++) {
	        ans = max(ans,increasing[i]+decreasing[i]-1);
	    }
	    return ans;
	}
};

int main() {
    vector<int> nums = {1,11,2,10,4,5,2,1};
    Solution s;
    cout<<s.LongestBitonicSequence(nums)<<endl;
}