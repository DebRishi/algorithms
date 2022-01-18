#include<iostream>
#include<map>
using namespace std;

int maxLen(int A[], int n) {
    map<int,int> hash;
    int ans = 0;
    int sum = 0;
    for(int i = 0 ; i < n ; i++) {
        sum += A[i];
        if(sum == 0) 
            ans = i+1;
        else{
            if(hash.find(sum) != hash.end()) 
                ans = max(ans,i-hash[sum]);
            else 
                hash[sum] = i;
        }
    }
    return ans;
}

// int maxLen(int A[], int n) {
//     map<int,int> hash;
//     hash[0] = -1;
//     int ans = 0;
//     int sum = 0;
//     for(int i = 0 ; i < n ; i++) {
//         sum += A[i];
//         if(hash.find(sum) != hash.end()) 
//             ans = max(ans,i-hash[sum]);
//         else 
//             hash[sum] = i;
//     }
//     return ans;
// }

int main() {
    int n = 8;
    int arr[] = {15,-2,2,-8,1,7,10,23};
    cout<<maxLen(arr,n)<<endl;
    return 0;
}