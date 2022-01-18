#include <iostream>

using namespace std;

bool isPossible(int * arr,int n,int m,int cur_min) {
    int req = 1;
    int sum = 0;
    for(int i = 0 ; i < n ; i++) {
        if(sum + arr[i] > cur_min) {
            req++;
            sum = arr[i];
        }
        else {
            sum += arr[i];
        }
    }
    if(req <= m) {
        return true;
    }
    else {
        return false;
    }
}

int findPages(int * arr,int n,int m) {
    if(m > n) {
        return -1;
    }

    int sum = 0;
    int max = INT_MIN;
    for(int i = 0 ; i < n ; i++) {
        sum += arr[i];
        max = std::max(max,arr[i]);
    }

    int res = -1;
    int low = max;
    int high = sum;
    while(low <= high) {
        int mid = low + (high -low)/2;
        if(isPossible(arr,n,m,mid)) {
            res = mid;
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }
    return res;
}

int main() {
    int arr[] = {12, 34, 67, 90};
    cout<<findPages(arr,4,2);
    return 0;
}