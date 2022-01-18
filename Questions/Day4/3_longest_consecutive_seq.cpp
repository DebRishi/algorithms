#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> hash;
        for(int i : nums) hash.insert(i);
        int ans = 0;
        for(int i : nums) {
            if(!hash.count(i-1)) {
                int cur = i;
                int streak = 1;
                while(hash.count(cur+1)) {
                    streak++;
                    cur++;
                }
                ans = max(ans,streak);
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {100,4,200,1,3,2};
    Solution s;
    cout<<s.longestConsecutive(nums)<<endl;
    return 0;
}