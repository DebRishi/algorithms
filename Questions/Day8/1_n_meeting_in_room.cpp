#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
    
    static bool compare(vector<int> & a,vector<int> & b) {
        for(int i = 2 ; i >= 0 ; i--) {
            if(a[i] < b[i]) {
                return true;
            }
            if(a[i] > b[i]) {
                return false;
            }
        }
        return true;
    }
    
    int maxMeetings(int start[], int finish[], int n) {
        vector<vector<int>> act;
        for(int i = 0 ; i < n ; i++) {
            act.push_back({i+1,start[i],finish[i]});
        }
        sort(act.begin(),act.end(),compare);
        vector<vector<int>> ans;
        int end = -1;
        for(auto a : act) {
            if(a[1] > end) {
                ans.push_back(a);
                end = a[2];
            }
        }
        return ans.size();
    }
};

int main() {
    return 0;
}