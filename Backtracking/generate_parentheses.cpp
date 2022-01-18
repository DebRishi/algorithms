#include <iostream>
#include <vector>
using namespace std;

void helper(vector <string> & ans,string str,int n,int open,int close) {
    if(str.length() == 2*n) {
        ans.push_back(str);
        return;
    }
    if(open < n) {
        helper(ans,str+'(',n,open+1,close);
    }
    if(close < open) {
        helper(ans,str+')',n,open,close+1);
    }
}

vector <string> generateParentheses(int n) {
    vector <string> ans;
    helper(ans,"",n,0,0);
    return ans;
}

int main() {
    for(auto i : generateParentheses(3)) {
        cout<<i<<endl;
    }
    return 0;
}