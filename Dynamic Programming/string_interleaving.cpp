#include<iostream>
#include<vector>
using namespace std;

// MEMORIZATION DP
class Solution {
public:
    
    vector<vector<int>> memo;
    
    bool helper(string s1,string s2,string s3,int p1 = 0,int p2 = 0,int p3 = 0) {
        if(p3 == s3.length() && p1 == s1.length() && p2 == s2.length()) {
            return true;
        }
        if(p3 == s3.length()) {
            return false;
        }
        if(memo[p1][p2] != -1) {
            return memo[p1][p2];
        }
        bool ans = false;
        if(s1[p1] == s3[p3]) {
            ans = ans || helper(s1,s2,s3,p1+1,p2,p3+1);
        }
        if(s2[p2] == s3[p3]) {
            ans = ans || helper(s1,s2,s3,p1,p2+1,p3+1);
        }
        return memo[p1][p2] = ans;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        memo = vector<vector<int>>(s1.length()+1,vector<int>(s2.length()+1,-1));
        return helper(s1,s2,s3);
    }
};

// RECURSION
// class Solution {
// public:
    
//     bool helper(string s1,string s2,string s3,int p1 = 0,int p2 = 0,int p3 = 0) {
//         if(p3 == s3.length() && p1 == s1.length() && p2 == s2.length()) {
//             return true;
//         }
//         if(p3 == s3.length()) {
//             return false;
//         }
//         bool ans = false;
//         if(s1[p1] == s3[p3]) {
//             ans = ans || helper(s1,s2,s3,p1+1,p2,p3+1);
//         }
//         if(s2[p2] == s3[p3]) {
//             ans = ans || helper(s1,s2,s3,p1,p2+1,p3+1);
//         }
//         return ans;
//     }
    
//     bool isInterleave(string s1, string s2, string s3) {
//         return helper(s1,s2,s3);
//     }
// };

int main() {
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    Solution s;
    cout<<s.isInterleave(s1,s2,s3)<<endl;
    return 0;
}