#include<iostream>
#include<vector>
using namespace std;

int upperBound(vector<int> arr,int k) {
    int i = 0;
    int j = arr.size();
    while(i < j) {
        int mid = i + (j-i)/2;
        if(arr[mid] <= k)
            i = mid+1;
        else
            j = mid;
    }
    return i;
}

int main() {
    vector<int> arr = {1,3,5,5,5,6,6};
    cout<<upperBound(arr,5);
}