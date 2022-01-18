#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> memo;
    
    bool helper(string str,string pat,int s = 0,int p = 0) {
        int strlen = str.length();
        int patlen = pat.length();
        
        if(s == strlen && p == patlen)
            return true;
        if(p == patlen)
            return false;
        if(memo[s][p] != -1)
            return memo[s][p];
        
        bool match = s < strlen && (str[s] == pat[p] || pat[p] == '.');
        
        if(p+1 < patlen && pat[p+1] == '*') 
            return memo[s][p] = (match && helper(str,pat,s+1,p)) || helper(str,pat,s,p+2);
        else if(match)
            return memo[s][p] = helper(str,pat,s+1,p+1);
        else 
            return memo[s][p] = false;
    }
    
    bool isMatch(string str,string pat) {
        memo = vector<vector<int>> (str.length()+1,vector<int> (pat.length()+1,-1));
        return helper(str,pat);
    }
};

int main() {
    string str = "mississippi";
    string pat = "mis*is*ip*.";
    Solution s;
    cout<<s.isMatch(str,pat);
    return 0;
}