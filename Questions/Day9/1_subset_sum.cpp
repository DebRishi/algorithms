#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> ans;
    
    void helper(vector<int>& arr,int i = 0,int sum = 0) {
        if(i == arr.size()) {
            ans.push_back(sum);
            return;
        }
        helper(arr,i+1,sum);
        helper(arr,i+1,sum+arr[i]);
    }
    
    vector<int> subsetSums(vector<int> arr, int N) {
        helper(arr);
        return ans;
    }
};

int main() {
    return 0;
}