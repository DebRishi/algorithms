#include<iostream>
#include<vector>
using namespace std;
#define maxCoins 1e9

// DP SOLUTION
int countCoins(vector<int> & coins,int amount) {
    int dp[coins.size()+1][amount+1];
    for(int i = 0 ; i <= coins.size() ; i++) dp[i][0] = 0;
    for(int j = 1 ; j <= amount; j++) dp[0][j] = maxCoins;
    for(int i = 1 ; i <= coins.size() ; i++) {
        for(int j = 1 ; j <= amount ; j++) {
            int exclude = dp[i-1][j];
            int include = j-coins[i-1] < 0 ? maxCoins : dp[i][j-coins[i-1]];
            dp[i][j] = min(exclude,1+include);
        }
    }
    if(dp[coins.size()][amount] == maxCoins) {
        cout<<"Amount cannot be made up with this set of coins"<<endl;
    }
    return dp[coins.size()][amount];
}


// RECURSIVE SOLUTION
// int countCoins(vector<int> & coins,int amount,int index = 0) {
//     if(index >= coins.size() || amount < 0) {
//         return 1e9;
//     }
//     if(amount == 0) {
//         return 0;
//     }
//     return min(1+countCoins(coins,amount-coins[index],index),countCoins(coins,amount,index+1));
// }

int main() {
    vector<int> coins = {2,5,3,6};
    int amount = 10;
    cout<<countCoins(coins,amount)<<endl;
    return 0;
}