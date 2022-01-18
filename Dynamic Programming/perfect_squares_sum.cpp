#include<iostream>
#include<vector>
using namespace std;

int perfectSquareSum(int n) {
    vector<int> dp(n+1,0);
    for(int i = 1 ; i <= n ; i++) {
        int min_steps = i;
        for(int j = 1 ; j*j <= i ; j++) {
            min_steps = min(min_steps,1+dp[i-j*j]);
        }
        dp[i] = min_steps;
    }
    return dp[n];
}

int main() {
    cout<<perfectSquareSum(56)<<endl;
    return 0;
}