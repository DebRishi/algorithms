#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<int> primes(n+1,1);
        for(int i = 2 ; i*i <= n ; i++) {
            if(primes[i]) {
                for(int j = i*i ; j <= n ; j += i)
                    primes[j] = 0;
            }
        }
        int ans = 0;
        for(int i = 2 ; i <= n ; i++) {
            if(primes[i]) {
                cout<<i<<" ";
                ans++;
            }
        }
        cout<<endl;
        return ans;
    }
};

// BETTER
// class Solution {
// public:
//     int countPrimes(int n) {
//         vector<int> primes(n,1);
//         for(int i = 2 ; i <= n/2 ; i++) {
//             if(primes[i]) {
//                 for(int j = 2 ; i*j < n ; j++)
//                     primes[i*j] = 0;
//             }
//         }
//         int ans = 0;
//         for(int i = 2 ; i < n ; i++) 
//             if(primes[i])
//                 ans++;
//         return ans;
//     }
// };

// BRUTE
// class Solution {
// public:
//     bool isPrime(int n) {
//         for(int i = 2 ; i <= n/2 ; i++) {
//             if(n%i == 0)
//                 return false;
//         }
//         return true;
//     }
    
//     void countPrimes(int n) {
//         for(int i = 2 ; i < n ; i++) 
//             if(isPrime(i))
//                 cout<<i<<" ";
//     }
// };

int main() {
    Solution s;
    cout<<s.countPrimes(50);
    return 0;
}