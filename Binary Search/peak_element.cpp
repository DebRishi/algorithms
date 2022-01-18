#include <iostream>
#include <vector>
using namespace std;

int findPeak(vector <int> arr,int low,int high) {
    int mid = low + (high-low)/2;
    if((mid == 0 || arr[mid-1] <= arr[mid]) && (mid == arr.size()-1 || arr[mid+1] <= arr[mid])) {
        return mid;
    }
    else if(mid > 0 || arr[mid-1] > arr[mid]) {
        return findPeak(arr,low,mid-1);
    }
    else {
        return findPeak(arr,mid+1,high);
    }
}

int main() {
    vector <int> v = {0,6,8,5,7,9};
    cout<<findPeak(v,0,5);
    return 0;
}