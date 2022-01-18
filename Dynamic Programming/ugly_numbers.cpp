#include<iostream>
#include<algorithm>
using namespace std;

// DP SOLUTION
class Solution {
public:
    int nthUglyNumber(int n) {
        int ugly[n];
        ugly[0] = 1;
        int c2(0),c3(0),c5(0);
        for(int i = 1 ; i < n ; i++) {
            ugly[i] = min({2 * ugly[c2],3 * ugly[c3],5 * ugly[c5]});
            if(ugly[i] == 2 * ugly[c2])
                c2++;
            if(ugly[i] == 3 * ugly[c3])
                c3++;
            if(ugly[i] == 5 * ugly[c5])
                c5++;
        }
        return ugly[n-1];
    }
};

// BRUTE FORCE
// class Solution {
// public:
//     bool isUgly(int n) {
//         while(n > 1) {
//             if(n % 5 == 0)
//                 n = n/5;
//             else if(n % 3 == 0)
//                 n = n/3;
//             else if(n % 2 == 0)
//                 n = n/2;
//             else
//                 return false;
//         }
//         return true;
//     }
    
//     int nthUglyNumber(int n) {
//         int i = 1;
//         while(n) {
//             if(isUgly(i))
//                 n--;
//             i++;
//         }
//         return i-1;
//     }
// };

int main() {
    return 0;
}