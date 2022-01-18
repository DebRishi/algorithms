#include<iostream>
#include<vector>
#include<utility>
using namespace std;

// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int bit = 0;
//         for(int i = 0 ; i < nums.size() ; i++)
//             bit = bit ^ i ^ nums[i];
//         return bit ^ nums.size();
//     }
// };

pair<int,int> missingAndReapeat(vector<int> num) {
    int n = num.size();
    vector<int> count(n,0);
    for(int i : num) {
        count[i-1]++;
    }
    int repeat;
    int missing;
    for(int i = 0 ; i < n ; i++) {
        if(count[i] == 0) {
            missing = i+1;
        }
        else if(count[i] == 2) {
            repeat = i+1;
        }
    }
    return {missing,repeat};
}

int main() {
    vector<int> num = {4, 3, 6, 2, 1, 1};
    pair<int,int> p = missingAndReapeat(num);
    cout<<p.first<<" "<<p.second<<endl;
    return 0;
}