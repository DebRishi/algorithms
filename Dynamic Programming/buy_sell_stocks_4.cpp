#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// MEMORIZATION
class Solution {
public:
    vector<vector<int>> memo;
    
    int solve(vector<int>& prices,int trans,int pos = 0) {
        int n = prices.size();
        if(pos == n || trans == 0)
            return 0;
        if(memo[pos][trans] != -1)
            return memo[pos][trans];
        int ans = 0;
        for(int i = pos+1 ; i < n ; i++)
            ans = max(ans,prices[i]-prices[pos]+solve(prices,trans-1,i+1));
        ans = max(ans,solve(prices,trans,pos+1));
        return memo[pos][trans] = ans;
    }
    
    int maxProfit(int k,vector<int>& prices) {
        int n = prices.size();
        memo = vector<vector<int>>(n,vector<int>(k+1,-1));
        return solve(prices,k);
    }
};

// RECURSION
// class Solution {
// public:
//     int solve(vector<int>& prices,int trans,int pos = 0) {
//         int n = prices.size();
//         if(pos == n || trans == 0)
//             return 0;
//         int ans = 0;
//         for(int i = pos+1 ; i < n ; i++)
//             ans = max(ans,prices[i]-prices[pos]+solve(prices,trans-1,i+1));
//         ans = max(ans,solve(prices,trans,pos+1));
//         return ans;
//     }
    
//     int maxProfit(int k,vector<int>& prices) {
//         return solve(prices,k);
//     }
// };

int main() {
    return 0;
}