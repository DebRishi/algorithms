#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int maxLeft = 0;
        int maxRight = 0;
        int ans = 0;
        while(l < r) {
            if(height[l] <= height[r]) {
                if(height[l] >= maxLeft) 
                    maxLeft = height[l];
                else
                    ans += maxLeft-height[l];
                l++;
            }
            else {
                if(height[r] >= maxRight) 
                    maxRight = height[r];
                else
                    ans += maxRight-height[r];
                r--;
            }
        }
        return ans;
    }
};

// BRUTE FORCE -> prefixMax and suffixMax
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
        
//         int maxLR[n];
//         int maxInt = -1;
//         for(int i = 0 ; i < n ; i++) {
//             maxInt = max(maxInt,height[i]);
//             maxLR[i] = maxInt;
//         }
        
//         int maxRL[n];
//         maxInt = -1;
//         for(int i = n-1 ; i >= 0 ; i--) {
//             maxInt = max(maxInt,height[i]);
//             maxRL[i] = maxInt;
//         }
        
//         int ans = 0;
//         for(int i = 0 ; i < n ; i++) {
//             ans += min(maxLR[i],maxRL[i]) - height[i];
//         }
        
//         return ans;
//     }
// };

int main() {
    return 0;
}