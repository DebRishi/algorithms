#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num,int k) {
        stack<char> stack;
        for(char c : num) {
            while(!stack.empty() && stack.top() > c && k > 0) {
                stack.pop();
                k--;
            }
            stack.push(c);
        }
        
        while(!stack.empty() && k > 0) {
            stack.pop();
            k--;
        }
        
        string ans = "";
        while(!stack.empty()) {
            ans += stack.top();
            stack.pop();
        }
        
        reverse(ans.begin(),ans.end());
        for(int i = 0 ; i < ans.size() ; i++) {
            if(ans[i] != '0') {
                ans = ans.substr(i);
                break;
            }
        }
        
        if(ans == "" || ans[0] == '0')
            return "0";
        else
            return ans;
    }
};

int main() {
    string num = "1432219";
    int k = 3;
    Solution s;
    cout<<s.removeKdigits(num,k);
    return 0;
}