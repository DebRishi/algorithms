#include<iostream>
#include<vector>
using namespace std;

int maxSumSubarray(vector<int> arr) {
    // KADANE'S ALGORITHM
    int sum = 0;
    int maxSum = arr[0];
    for(int i : arr) {
        sum += i;
        maxSum = max(maxSum,sum);
        sum = max(sum,0);
    }
    return maxSum;
}

int main() {
    vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSumSubarray(v)<<endl;
    return 0;
}