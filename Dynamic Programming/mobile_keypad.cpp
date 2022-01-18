#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
	
    vector<vector<vector<int>>> memo;
	
	int solve(int i,int j,int n) {
	    if(i < 0 || j < 0 || i == 4 || j == 3 || (i == 3 && (j == 0 || j == 2)))
	        return 0;
	    if(n == 1)
	        return 1;
	    if(memo[i][j][n] != -1)
	        return memo[i][j][n];
	    return memo[i][j][n] =
	        solve(i-1,j,n-1) +
	        solve(i,j-1,n-1) +
	        solve(i+1,j,n-1) +
	        solve(i,j+1,n-1) +
	        solve(i,j,n-1);
	}
	
	int getCount(int n) {
	    int ans = 0;
	    memo = vector<vector<vector<int>>>(4,vector<vector<int>>(3,vector<int>(n+1,-1)));
	    for(int i = 0 ; i < 4 ; i++) {
	        for(int j = 0 ; j < 3 ; j++) {
	            ans += solve(i,j,n);
	        }
	    }
	    return ans;
	}
};

int main() {
    Solution s;
    cout<<s.getCount(10);
    return 0;
}