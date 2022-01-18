#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    
    vector<vector<int>> fourSum(vector<int> & num, int target) {
        vector <vector <int>> ans;
        int n = num.size();
        sort(num.begin(),num.end());
        for(int i = 0 ; i < n ; i++) {
            for(int j = i+1 ; j < n ; j++) {
                int diff = target - num[i] - num[j];
                int left = j+1;
                int right = n-1;
                while(left < right) {
                    int sum = num[left] + num[right];
                    if(sum < diff) {
                        left++;
                    }
                    else if(sum > diff) {
                        right--;
                    }
                    else {
                        vector <int> seq(4,0);
                        seq[0] = num[i];
                        seq[1] = num[j];
                        seq[2] = num[left];
                        seq[3] = num[right];
                        ans.push_back(seq);
                        
                        while(left < right && seq[2] == num[left]) {
                            left++;
                        }
                        while(left < right && seq[3] == num[right]) {
                            right--;
                        }
                    }
                }
                while(j < n-1 && num[j] == num[j+1]) {
                    j++;
                }
            }
            while(i < n-1 && num[i] == num[i+1]) {
                i++;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> num = {1,0,-1,0,-2,2};
    int target = 0;
    for(auto i : s.fourSum(num,target)) {
        for(auto j : i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}