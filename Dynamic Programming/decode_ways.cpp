#include<iostream>
#include<vector>
#include<set>
using namespace std;

// MEMORIZATION
class Solution {
    public:

    vector<int> memo;
    set<string> code;

    Solution() {
        for(int i = 1 ; i <= 26 ; i++) code.insert(to_string(i));
    }

    int helper(string str,int pos = 0) {
        int n = str.length();
        if(pos == n) return 1;
        if(memo[pos] != -1) return memo[pos];
        int ans = 0;
        if(code.find(str.substr(pos,1)) != code.end()) {
            ans += helper(str,pos+1);
        }
        if(pos+1 < n && code.find(str.substr(pos,2)) != code.end()) {
            ans += helper(str,pos+2);
        }
        return memo[pos] = ans;
    }

    int decodeWays(string str) {
        memo = vector<int> (str.length()+1,-1);
        return helper(str);
    }
};

// RECURSIVE
// class Solution {
//     public:
//     set<string> code;

//     int helper(string str,int pos = 0) {
//         int n = str.length();
//         if(pos == n) {
//             return 1;
//         }
//         int ans = 0;
//         if(code.find(str.substr(pos,1)) != code.end()) {
//             ans += helper(str,pos+1);
//         }
//         if(pos+1 < n && code.find(str.substr(pos,2)) != code.end()) {
//             ans += helper(str,pos+2);
//         }
//         return ans;
//     }

//     int decodeWays(string str) {
//         for(int i = 1 ; i <= 26 ; i++) code.insert(to_string(i));
//         return helper(str);
//     }
// };

int main() {
    string str = "226";
    Solution s;
    cout<<s.decodeWays(str)<<endl;
    return 0;
}