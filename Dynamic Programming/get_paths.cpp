#include <iostream>
#include <vector>
using namespace std;

int getPaths(int i,int j,int m,int n,vector <vector <int>> & dp) {
    if(i == m-1 && j == n-1) {
        return 1;
    }
    if(i > m-1 || j > n-1) {
        return 0;
    }
    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    dp[i][j] = getPaths(i+1,j,m,n,dp) + getPaths(i,j+1,m,n,dp);
    return dp[i][j];
}

int uniquePaths(int m, int n) {
    vector <vector <int>> dp(m,vector <int> (n,-1));
    return getPaths(0,0,m,n,dp);
}

int main() {
    cout<<uniquePaths(3,7);
    return 0;
}