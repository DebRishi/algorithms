#include<iostream>
#include<vector>
#include<stack>
#include<unordered_set>
using namespace std;

class Solution {
  public:

    unordered_set<string> set;
    vector<string> ans;
    
    void solve(string str,int removals) {
        
        // OPTIMIZATION
        if(set.find(str) != set.end())
            return;
        set.insert(str);
        
        if(removals == 0) {
            int count = countRemovals(str);
            if(count == 0)
                ans.push_back(str);
            return;
        }
        
        for(int i = 0 ; i < str.size() ; i++) {
            string lstr = str.substr(0,i);
            string rstr = str.substr(i+1);
            solve(lstr+rstr,removals-1);
        }
    }
    
    int countRemovals(string str) {
        stack<char> stack;
        for(char c : str) {
            if(c == '(')
                stack.push('(');
            else if(c == ')') {
                if(stack.empty() || stack.top() == ')')
                    stack.push(')');
                else
                    stack.pop();
            }
        }
        return stack.size();
    }
    
    vector<string> removeInvalidParentheses(string str) {
        int count = countRemovals(str);
        solve(str,count);
        return ans;
    }
};

int main() {
    string str = "(a)())()";
    Solution s;
    for(auto i : s.removeInvalidParentheses(str))
        cout<<i<<endl;
    return 0;
}