#include<bits/stdc++.h>
using namespace std;

// EFFICIENT APPROACH - KMP ALGORITHM
class Solution {
public:
    vector<int> longestPrefixSuffix(string str) {
        int strlen = str.length();
        vector<int> lps(strlen,0);
        int j = 0;
        for(int i = 1 ; i < strlen ; i++) {
            while(j > 0 && str[i] != str[j])
                j = lps[j-1];
            if(str[i] == str[j])
                j++;
            lps[i] = j;
        }
        return lps;
    }
    
    int strStr(string str, string pat) {
        int strlen = str.length();
        int patlen = pat.length();
        if(patlen == 0)
            return 0;
        vector<int> lps = longestPrefixSuffix(pat);
        int i(0),j(0);
        while(i < strlen) {
            if(str[i] == pat[j]) {
                i++;
                j++;
                if(j == patlen)
                    return i-j;
            }
            else {
                if(j != 0)
                    j = lps[j-1];
                else
                    i++;
            }
        }
        return -1;
    }
};

// BRUTE FORCE
// class Solution {
// public:
//     int stringMatching(string str, string pat) {
//         int strlen = str.length();
//         int patlen = pat.length();
//         if(patlen == 0)
//             return 0;
//         for(int s = 0 ; s <= strlen-patlen ; s++) {
//             int p = 0;
//             while(p < patlen && pat[p] == str[s+p])
//                 p++;
//             if(p == patlen)
//                 return s;
//         }
//         return -1;
//     }
// };

int main() {
    return 0;
}