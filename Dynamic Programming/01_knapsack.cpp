#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
    void knapsack(int maxWeight,vector<string>& names,vector<int>& weight,vector<int>& values) {
        int n = names.size();
        int dp[n+1][maxWeight+1];
        for(int i = 0 ; i <= n ; i++) {
            for(int j = 0 ; j <= maxWeight ; j++) {
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
                else if(weight[i-1] > j)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = max(dp[i-1][j],values[i-1]+dp[i-1][j-weight[i-1]]);
            }
        }
        vector<string> items;
        int res = dp[n][maxWeight];
        for(int i = n , j = maxWeight ; i > 0 && res > 0 ; i--) {
            if(res == dp[i-1][j])
                continue;
            else {
                items.push_back(names[i-1]);
                j = j - weight[i-1];
                res = res - values[i-1];
            }
        }
        cout<<"RESULT -> "<<dp[n][maxWeight]<<endl;
        cout<<"ITEMS -> ";
        for(auto i : items)
            cout<<i<<",";
        cout<<endl;
    }
};

// class Solution {
//     public:
//     vector<vector<int>> memo;

//     int solve(int maxWeight,vector<int>& weight,vector<int>& values,int i = 0) {
//         int n = weight.size();
//         if(i == n)
//             return 0;
//         if(memo[i][maxWeight] != -1)
//             return memo[i][maxWeight];
//         if(weight[i] > maxWeight)
//             return solve(maxWeight,weight,values,i+1);
//         return memo[i][maxWeight] = max(solve(maxWeight,weight,values,i+1),values[i]+solve(maxWeight-weight[i],weight,values,i+1));
//     }

//     void knapsack(int maxWeight,vector<string>& names,vector<int>& weight,vector<int>& values) {
//         int n = weight.size();
//         memo = vector<vector<int>>(n+1,vector<int>(maxWeight+1,-1));
//         cout<<solve(maxWeight,weight,values)<<endl;
//     }
// };

int main() {
    vector<string> names = {"map","compass","water","sandwich","glucose","tin","banana","apple","cheese","beer","suntan-cream","camera","t-shirt","trousers","umbrella","waterproof-trousers","waterproof-overclothes","note-case","sunglasses","towel","socks","book"};
    vector<int> weight = {9,13,153,50,15,68,27,39,23,52,11,32,24,48,73,42,43,22,7,18,4,30};
    vector<int> values = {150,35,200,160,60,45,60,40,30,10,70,30,15,10,40,70,75,80,20,12,50,10};
    int maxWeight = 400;
    Solution s;
    s.knapsack(maxWeight,names,weight,values);
    return 0;
}