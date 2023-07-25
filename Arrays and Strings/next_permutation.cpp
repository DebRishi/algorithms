#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutaion(vector<int> & num) {
    int n = num.size();
    int i = n-2;
    
    // FINDING POSSIBLE BREAKPOINTS
    while(i >= 0 && num[i] >= num[i+1]) {
        i--;
    }

    // IF BREAKPOINT FOUND
    if(i >= 0) {
        int j = n-1;
        
        // SWAP WITH NEXT GREATEST IN LEFT SECTION
        while(j > i) {
            if(num[i] < num[j]) {
                swap(num[i],num[j]);
                break;
            }
            j--;
        }
    }

    // REVERSE THE LEFT SECTION
    i++;
    int j = n-1;
    while(i < j) {
        swap(num[i],num[j]);
        i++;
        j--;
    }
}

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-2;
        while(i >= 0 && nums[i] >= nums[i+1])
            i--;
        if(i >= 0) {
            int j = n-1;
            while(i < j && nums[j] <= nums[i])
                j--;
            swap(nums[i],nums[j]);
        }
        reverse(nums.begin()+i+1,nums.end());
    }
};

int main() {
    vector <int> v = {1,2,3};
    nextPermutaion(v);
    for(auto i : v) {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}