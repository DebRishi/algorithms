#include<iostream>
using namespace std;

class Solution {
public:
    double myPow(double x,long long n) {
        if(n == 0) return 1;
        if(n < 0) {
            n = -n;
            x = 1/x;
        }
        return n%2 == 0 ? myPow(x*x,n/2) : x*myPow(x,n-1); 
    }
};

int main() {
    Solution s;
    cout<<fixed<<s.myPow(2.10000,3)<<endl;
    return 0;
}