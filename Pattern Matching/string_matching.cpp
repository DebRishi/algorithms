#include<iostream>
using namespace std;


// BRUTE FORCE
class Solution {
public:
    int stringMatching(string str, string pat) {
        int strlen = str.length();
        int patlen = pat.length();
        if(patlen == 0)
            return 0;
        for(int s = 0 ; s <= strlen-patlen ; s++) {
            int p = 0;
            while(p < patlen && pat[p] == str[s+p])
                p++;
            if(p == patlen)
                return s;
        }
        return -1;
    }
};

int main() {
    return 0;
}