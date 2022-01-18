#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
	int total;
	vector<vector<int>> memo;
	
	int solve(int arr[],int n,int i = 0,int sum = 0) {
	    if(i == n)
	        return abs(total - 2*sum);
	    if(memo[i][sum] != -1)
	        return memo[i][sum];
	    return memo[i][sum] = min(solve(arr,n,i+1,sum),solve(arr,n,i+1,sum+arr[i]));
	}
	
	int minDifference(int arr[],int n) {
	    total = 0;
	    for(int i = 0 ; i < n ; i++)
	        total += arr[i];
	    memo = vector<vector<int>>(n,vector<int>(total+1,-1));
	    return solve(arr,n);
	}
};