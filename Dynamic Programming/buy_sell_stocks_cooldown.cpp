#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// STATE MACHINE DP
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int noStock[n];
        int inHand[n];
        int Sold[n];
        
        noStock[0] = 0;
        inHand[0] = -prices[0];
        Sold[0] = 0;
        
        for(int i = 1 ; i < n ; i++) {
            noStock[i] = max(noStock[i-1],Sold[i-1]);
            inHand[i] = max(inHand[i-1],noStock[i-1] - prices[i]);
            Sold[i] = inHand[i-1] + prices[i];
        }
        
        return max({noStock[n-1],inHand[n-1],Sold[n-1]});
    }
};

// MEMORIZATION
// class Solution {
// public:
//     vector<int> memo;
    
//     int solve(vector<int>& prices,int pos = 0) {
//         int n = prices.size();
//         if(pos >= n)
//             return 0;
//         if(memo[pos] != -1)
//             return memo[pos];
//         int ans = 0;
//         int cost = prices[pos];
//         for(int i = pos+1 ; i < n ; i++)
//             ans = max(ans,prices[i]-cost+solve(prices,i+2));
//         ans = max(ans,solve(prices,pos+1));
//         return memo[pos] = ans;
//     }
    
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         memo = vector<int>(n,-1);
//         return solve(prices);
//     }
// };

// RECURSIVE
// class Solution {
// public:
//     int solve(vector<int>& prices,int pos = 0) {
//         int n = prices.size();
//         if(pos >= n)
//             return 0;
//         int ans = 0;
//         int cost = prices[pos];
//         for(int i = pos+1 ; i < n ; i++)
//             ans = max(ans,prices[i]-cost+solve(prices,i+2));
//         ans = max(ans,solve(prices,pos+1));
//         return ans;
//     }

//     int maxProfit(vector<int>& prices) {
//         return solve(prices);
//     }
// };

int main() {
    vector<int> prices = {1,2,3,0,2};
    Solution s;
    cout<<s.maxProfit(prices);
    return 0;
}