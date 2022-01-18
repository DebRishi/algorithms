#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int LR[n];
        int RL[n];
        
        int lmin = prices[0];
        LR[0] = 0;
        for(int i = 1 ; i < n ; i++) {
            lmin = min(lmin,prices[i]);
            LR[i] = max(LR[i-1],prices[i] - lmin);
        }
        
        int rmax = prices[n-1];
        RL[n-1] = 0;
        for(int i = n-2 ; i >= 0 ; i--) {
            rmax = max(rmax,prices[i]);
            RL[i] = max(RL[i+1],rmax - prices[i]);
        }
        
        int profit = 0;
        for(int i = 0 ; i < n ; i++)
            profit = max(profit,LR[i] + RL[i]);
        
        return profit;
    }
};

// MEMORIZATION
// class Solution {
// public:
//     vector<vector<int>> memo;
    
//     int solve(vector<int>& prices,int pos = 0,int trans = 0) {
//         int n = prices.size();
//         if(pos == n || trans == 2)
//             return 0;
//         if(memo[pos][trans] != -1)
//             return memo[pos][trans];
//         int ans = 0;
//         for(int i = pos+1 ; i < n ; i++)
//             ans = max(ans,prices[i] - prices[pos] + solve(prices,i+1,trans+1));
//         ans = max(ans,solve(prices,pos+1,trans));
//         return memo[pos][trans] = ans;
//     }
    
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         memo = vector<vector<int>>(n,vector<int>(2,-1));
//         return solve(prices);
//     }
// };

int main() {
    vector<int> prices = {3,3,5,0,0,3,1,4};
    Solution s;
    cout<<s.maxProfit(prices);
    return 0;
}