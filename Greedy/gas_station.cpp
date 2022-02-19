#include<iostream>
#include<vector>
using namespace std;

// O(N) : LEETCODE 134 - Gas Station
class Solution {
public:
    int canCompleteCircuit(vector<int>& fuel,vector<int>& cost) {
        int n = fuel.size();
        int start = 0;
        int total = 0;
        int prev = 0;
        for(int i = 0 ; i < n ; i++) {
            total += fuel[i] - cost[i];
            if(total < 0) {
                prev += total;
                total = 0;
                start = i + 1;
            }
        }
        if(prev + total < 0)
            return -1;
        else
            return start;
    }
};

// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& fuel,vector<int>& cost) {
//         int n = fuel.size();
//         int fuelSum = 0;
//         int costSum = 0;
//         for(int i = 0 ; i < n ; i++) {
//             fuelSum += fuel[i];
//             costSum += cost[i];
//         }
//         if(fuelSum < costSum)
//             return -1;
        
//         int tot = 0;
//         int ans = 0;
//         for(int i = 0 ; i < n ; i++) {
//             tot += fuel[i] - cost[i];
//             if(tot < 0) {
//                 tot = 0;
//                 ans = i+1;
//             }
//         }
//         return ans;
//     }
// };

// O(N^2)
// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& fuel,vector<int>& cost) {
//         int size = fuel.size();
//         for(int i = 0 ; i < size ; i++) {
//             if(fuel[i]-cost[i] >= 0) {
//                 int step = size;
//                 int flag = true;
//                 int curr = i;
//                 int currFuel = fuel[i];
//                 while(step-- > 0) {
//                     currFuel -= cost[curr];
//                     if(currFuel < 0) {
//                         flag = false;
//                         break;
//                     }
//                     curr = (curr+1)%size;
//                     currFuel += fuel[curr];
//                 }
//                 if(flag)
//                     return i;
//             }
//         }
//         return -1;
//     }
// };

int main() {
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    Solution s;
    cout<<s.canCompleteCircuit(gas,cost);
    return 0;
}