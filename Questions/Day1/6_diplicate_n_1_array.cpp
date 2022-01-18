#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int> & num) {
        int slow = num[0];
        int fast = num[0];
        
        do {
            slow = num[slow];
            fast = num[num[fast]];
        }while(slow != fast);
        
        fast = num[0];
        while(slow != fast) {
            slow = num[slow];
            fast = num[fast];
        }
        
        return slow;
    }
};

int main(){
    vector<int> nums = {1,3,4,2,2};
    Solution s;
    cout<<s.findDuplicate(nums)<<endl;
    return 0;
}