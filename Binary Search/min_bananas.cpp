#include<iostream>
#include<vector>
using namespace std;

// LEETCODE 875 - Koko Eating Bananas
class Solution {
  public:
    
    bool isPossible(vector<int>& piles,int hours,int maxBananas) {
        int count = 0;
        for(int bananas : piles) {
            count += bananas / maxBananas;
            if(bananas % maxBananas)
                count++;
            if(count > hours)
                return false;
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles,int hours) {
        int maxBananas = piles[0];
        for(int bananas : piles)
            maxBananas = max(maxBananas,bananas);
        int low = 1;
        int hii = maxBananas;
        while(low < hii) {
            int mid = (hii + low) >> 1;
            if(isPossible(piles,hours,mid))
                hii = mid;
            else
                low = mid+1;
        }
        return hii;
    }
};

int main() {
    vector<int> piles = {3,6,7,11};
    int hours = 8;
    
    Solution s;
    cout<<s.minEatingSpeed(piles,hours);
    return 0;
}