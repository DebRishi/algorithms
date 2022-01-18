#include<iostream>
#include<vector>
using namespace std;

int maxSumSubsequence(vector<int> arr) {
    int maxInt = arr[0];
    for(int i : arr) {
        maxInt = max(maxInt,i);
    }
    if(maxInt <= 0) {
        return maxInt;
    }
    int sum = 0;
    for(int i : arr) {
        if(i > 0) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSumSubsequence(v)<<endl;
    return 0;
}