#include<iostream>
#include<vector>
using namespace std;

// DP SOLUTION
int change(vector<int> & coins,int amount) {
    int dp[coins.size()+1][amount+1];
    for(int i = 0 ; i <= coins.size() ; i++) dp[i][0] = 1;
    for(int j = 1 ; j <= amount ; j++) dp[0][j] = 0;
    for(int i = 1 ; i <= coins.size() ; i++) {
        for(int j = 1 ; j <= amount ; j++) {
            int exclude = dp[i-1][j];
            int include = j-coins[i-1] < 0 ? 0 : dp[i][j-coins[i-1]];
            dp[i][j] = include + exclude;
        }
    }
    return dp[coins.size()][amount];
}

// RECURSIVE SOLUTION
// int change(vector<int> & coins,int amount,int index = 0) {
//     if(index >= coins.size() || amount < 0) {
//         return 0;
//     }
//     if(amount == 0) {
//         return 1;
//     }
//     int include = change(coins,amount-coins[index],index);
//     int exclude = change(coins,amount,index+1);
//     return include + exclude;
// }

int main() {
    vector<int> coins = {1,2,5};
    int amount = 5;
    cout<<change(coins,amount)<<endl;
    return 0;
}