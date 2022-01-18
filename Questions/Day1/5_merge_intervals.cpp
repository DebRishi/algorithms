#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> & intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        vector<int> tempInterval = intervals[0];
        for(auto it : intervals) {
            if(it[0] <= tempInterval[1]) {
                tempInterval[1] = max(tempInterval[1],it[1]);
            }
            else {
                ans.push_back(tempInterval);
                tempInterval = it;
            }
        }
        ans.push_back(tempInterval);
        return ans;
    }
};

// class Solution {
// public:
    
//     static bool compare(vector<int> p1, vector<int> p2) {
//         return p1[0] < p2[0] || (p1[0] == p2[0] && p1[1] < p2[1]);
//     }
    
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         sort(intervals.begin(),intervals.end(),compare);
//         vector<vector<int>> ans;
//         vector<int> temp = {intervals[0][0],intervals[0][1]};
//         for(int i = 1 ; i < intervals.size() ; i++) {
//             if(intervals[i][0] <= temp[1]) {
//                 temp[1] = max(temp[1],intervals[i][1]);
//             }
//             else {
//                 ans.push_back(temp);
//                 temp[0] = intervals[i][0];
//                 temp[1] = intervals[i][1];
//             }
//         }
//         ans.push_back(temp);
//         return ans;
//     }
// };

int main() {
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    Solution s;
    for(auto i : s.merge(intervals)) {
        cout<<i[0]<<" "<<i[1]<<endl;
    }
    return 0;
}