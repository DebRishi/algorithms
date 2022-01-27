#include<iostream>
#include<vector>
using namespace std;

// LEETCODE 1011 - Capacity To Ship Packages Within D Days
class Solution {
public:
    int countDays(vector<int>& weights,int limit) {
        int day = 1;
        int sum = 0;
        for(int weight : weights) {
            sum += weight;
            if(sum > limit) {
                day++;
                sum = weight;
            }
        }
        return day;
    }
    
    int shipWithinDays(vector<int>& weights,int days) {
        int maxWeight = 0;
        int sumWeight = 0;
        for(int weight : weights) {
            sumWeight += weight;
            maxWeight = max(maxWeight,weight);
        }
        
        int low = maxWeight;
        int hii = sumWeight;
        while(low < hii) {
            int mid = (low + hii) >> 1;
            if(countDays(weights,mid) <= days)
                hii = mid;
            else
                low = mid+1;
        }
        return hii;
    }
};

int main() {
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;
    
    Solution s;
    cout<<s.shipWithinDays(weights,days);
    
    return 0;
}