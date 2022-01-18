#include<iostream>
#include<vector>
using namespace std;

// MEMOIZATION
class EggDropping {
    public:
    vector<vector<int>> memo;

    int solve(int floors,int eggs) {
        if(floors == 0 || floors == 1)
            return floors;
        if(eggs == 1)
            return floors;
        if(memo[floors][eggs] != -1)
            return memo[floors][eggs];
        int ans = INT_MAX;
        for(int i = 1 ; i <= floors ; i++)
            ans = min(ans,max(solve(i-1,eggs-1),solve(floors-i,eggs)));
        return memo[floors][eggs] = ans+1;
    }

    int eggDropping(int floors,int eggs) {
        memo = vector<vector<int>>(floors+1,vector<int>(eggs+1,-1));
        return solve(floors,eggs);
    }
};

int main() {
    EggDropping e;
    cout<<e.eggDropping(14,3);
    return 0;
}