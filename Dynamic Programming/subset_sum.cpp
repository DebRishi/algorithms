#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution{   
public:
    vector<vector<int>> memo;
    
    bool solve(int arr[],int n,int sum,int i = 0) {
        if(sum == 0)
            return true;
        if(i == n || sum < 0)
            return false;
        if(memo[i][sum] != -1)
            return memo[i][sum];
        return memo[i][sum] = solve(arr,n,sum,i+1) || solve(arr,n,sum-arr[i],i+1);
    }
    
    bool isSubsetSum(int n,int arr[],int sum) {
        memo = vector<vector<int>>(n,vector<int>(sum+1,-1));
        return solve(arr,n,sum);
    }
};

int main() {
    int n = 6;
    int arr[] = {3,34,4,12,5,2};
    int sum = 9;
    Solution s;
    cout<<s.isSubsetSum(n,arr,sum);
}