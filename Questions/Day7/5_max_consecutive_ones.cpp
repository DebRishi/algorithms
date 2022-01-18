#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxCount = 0;
        for(int i : nums) {
            if(i == 0)
                count = -1;
            count++;
            maxCount = max(maxCount,count);
        }
        return maxCount;
    }
};

int main() {
    return 0;
}