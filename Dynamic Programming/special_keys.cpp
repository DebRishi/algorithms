#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    vector<long> memo;
    
    long solve(int n) {
        if(n == 0)
            return 0;
        if(memo[n] != -1)
            return memo[n];
        long ans = 1 + solve(n-1);
        for(int i = 1 ; i < n ; i++)
            if(n-2-i >= 0)
                ans = max(ans,(i+1)*solve(n-2-i));
        return memo[n] = ans;
    }
    
    long optimalKeys(int n) {
        memo = vector<long>(n+1,-1);
        return solve(n);
    }
};

int main() {
    Solution s;
    cout<<s.optimalKeys(10);
    return 0;
}