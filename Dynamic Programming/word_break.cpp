#include<iostream>
#include<vector>
#include<set>
using namespace std;

// MEMORIZATION DP
class Solution {
    public:

    set<string> dict;
    vector<int> memo;

    bool helper(string str,int pos = 0) {
        if(pos == str.length()) {
            return true;
        }
        if(memo[pos] != -1) {
            return memo[pos];
        }
        for(int i = pos ; i < str.length() ; i++) {
            string substr = str.substr(pos,i-pos+1);
            if(dict.find(substr) != dict.end() && helper(str,i+1)) {
                return memo[pos] = true;
            }
        }
        return memo[pos] = false;
    }

    bool wordBreak(string str,vector<string> wordDict) {
        memo = vector<int>(str.length(),-1);
        dict = set<string>();
        for(auto s : wordDict) dict.insert(s);
        return helper(str);
    }
};

// RECURSIVE
// class Solution {
//     public:

//     set<string> dict;

//     bool helper(string str,int pos = 0) {
//         if(pos == str.length()) {
//             return true;
//         }
//         for(int i = pos ; i < str.length() ; i++) {
//             string substr = str.substr(pos,i-pos+1);
//             if(dict.find(substr) != dict.end() && helper(str,i+1)) {
//                 return true;
//             }
//         }
//         return false;
//     }

//     bool wordBreak(string str,vector<string> wordDict) {
//         dict = set<string>();
//         for(auto s : wordDict) dict.insert(s);
//         return helper(str);
//     }
// };

int main() {
    string str = "applepenapple";
    vector<string> wordDict = {"apple","pen"};
    Solution sol;
    cout<<sol.wordBreak(str,wordDict)<<endl;
    return 0;
}