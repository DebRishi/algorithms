#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    vector<vector<string>> ans;
    
    bool isPalindrome(string str,int start,int end) {
        while(start <= end) {
            if(str[start] != str[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    
    void helper(string str,vector<string> path,int index = 0) {
        if(index == str.length()) {
            ans.push_back(path);
            return;
        }
        for(int i = index ; i < str.length() ; i++) {
            if(isPalindrome(str,index,i)) {
                path.push_back(str.substr(index,i+1-index));
                helper(str,path,i+1);
                path.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string str) {
        vector<string> path;
        ans = vector<vector<string>>();
        helper(str,path);
        return ans;
    }
};

int main() {
    string str = "aab";
    Solution s;
    for(auto i : s.partition(str)) {
        for(auto j : i)
            cout<<j<<",";
        cout<<endl;
    }
}